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
    bool hasCycle(ListNode *head) {
        if(head==NULL)return false;
        ListNode* slow=head;
        ListNode* fast=new ListNode(NULL);
        fast=head->next;

        while(fast && slow){
            if(fast==slow)return true;
            if(fast->next && fast->next->next){
                fast=fast->next->next;
            }else{
                return false;
            }
            
            slow=slow->next;
        }
        return false;
    }
};