struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* temp_node;
        ListNode* sentinel_node = nullptr;
        ListNode* current_node = head;
        while(current_node){
            temp_node = current_node->next;     // 暂存当前节点的下一节点，因为会修改current_node->next
            current_node->next = sentinel_node; // 将当前节点的 next 指向新链表的尾部
            sentinel_node = current_node;// 移动哨兵节点至当前节点
            current_node = temp_node;// 移动当前节点至暂存状态时的节点的下一节点
        }
        return sentinel_node;
    }
};