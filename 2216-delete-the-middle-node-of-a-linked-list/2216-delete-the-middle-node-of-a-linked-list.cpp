/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        if(head->next==NULL){
            return NULL;
        }
        ListNode* prev=new ListNode(10);
        prev->next=head;
        while(fast->next && fast->next->next ){
            prev=slow;
            slow=slow->next;
            
            fast=fast->next->next;
        }
         if(fast->next!=NULL){
             prev=slow;
             slow=slow->next;
         }
        prev->next=slow->next;
        slow->next=NULL;
        delete(slow);
        return head;
    }
};