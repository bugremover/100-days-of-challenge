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
private:
    
    ListNode* reverseLinkedList(ListNode *head) 
    {
        ListNode *currNode = head, *prevNode = nullptr, *nextNode;
        while (currNode != nullptr) 
        {
            nextNode = currNode->next;
            currNode->next = prevNode;
            prevNode = currNode;
            currNode = nextNode;
        }
        return prevNode;
    }

     
    ListNode* getKthNode(ListNode *temp, int k) 
    {
        k -= 1;
        while (temp != nullptr && k > 0) 
        {
            k--;
            temp = temp->next;
        }
        return temp;
    }

public:
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode *temp = head, *prevNode = nullptr, *nextNode = nullptr;
        
        while (temp != nullptr) 
        { 
            
            ListNode *kthNode = getKthNode(temp, k);

            
            if (kthNode == nullptr) 
            {
                if (prevNode != nullptr) 
                {
                    prevNode->next = temp;
                }
                break;
            }
            nextNode = kthNode->next;

            
            kthNode->next = nullptr;

          
            reverseLinkedList(temp);
            if (temp == head) 
            {
                head = kthNode;
            } else 
            {
                prevNode->next = kthNode;
            }

           
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};