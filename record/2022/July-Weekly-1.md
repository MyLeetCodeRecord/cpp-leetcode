#### Weekly 1

##### 1. 解密消息

> [题目](https://leetcode.cn/problems/decode-the-message/) - 简单的`hash`问题

```CPP
string decodeMessage(string key, string message) {
    vector<int> hashTable(26, -1);
    int index = 0;
    for(int i=0; i<key.size(); i++){
        if(key[i]==' ')
            continue;
        if(hashTable[key[i]-'a'] == -1)
            hashTable[key[i]-'a'] = index++;
    }
    for(int i=0; i<message.size(); i++){
        if(message[i]==' ')
            continue;
        message[i] = 'a' + hashTable[message[i]-'a'];
    }
    return message;
}
```

##### 2. 螺旋矩阵Ⅳ

> [题目](https://leetcode.cn/problems/spiral-matrix-iv/) - `matrix`
> 
> 与[LC54. 螺旋矩阵](https://leetcode.cn/problems/spiral-matrix/)和[LC59. 螺旋矩阵II](https://leetcode.cn/problems/spiral-matrix-ii)是同一道题, 熟能生巧...
>
> 本题要对链表长度不足的情况提前终止

```CPP
vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    int left = 0;
    int right = n-1;
    int up = 0;
    int down = m-1;
    
    vector<vector<int> > matrix(m, vector<int>(n, -1));
    while(head!=NULL && left<=right && up<=down){
        for(int i=left; i<=right; i++){
            if(head==NULL)
                return matrix;
            matrix[up][i] = head->val;
            head = head->next;
        }
        up++;
        for(int j=up; j<=down; j++){
            if(head==NULL)
                return matrix;
            matrix[j][right] = head->val;
            head = head->next;
        }
        right--;
        for(int i=right; i>=left; i--){
            if(head==NULL)
                return matrix;
            matrix[down][i] = head->val;
            head = head->next;
        }
        down--;
        for(int j=down; j>=up; j--){
            if(head==NULL)
                return matrix;
            matrix[j][left] = head->val;
            head = head->next;
        }
        left++;
    }
    return matrix;
}
```


##### 3. 知道秘密的人数

> [题目](https://leetcode.cn/problems/number-of-people-aware-of-a-secret/) - `动态规划`
>
> `dp[j]`: 第j天新增的人数, 其值为`delay~forget`范围内的`dp[i]`之和
>
> 最后在时刻 n 倒推`forget`范围内的新增人数之和, 即为ans

```CPP
int peopleAwareOfSecret(int n, int delay, int forget) {
    // dp[i]: 第i天新增的人数
    vector<int> dp(n, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i+delay; j<i+forget && j<n; j++) {
            dp[j] += dp[i];
            dp[j] %= 1000000007;
        }
    }
    // 倒数forget范围内的新增为n时刻知道秘密的人数
    int ans = 0;
    for (int i = n-forget; i < n; i++) {
        ans += dp[i];
        ans %= 1000000007;
    }
    return ans;
}
```