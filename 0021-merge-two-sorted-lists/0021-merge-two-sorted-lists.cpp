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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp=new ListNode(1);
        ListNode* head=temp;
        while(list1 && list2){
            if(list1->val<=list2->val){
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }else{
                temp->next=list2;
                temp=temp->next;
                list2=list2->next;
            }
        }
        if(!list1){
            while(list2){
                temp->next=list2;
                temp=temp->next;
                list2=list2->next;
            }
        }else if(!list2){
            while(list1){
                temp->next=list1;
                temp=temp->next;
                list1=list1->next;
            }

        }
        return head->next;
    }
};