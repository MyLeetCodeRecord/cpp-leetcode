/*
 * @lc app=leetcode.cn id=558 lang=cpp
 *
 * [558] 四叉树交集
 */

// @lc code=start
class Solution {
public:
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if(quadTree1->isLeaf == true && quadTree2->isLeaf == true){
            return new Node(quadTree1->val | quadTree2->val, true, NULL, NULL, NULL, NULL);
        }
        if(quadTree1->isLeaf == true){
            if(quadTree1->val == true)
                return new Node(true, true, NULL, NULL, NULL, NULL);
            else
                return quadTree2;
        }
        if(quadTree2->isLeaf == true){
            if(quadTree2->val == true)
                return new Node(true, true, NULL, NULL, NULL, NULL);
            else
                return quadTree1;
        }
        // 虽然QuadTree1和QuadTree2都不是leaf, 但可能 or 后所有元素相等 => isleft
        Node* topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
        Node* topRight = intersect(quadTree1->topRight, quadTree2->topRight);
        Node* bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
        Node* bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        if(topLeft->val==topRight->val && topRight->val==bottomLeft->val && bottomLeft->val==bottomRight->val 
            &&topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf)
            return new Node(true, true, NULL, NULL, NULL, NULL);
        else
            return new Node(quadTree1->val | quadTree2->val, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};
// @lc code=end

