/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
class Solution {
public:
    // AA'BB'CC' -> 修改random -> 保留A'B'C'
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        // 复制AABBCC
        Node* cur = head;
        while(cur != NULL){
            Node* copyCur = new Node(cur->val);
            copyCur->next = cur->next;
            cur->next = copyCur;
            cur = copyCur->next;
        }
        // 修改Random
        cur = head;
        while(cur != NULL){
            if(cur->random != NULL){
                Node* copyCur = cur->next;
                copyCur->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        // 拆分链表
        cur = head;
        Node* ans = cur->next;
        while(cur != NULL){
            Node* copyCur = cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
            if(cur != NULL)
                copyCur->next = copyCur->next->next;
        }
        return ans;
    }
    /*
    // 深拷贝1: DFS+hash
    unordered_map<Node*, Node*> hash;
    Node* DFS(Node* node){
        if(node==NULL)
            return NULL;
        if(hash.find(node) != hash.end())
            return hash[node];
        Node* newNode = new Node(node->val);
        hash[node] = newNode;
        newNode->next = DFS(node->next);
        newNode->random = DFS(node->random);
        return newNode;
    }
    Node* copyRandomList(Node* head) {
        return DFS(head);
    }
    */
    /*
    // 深拷贝2: 先复制节点, 并建立节点hash, 然后复制指针
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return NULL;
        unordered_map<Node*, Node*> hash;
        // 建立旧节点到新节点的映射
        Node* cur = head;
        while(cur != NULL){
            Node* copy = new Node(cur->val, NULL, NULL);
            hash[cur] = copy;
            cur = cur->next;
        }
        // 复制指针
        cur = head;
        while(cur != NULL){
            hash[cur]->next = hash[cur->next];
            hash[cur]->random = hash[cur->random];
            cur = cur->next;
        }
        // 返回复制后新的head
        return hash[head];
    }
    */
};
// @lc code=end

