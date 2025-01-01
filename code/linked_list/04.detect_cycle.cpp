struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution{
public:
    ListNode* detectCycle(ListNode* head){
        // 判断链表有无环一定是从最后的节点向前遍历以匹配，因为链表的结构只存在一个指向后方的next，所以快指针优先遍历到队尾，再用next匹配
        // 现在的问题在于，如何判断这个节点是“最后”的节点，如果存在环的话，终止条件肯定不是next为空，理论来说，判断条件应该是next->next->...->next与当前的next位于同一位置
        // 那么只要有环，快慢指针以速率一个节点差的方式遍历，总会相遇在一起，且一定会相遇在环中
        ListNode* SlowNode = head;
        ListNode* FastNode = head;
        while((FastNode != nullptr) && (FastNode->next!= nullptr)){
            SlowNode = SlowNode->next;
            FastNode = FastNode->next->next;
            if(FastNode == SlowNode){
                ListNode* FirstEncounter = FastNode;
                ListNode* EntranceNode = head;
                while(FirstEncounter != EntranceNode){
                    FirstEncounter = FirstEncounter->next;
                    EntranceNode = EntranceNode->next;
                }
                return EntranceNode;
            }
        }
        return nullptr;
    }
};
