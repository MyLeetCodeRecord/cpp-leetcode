class Solution {
public:
    // 后序遍历结果: postLeft | postRight | root
    bool verifyPost(vector<int>& postorder, int left, int right){
        if(left>=right)
            return true;
        int rootVal = postorder[right];
        // 左子树 / 前半段
        int l = left;
        while(l < right && postorder[l] < rootVal)
            l++;
        // 右子树 / 后半段
        int r = l;
        while(r < right && postorder[r] > rootVal)
            r++;
        return r == right 
            && verifyPost(postorder, left, l-1)
            && verifyPost(postorder, l, r-1);
    }
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPost(postorder, 0, postorder.size()-1);
    }
};