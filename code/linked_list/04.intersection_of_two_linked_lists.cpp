#include<algorithm>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* currentA = headA;
        ListNode* currentB = headB;
        int lengthA = 0, lengthB = 0;
        while(currentA){
            currentA = currentA->next;
            lengthA++;
        }
        while(currentB){
            currentB = currentB->next;
            lengthB++;
        }
        currentA = headA;
        currentB = headB;
        if(lengthB > lengthA){
            std::swap(lengthA, lengthB);
            std::swap(currentA, currentB);
        }
        int length_diff = lengthA - lengthB;
        while(length_diff--){
            currentA = currentA->next;  //对齐链表长度，使AB链表的索引头尾结点对齐;
                                        //因为此题的链表相交不是单纯指表中的元素值一致，而是同样的地址
        }
        while(currentA != nullptr){
            if(currentA == currentB){
                return currentA;
            }
            currentA = currentA->next;
            currentB = currentB->next;
        }
        return nullptr;
    }
};