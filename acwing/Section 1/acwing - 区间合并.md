#### 区间合并

> 其它[区间题目](/markdown/%E4%B8%93%E9%A2%98%20-%20%E5%8C%BA%E9%97%B4.md)

##### 1. 区间左端点排序
```CPP
bool cmp(PII l, PII r){
    return l.first < r.first;
}
```

##### 2. 逐个区间扫描
> 当前区间(复制一份)与后续区间只存在三种相对关系
> - ① 跳过不做处理
> - ② 更新当前维护的区间右端点
> - ③ 结束当前区间维护, 加入结果集
> 
> ![区间合并](/appendix/区间合并.png)

```CPP
typedef pair<int,int> PII;
vector<PII> intervals, ans;

// 按区间左端点(开始时间)排序
bool cmp(pair<int,int> l, pair<int,int> r){
    return l.first < r.first;
}
vector<PII> intervalMerge(vector<PII> intervals){
    sort(intervals.begin(), intervals.end(), cmp);  // 默认排序也可以
    PII curInterval = intervals[0]; // curInterval当前维护区间, 也可以初始化为(-∞,-∞)
    for(int i=0; i<intervals.size(); i++){
        // 当前区间维护结束
        if(curInterval.second < intervals[i].first){
            ans.push_back(curInterval);
            curInterval = intervals[i];
            continue;
        }
        // 继续维护当前区间
        else{
            curInterval.second = max(curInterval.second, intervals[i].second);
        }
    }
    // 最后一个区间
    ans.push_back(curInterval);
    return ans;
}
```