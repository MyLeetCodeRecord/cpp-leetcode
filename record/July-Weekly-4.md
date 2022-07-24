#### Weekly 4

##### [第一次出现两次的字母](https://leetcode.cn/problems/first-letter-to-appear-twice/)

> `hash` `map`


##### [相等行列对](https://leetcode.cn/problems/equal-row-and-column-pairs/)

> `map`
> 
> 注意<i,j>是计次的, 不保证没有重复的行或者重复的列

```CPP
int equalPairs(vector<vector<int>>& grid) {
    int N = grid.size();
    unordered_map<string, int> rowMap;
    int cnt = 0;
    for(int i=0; i<N; i++){
        string row = "";
        for(int j=0; j<N; j++)
            row += (to_string(grid[i][j])+",");
        rowMap[row]++;
    }
    for(int j=0; j<N; j++){
        string col = "";
        for(int i=0; i<N; i++)
            col += (to_string(grid[i][j])+",");
        if(rowMap.find(col)!=rowMap.end())
            cnt += rowMap[col];
    }
    return cnt;
}
```

##### [设计食物评分系统](https://leetcode.cn/problems/design-a-food-rating-system/)

> `map` `set`
> 
> 周赛的时候用`priority_queue<Node*>`来做, 修改`Node->rating`时不能触发`priority_queue`重新排序...
> 
> 所以只能选择重新“倒”一遍, 于是卡在了70/72
> 
> 写的时候也想过`map/set`默认会保持key有序, 但是沉没成本...牵绊住了...嘿嘿嘿
```CPP
// 通过地址索引, 方便修改 => 事实上不会触发priority_queue的重排(因为pq中的元素是地址, 没有发生变化, find/erase也没有)
struct Food{
    string food;
    string cuisine;
    int rate;
    Food(string f, string c, int r): food(f), cuisine(c), rate(r){}
};
struct cmp{
    bool operator() (const Food* a, const Food* b) const{
        if(a->rate==b->rate){
            return a->food > b->food;
        }
        return a->rate < b->rate;
    }
};
unordered_map<string, priority_queue<Food*, vector<Food*>, cmp> > pqMap;
unordered_map<string, Food*> foodMp;
public:
FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    set<string> st(cuisines.begin(), cuisines.end());
    for(string cuisine: st){
        priority_queue<Food*, vector<Food*>, cmp> pq;
        pqMap[cuisine] = pq;
    }
    for(int i=0; i<foods.size(); i++){
        Food* f = new Food(foods[i], cuisines[i], ratings[i]);
        pqMap[cuisines[i]].push(f);
        foodMp[foods[i]] = f;
    }
}
void changeRating(string food, int newRating) {
    foodMp[food]->rate = newRating;
    priority_queue<Food*, vector<Food*>, cmp> newPq;
    while(!pqMap[foodMp[food]->cuisine].empty()){
        newPq.push(pqMap[foodMp[food]->cuisine].top());
        pqMap[foodMp[food]->cuisine].pop();
    }
    pqMap[foodMp[food]->cuisine] = newPq;
}
string highestRated(string cuisine) {
    return pqMap[cuisine].top()->food;
}
```

> 下面是cv题解
```CPP
// cuisine - <rate - set(foodName)>, 内部使用map保证ratings有序, set保证foodName有序
unordered_map<string, map<int, set<string>>> rank;

// foodName - 其他信息(cuisine, rate)
unordered_map<string, pair<string, int>> meta;

FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
    // 初始化 meta
    for (int i = 0; i < foods.size(); i++) {
        meta[foods[i]] = make_pair(cuisines[i], ratings[i]);
    }
    // 初始化 rank
    for (const auto &pair : meta) {
        // 按cuisine分别插入对应map, 再按rate插入对应分数的set
        rank[pair.second.first][pair.second.second].insert(pair.first);
    }
}

void changeRating(string food, int newRating) {
    // 从 rank 中删除旧的分数
    auto pair = meta.find(food);
    // 在 rank 中使用cuisine-rate索引到food
    rank[pair->second.first][pair->second.second].erase(food);
    if (rank[pair->second.first][pair->second.second].empty()) {
        rank[pair->second.first].erase(pair->second.second);
    }
    // 修改分数
    meta[food].second = newRating;
    // 向 rank 中重新插入新的food
    rank[pair->second.first][pair->second.second].insert(food);
}

string highestRated(string cuisine) {
    // 利用 rbegin() 和 begin() 得到答案
    auto pair = rank.find(cuisine);
    return *(pair->second.rbegin()->second.begin());
}
```