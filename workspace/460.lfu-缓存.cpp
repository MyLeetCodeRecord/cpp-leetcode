/*
 * @lc app=leetcode.cn id=460 lang=cpp
 *
 * [460] LFU 缓存
 */

// @lc code=start
struct Node {
    int key, val;
    int freq;
    Node* pre;
    Node* nxt;
    Node(int k=0, int v=0){
        key = k;
        val = v;
        freq = 1;
    }
};
class LFUCache {
    int limit;
    int min_freq;   // 用于已满时, 进行O(1)删除
    unordered_map<int, Node*> key_to_node;
    unordered_map<int, Node*> freq_to_head;
    Node* newList() {
        Node* head = new Node();
        head->nxt = head;
        head->pre = head;
        return head;
    }
    Node* getNode(int key) {
        if(key_to_node.find(key) == key_to_node.end()){
            return NULL;
        }
        Node* node = key_to_node[key];
        remove(node);
        Node* head = freq_to_head[node->freq];
        if(head->pre == head){
            freq_to_head.erase(node->freq);
            delete head;
            if(min_freq == node->freq){
                min_freq++;
            }
        }
        push_front(++node->freq, node);
        return node;
    }
    void remove(Node* x){
        x->pre->nxt = x->nxt;
        x->nxt->pre = x->pre;
    }
    void push_front(int freq, Node* node){
        if(freq_to_head.find(freq) == freq_to_head.end())
            freq_to_head[freq] = newList();
        Node* head = freq_to_head[freq];
        node->pre = head;
        node->nxt = head->nxt;
        head->nxt->pre = node;
        head->nxt = node;
    }
public:
    LFUCache(int capacity) {
        limit = capacity;
    }
    int get(int key) {
        Node* node = getNode(key);
        if(node != NULL)
            return node->val;
        return -1;
    }
    void put(int key, int value) {
        Node* node = getNode(key);
        if(node != NULL){
            node->val = value;
            return ;
        }
        if(key_to_node.size() == limit){
            Node* head = freq_to_head[min_freq];
            Node* bottom = head->pre;
            key_to_node.erase(bottom->key);
            remove(bottom);
            delete bottom;
            if(head->pre == head){
                freq_to_head.erase(min_freq);
                delete head;
            }
        }
        Node* cur = new Node(key, value);
        key_to_node[key] = cur;
        push_front(1, cur);
        min_freq = 1;
    }
};
// @lc code=end

