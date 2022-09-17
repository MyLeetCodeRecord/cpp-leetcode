/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
struct LinkedNode{
    int val;
    LinkedNode* next;
    LinkedNode(int val): val(val), next(NULL) {}
};
class MyLinkedList {
public:
    LinkedNode* _dummyHead;
    int _size;
    
    MyLinkedList() {
        _dummyHead = new LinkedNode(-1);
        _size = 0;
    }
    
    int get(int index) {
        if(index >= _size || index < 0)
            return -1;
        LinkedNode* cur = _dummyHead->next;
        while(index > 0){
            cur = cur->next;
            index--;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) {
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(cur->next != NULL){
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index > _size || index < 0)
            return ;
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;
        while(index > 0){
            cur = cur->next;
            index--;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
    }
    
    void deleteAtIndex(int index) {
        if(index >= _size || index < 0)
            return ;
        LinkedNode* cur = _dummyHead;
        while(index > 0){
            cur = cur->next;
            index--;
        }
        cur->next = cur->next->next;
        _size--;
    }
};
// @lc code=end

