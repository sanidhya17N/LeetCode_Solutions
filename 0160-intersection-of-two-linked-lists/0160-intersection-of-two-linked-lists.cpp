/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int length(ListNode* node){
        int len=0;
        while(node){
            node=node->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA=length(headA);
        int lenB=length(headB);
        int diff=abs(lenA-lenB);
        if(lenA>lenB){
            while(diff--){
                headA=headA->next;
            }
        }else{
            while(diff--){
                headB=headB->next;
            }
        }

        while(headA!=headB){
            headA=headA->next;
            headB=headB->next;
        }
        return headB;
    }
};