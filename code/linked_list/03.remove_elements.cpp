struct ListNode{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr){}
    ListNode(int x, ListNode* next) : val(x), next(next){}  
};

class Solution{
public:
    ListNode* removeElements(ListNode* head, int val){
        while(head != nullptr && head->val == val){
            ListNode* current_node = head;
            head = head->next;
            delete current_node;
        }
        ListNode* current_node = head;
        while(current_node != nullptr && current_node->next != nullptr){
            if(current_node->next->val == val){
                ListNode* temp_node = current_node->next;
                current_node->next = temp_node->next;
                delete temp_node;
            }
            else{
                current_node = current_node->next;
            }
        }
        return head;
    }
    ListNode* removeElementsBySentinelNode(ListNode* head, int val){
        // 使用虚拟头结点(哨兵节点)
        ListNode* sentinel_node = new ListNode(0);
        sentinel_node->next = head;
        ListNode* current_node = sentinel_node;
        while(current_node->next != nullptr){
            if(current_node->next->val == val){
                ListNode* temp_node = current_node->next;
                current_node->next = temp_node->next;
                delete temp_node;
            }
            else{
                current_node = current_node->next;
            }
        }
        return sentinel_node->next;
    }
};