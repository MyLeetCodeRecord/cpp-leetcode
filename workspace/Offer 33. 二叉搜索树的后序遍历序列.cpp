class Solution {
public:
    // 递归 - 美团二面
    // 后序遍历结果: postLeft | postRight | root
    bool verify(vector<int> &postorder, int l, int r){
        if(l>=r)
            return true;
        int rootVal = postorder[r];
        // 左子树 / 前半段
        int i = l;
        while(i < r && postorder[i] < rootVal){
            i++;
        }
        // 右子树 / 后半段
        for(int j=i; j<=r-1; j++){
            if(postorder[j] <= rootVal)
                return false;
        }
        return verify(postorder, l, i-1) && verify(postorder, i, r-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return verify(postorder, 0, postorder.size()-1);
    }
};