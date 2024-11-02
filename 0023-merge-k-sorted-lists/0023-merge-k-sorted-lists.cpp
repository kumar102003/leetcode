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
     ListNode * merge(ListNode* l1 , ListNode* l2){
        if(!l1){
            return l2;
        }
        if(!l2){
            return l1;
        }
        if(l1->val<=l2->val){
            l1->next  = merge(l1->next, l2);
            return l1;
        }
        else{
            l2->next = merge(l1,l2->next);
            return l2;
        }
        return NULL;
     }
     ListNode* part(int s , int e , vector<ListNode*>& lists){
        
        if(s>e){
            return NULL;
        }
        if(s==e){
            return lists[s];
    }
        int mid = s + ( e-s)/2;
        ListNode * l1  = part(s, mid , lists);
        ListNode * l2 = part(mid+1, e , lists);
        return merge(l1,l2);
     }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int s = 0 ;
        int e = lists.size()-1;
    if(lists.size()==0){
        return NULL;
    }
    return part( 0  , e,lists);
    }
};