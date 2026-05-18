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
        ListNode *temp1 = list1, *temp2 = list2, *dummy = new ListNode(0), *temp3 = dummy;

        while(temp1 && temp2){
            if(temp1 -> val < temp2 -> val) {
                temp3 -> next = temp1;
                temp1 = temp1 -> next;
            } else {
                temp3 -> next = temp2;
                temp2 = temp2 -> next;
            }
            temp3 = temp3 -> next;
        }
        if(temp1){
            temp3 -> next = temp1;
        }
        if(temp2){
            temp3 -> next = temp2;
        }

        return dummy -> next;
    }
};
