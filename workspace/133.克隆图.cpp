/*
 * @lc app=leetcode.cn id=133 lang=cpp
 *
 * [133] 克隆图
 */

// @lc code=start
class Solution {
public:
    unordered_map<Node*, Node*> hash;
    Node* DFS(Node* node){
        if(hash.find(node) != hash.end())
            return hash[node];
        Node* newNode = new Node(node->val);
        hash[node] = newNode;
        for(Node* neighbor: node->neighbors){
            newNode->neighbors.push_back(DFS(neighbor));
        }
        return newNode;
    }
    Node* cloneGraph(Node* node){
        if(node==NULL)
            return NULL;
        return DFS(node);
    }
};
// @lc code=end

