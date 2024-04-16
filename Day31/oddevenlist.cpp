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
    ListNode* oddEvenList(ListNode* head) {
    if(head==NULL || head->next==NULL || head->next->next==NULL) return head;
    ListNode* slow=head;
    ListNode* fast=head->next;
    ListNode* ans=fast;
    while(fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        ListNode* aftereven=fast->next->next;
        slow->next=fast->next;
        slow=fast->next;
        slow->next=NULL;
        fast->next=aftereven;
        fast=aftereven;
    }
    if(fast->next!=NULL){
    slow->next=fast->next;
    slow=slow->next;
    slow->next=NULL;
    fast->next=NULL;
    }
    slow->next=ans;
    return head;
    }
};