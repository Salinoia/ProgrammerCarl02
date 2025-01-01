
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* sentinel_node = new ListNode(0);
        sentinel_node->next = head;
        ListNode* slow_node = sentinel_node;
        ListNode* fast_node = sentinel_node;
        while(n-- && fast_node){
            fast_node = fast_node->next;
        }
        fast_node = fast_node->next;// fast右移，删除倒数第N个节点，slow则最终会指向需要删除的上一个节点
        while(fast_node){
            slow_node = slow_node->next;
            fast_node = fast_node->next;
        }
        ListNode* temp_node = slow_node->next;
        slow_node->next = slow_node->next->next;
        delete temp_node;
        return sentinel_node->next;
    }
};