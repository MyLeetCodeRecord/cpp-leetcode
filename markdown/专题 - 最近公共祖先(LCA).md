#### [最近公共祖先LCA](https://www.bilibili.com/video/BV1W44y1Z7AR/?spm_id_from=333.337.search-card.all.click)

|  题目  |  类型  |
|  :-:  |  :-:  |
|[LC236. 二叉树的最近公共祖先](/markdown/%E4%B8%93%E9%A2%98%20-%20%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88(LCA).md#lc236-%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88-%E9%80%92%E5%BD%92)|`递归`|
|[LC235. 二叉搜索树的最近公共祖先](/markdown/%E4%B8%93%E9%A2%98%20-%20%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88(LCA).md#lc235-%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88-bst-%E9%80%92%E5%BD%92)|`递归` `BST`|
|[LC2509. 查询树中环的长度](/markdown/%E4%B8%93%E9%A2%98%20-%20%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88(LCA).md#lc2509-%E6%9F%A5%E8%AF%A2%E6%A0%91%E4%B8%AD%E7%8E%AF%E7%9A%84%E9%95%BF%E5%BA%A6-%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88lca-%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91)|`完全二叉树`

##### 1. 递归
###### [LC236. 二叉树的最近公共祖先](/workspace/236.%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.cpp): `递归`
 
> ![LCA](/appendix/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%9A%84LCA-2.png)

```CPP
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL)
        return NULL;
    if(root==p || root==q)
        return root;
    // 分别检查left, right是否含有p, q中的一个或者两个(几个不重要)
    TreeNode* l = lowestCommonAncestor(root->left, p, q);
    TreeNode* r = lowestCommonAncestor(root->right, p, q);
    if(l!=NULL && r!=NULL)
        return root;
    if(l!=NULL)
        return l;
    else
        return r;
}
```


###### [LC235. 二叉搜索树的最近公共祖先](/workspace/235.%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84%E6%9C%80%E8%BF%91%E5%85%AC%E5%85%B1%E7%A5%96%E5%85%88.cpp): `BST` `递归`

> ![BST-LCA](/appendix/%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91%E7%9A%84LCA.png)

```CPP
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || root==p || root==q)
        return root;
    // 借助BST的性质, 最多只需要选一边(left/right)进行DFS
    if(root->val>p->val && root->val>q->val)
        return lowestCommonAncestor(root->left, p, q);
    else if(root->val<p->val && root->val<q->val)
        return lowestCommonAncestor(root->right, p, q);
    else
        return root;
}
```


##### 2. 完全二叉树的LCA
  ###### [LC2509. 查询树中环的长度](https://leetcode.cn/problems/cycle-length-queries-in-a-tree/): `最近公共祖先LCA` `完全二叉树`

> [12月周赛](/record/2022/Dec-Weekly-3.md)第四题 - `LCA`问题, `len = dist(a, lca) + dist(b, lca) + 1`
> 
> y总 ➡️ 爬山法: **先调到同一层**, 然后共同向上查找公共祖先, 向上爬升的过程就是遍历环的过程, 额外加一条`<a, b>`
> 
> 灵神 ➡️ 每次选深度更深的点(编号更大), **交替上升**

```CPP
// y总: 先对齐, 再一起爬升
int getHeight(int x){
    int h = 0;
    while(x!=0){
        x /= 2;
        h++;
    }
    return h;
}
vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> ans;
    for(vector<int> q: queries){
        int a = q[0];
        int b = q[1];
        if(a < b)
            swap(a, b);
        int ah = getHeight(a);
        int bh = getHeight(b);
        int len = 0;
        for(int i=0; i<ah-bh; i++){
            a /= 2;
            len++;
        }
        while(a!=b){
            a /= 2;
            b /= 2;
            len += 2;
        }
        ans.push_back(len+1);
    }
    return ans;
}
```

```CPP
// 灵神: 交替上升
vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
    vector<int> ans;
    for(vector<int> &q: queries){
        int a = q[0];
        int b = q[1];
        int len = 0;
        while(a != b){
            if(a > b)
                a /= 2;
            else
                b /= 2;
            len++;
        }
        ans.push_back(len+1);
    }
    return ans;
}
```