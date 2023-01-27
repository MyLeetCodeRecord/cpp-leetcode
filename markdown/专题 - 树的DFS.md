#### 树的DFS

> ![树的DFS](/appendix/%E6%A0%91%E7%9A%84DFS.png)
>
> ![树的DFS-2](/appendix/%E6%A0%91%E7%9A%84DFS-2.png)



##### 需要上面的计算结果 ➡️ 计算结果作为`DFS`的参数一起向下传递

###### [LC129. 求根节点到叶节点的数字之和](/workspace/129.%E6%B1%82%E6%A0%B9%E8%8A%82%E7%82%B9%E5%88%B0%E5%8F%B6%E8%8A%82%E7%82%B9%E6%95%B0%E5%AD%97%E4%B9%8B%E5%92%8C.cpp)

> ![LC129](/appendix/LC129.png)

```CPP
// DFS到当前节点时, 需要用到前面的信息, 因此需要作为参数传进来
int DFS(TreeNode* root, int preSum){
    if(root==NULL)
        return 0;
    int sum = preSum*10 + root->val;
    if(root->left==NULL && root->right==NULL)
        return sum;
    return DFS(root->left, sum) + DFS(root->right, sum);
}
int sumNumbers(TreeNode* root) {
    return DFS(root, 0);
}
```