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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL) {
        return NULL;
    }
        int k = 2;
        ListNode* next = NULL;
        ListNode* prev = NULL;
        ListNode* curr = head;
        int count = 0;
        while(curr!=NULL && count<k){
          next = curr->next;
            curr->next = prev ;
            prev = curr;
            curr= next ;
            count++;
        }
        if(next!=NULL){
        head->next  = swapPairs(next);
        }
        return prev;
    }
};