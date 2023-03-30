class Solution {
public:
    // 递归 - 美团二面
    // 后序遍历结果: postLeft | postRight | root
    bool verify(vector<int> &post, int l, int r){
        if(l >= r)
            return true;
        int rootVal = post[r];
        // 左子树 / 前半段
        int p = l;
        while(p<r && post[p] < rootVal)
            p++;
        // 右子树 / 后半段
        int q = p;
        while(q < r && post[q] > rootVal)
            q++;
        return q==r && verify(post, l, p-1) && verify(post, p, r-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size()-1);
    }
};