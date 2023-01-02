#### Biweek 2 - ✅✅❌✅

##### 1. [最多可以摧毁的敌人城堡数目](https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/): `模拟`
> 对每个`1`, 遇到`0`继续走, 直到找到第一个`-1`, 保证路径必须为`0`以及终点必须为`-1`
>
> 周赛的时候图省事, 只写了向右查找的代码, 然后将`forts`逆序, 再执行一次

```CPP
int captureForts(vector<int>& forts) {
    int n = forts.size();
    int ans = 0;
    for(int i=0; i<n; i++){
        // 对于每一个1
        if(forts[i]==1){
            // 向右找
            int j = i+1;
            while(j<n && forts[j]==0)   // 路径为0
                j++;
            if(j!=n && forts[j]==-1)    // 终点为-1
                ans = max(ans, j-i-1);
            // 向左找
            j = i-1;
            while(j>=0 && forts[j]==0)  // 路径为0
                j--;
            if(j!=-1 && forts[j]==-1)   // 终点为-1
                ans = max(ans, i-j-1);
        }
    }
    return ans;
}
```


##### 2. [奖励最顶尖的 K 名学生](https://leetcode.cn/problems/reward-top-k-students/)

> (1) 关于正向词/负向词对应分数的处理
> - 周赛中将所有正向词和负向词分别存到两个`set`中, 在`pos`和`neg`两个集合中检查存在性
> - 更方便的方式是直接用`map`记录单词对应的分数, `mp["smart"]=3`, `mp[not]=-1`
>
> (2) 如何获取`TopK`?
> - 周赛里用的`priority_queue`, 如果逐个插入维护大小为`K`的堆, 应该开销要比一次排序更大
> 
> - 直接存到`PII`类型的数组里, `n`项一起排序
>
> (但其实运行一下上面两个问题的两种方法, 发现开销都差不多...)
>
> (3) 排序
> - 按「`score`逆序 ➡️ `ID`正序」排序, 可以将其中一个加上➖, 然后就不需要自己实现排序了

> 补充一个按空格分割字符串的模板

```CPP
string s = "I'm a sentence"
string word;
stringstream ss(s);
while(ss >> word){
    // ...
}
```

###### (1) 直接排序
```CPP
typedef pair<int, int> PII;
vector<int> topStudents(vector<string>& p_words, vector<string>& n_words, vector<string>& report, vector<int>& student_id, int k) {
    int n = report.size();
    // 将单词对应的分数存入map, 不存在则分数为0
    unordered_map<string, int> scoresMp;
    for(string w: p_words)
        scoresMp[w] = 3;
    for(string w: n_words)
        scoresMp[w] = -1;
    // 定义PII类型的数组, 存入{-score, id}
    vector<PII> scores(n);
    for(int i=0; i<n; i++){
        string s = report[i];
        int id = student_id[i];
        int stu_score = 0;
        string word;
        stringstream ss(s);
        while(ss >> word){
            if(scoresMp.find(word) != scoresMp.end()){
                stu_score += scoresMp[word];
            }
        }
        scores[i] = {-stu_score, id};
    }
    // 直接对数组排序
    sort(scores.begin(), scores.end());
    vector<int> ans;
    for(int i=0; i<k; i++){
        ans.push_back(scores[i].second);
    }
    return ans;
}
```

###### (2) `priority_queue`
```CPP
class Solution {
public:
    typedef pair<int, int> PII;
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        int n = report.size();
        // set检查存在性做法
        unordered_set<string> pos;
        unordered_set<string> neg;
        for(string w: positive_feedback)
            pos.insert(w);
        for(string w: negative_feedback)
            neg.insert(w);
        // 第一维: 分数
        // 第二维: ID
        priority_queue<PII, vector<PII>, greater<PII>> pq;
        for(int i=0; i<n; i++){
            // 双指针做法
            string s = report[i];
            s += " ";
            int score = 0;
            int id = -student_id[i];
            for(int i=0; i<s.size(); i++){
                int j = i;
                while(j<s.size() && s[j]!=' '){
                    j++;
                }
                string word = s.substr(i, j-i);
                if(pos.find(word)!=pos.end())
                    score += 3;
                if(neg.find(word)!=neg.end())
                    score--;
                i = j;
            }
            pq.push({score, id});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<int> ans;
        while(k!=0){
            ans.push_back(-pq.top().second);
            pq.pop();
            k--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
```


##### 3. [最小化两个数组中的最大值](https://leetcode.cn/problems/minimize-the-maximum-of-two-arrays/)

> todo


##### 4. [统计同位异构字符串数目](https://leetcode.cn/problems/count-anagrams/): `math` `组合数` `排列`
> 第一次做出来第四题, 果然是粘模板代码...
> 
> 公式比较容易分析, 对于每个`word[i]`, 统计每个字母出现的次数, 然后求组合数即可, 即`word_ans *= C(rest_pos, cnt[i])`, `i∈[0,26)`
>
> 难点在于求较大范围内(`1e5`)的组合数, 可以参考[Acwing - S4 - 组合数II](/acwing/Section%204/5_%E6%B1%82%E7%BB%84%E5%90%88%E6%95%B0II.cpp)

> 由于力扣和Acwing的执行方式不一样, 力扣是每个case调用一次函数, 所以最好不要在每个函数内都求`1e5`范围内的所有`fact[]`和`infact[]`
> 
> 更好的方式是截取所有单词, 这样就不需要完整计算`N`范围内所有的`fact[]`和`infact[]`了

```CPP
const int N = 100010, MOD = 1e9+7;
int fact[N], infact[N];

int MOD = 1e9+7;
int quickPow(int a, int n, int p){
    long long ans = 1;
    while(n != 0){
        if(n & 1){
            ans *= a;
            ans %= p;
        }
        a = (long long)a * a % p;
        n >>= 1;
    }
    return ans;
}
void prepareFacts(int n){
    fact[0] = 1;
    infact[0] = 1;
    for(int i=1; i<n; i++){
        fact[i] = (long long)fact[i-1] * i % MOD;
        infact[i] = (long long)infact[i-1] * quickPow(i, MOD-2, MOD) % MOD;
    }
}
long long getCombination(int a, int b){
    int ans = (long long)fact[a] * infact[a-b] % MOD * infact[b] % MOD;
    return ans;
}
int countAnagrams(string s) {
    s += " ";
    vector<string> wordList;
    int maxLen = 0;
    // 双指针截取单词 => wordList
    for(int i=0; i<s.size(); i++){
        int j = i;
        while(j<s.size() && s[j]!=' ')
            j++;
        string word = s.substr(i, j-i);
        wordList.push_back(word);
        maxLen = max(maxLen, (int)word.size());
        i = j;
    }
    // 准备fact[]和infact[]两个数组, N取「最大单词长度+1」
    prepareFacts(maxLen + 1);
    long long ans = 1;
    for(string word: wordList){
        // 对于每个单词, 根据cnt[]计算「异构字符串」数量
        // e.g. too => cnt['o'-'a']=2, cnt['t'-'a']=1 => C(3, 2) * C(1, 1)
        int n = word.size();    // n:「剩余位置」
        long long word_ans = 1;
        int cnt[26] = {0};
        for(char ch: word){
            cnt[ch-'a']++;
        }
        for(int i=0; i<26; i++){
            if(cnt[i] != 0){
                word_ans *= getCombination(n, cnt[i]);
                n -= cnt[i];    // 记得更新「剩余位置」
                word_ans %= MOD;
            }
        }
        ans = ans * word_ans % MOD;
    }
    return ans;
}
```