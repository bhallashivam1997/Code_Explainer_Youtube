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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* copy_ptr=list1;
        if(list1==NULL) return list1;
        if(list1->next==NULL) return list2;
        ListNode* prev=NULL;
        ListNode* curr=list1;
        ListNode* last_b=list2;
        int c=0;
        while(last_b->next!=NULL){
            last_b=last_b->next;
        }
        ListNode* prev_a;
        ListNode* curr_b;
        while(1){
            c++;
            prev=curr;
            curr=curr->next;
            if(c==a){
                prev_a=prev;
            }
            if(c-1==b){
                curr_b=curr;
                break;
            }
        }
        prev_a->next=list2;
        last_b->next=curr_b;
        return copy_ptr;
    }
};
