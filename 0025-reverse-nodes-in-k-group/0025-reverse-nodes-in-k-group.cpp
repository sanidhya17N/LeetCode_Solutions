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
    ListNode* revInK(ListNode* head,int k,int numrev){
        if(numrev==0)return head;
        int counter=0;
        ListNode* curr=head;
        ListNode* prev=new ListNode(0);
        ListNode* next=new ListNode(0);
        prev->next=curr;
        next=head;
        while(counter<k){
            counter++;
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head->next=revInK(curr,k,numrev-1);
        return prev; ;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size=0;
        ListNode* curr=head;
        while(curr){
            curr=curr->next;
            size++;
        }
        int numrev=size/k;
        head=revInK(head,k,numrev);
        return head;
    }
};