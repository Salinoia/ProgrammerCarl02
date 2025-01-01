struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* sentinel_node = new ListNode(0);
        sentinel_node->next = head;
        ListNode* current_node = sentinel_node;
        while(current_node->next && current_node->next->next){
            ListNode* temp_node1 = current_node->next;// 暂存节点一
            ListNode* temp_node2 = current_node->next->next->next;// 暂存节点三
            current_node->next = current_node->next->next;// 哨兵节点指向节点二
            current_node->next->next = temp_node1;// 节点二指向节点一
            current_node->next->next->next = temp_node2;// 此时节点一的位置为current_node->next->next，节点一指向节点三

            current_node = current_node->next->next;// current_node右移两个节点
        }
        ListNode* res = sentinel_node->next;
        delete sentinel_node;
        sentinel_node = nullptr;
        return res;
    }
};