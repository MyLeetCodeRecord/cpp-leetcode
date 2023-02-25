class Solution {
public:
    // 前序遍历结果: root | preLeft | preRight | 
    bool verify(vector<int> &pre, int l, int r){
        if(l >= r)
            return true;
        int rootVal = pre[l];
        // 左子树 / 前半段
        int p = l+1;
        while(p <= r && pre[p] < rootVal)
            p++;
        // 右子树 / 后半段
        int q = p;
        while(q <= r && pre[q] > rootVal)
            q++;
        return (q == r+1) && verify(pre, l+1, p-1) && verify(pre, p, r);
    }
    bool verifyPreorder(vector<int>& preorder) {
        return verify(preorder, 0, preorder.size()-1);
    }
};