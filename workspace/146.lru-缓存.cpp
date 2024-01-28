/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU 缓存
 */

// @lc code=start
struct Node {
    Node* pre;
    Node* next;
    int key;
    int val;
    Node(int k, int v){
        key = k;
        val = v;
    }
};
class LRUCache {
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;
    int limit;
public:
    LRUCache(int capacity) {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->pre = head;
        limit = capacity;
    }
    void insertNode(Node* node){
        node->next = head->next;
        head->next->pre = node;
        node->pre = head;
        head->next = node;
    }
    void deleteNode(Node* node){
        node->pre->next = node->next;
        node->next->pre = node->pre;
    }
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        deleteNode(mp[key]);
        insertNode(mp[key]);
        return mp[key]->val;
    }
    void put(int key, int value) {
        Node* node = new Node(key, value);
        if(mp.find(key) != mp.end()){
            node = mp[key];
            node->val = value;
            deleteNode(node);
        }
        mp[key] = node;
        insertNode(node);
        if(mp.size() > limit){
            mp.erase(tail->pre->key);
            deleteNode(tail->pre);
        }
    }
};
// @lc code=end

