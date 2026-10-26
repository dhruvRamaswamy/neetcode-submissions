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
        ListNode dummy;
        ListNode* tail = &dummy;
        // You loop until one of them runs out
        // Then you just tack it on at the end

        while(list1 && list2) {
            if(list1->val >= list2->val) {
                tail->next = list2;
                list2 = list2->next;
            }
            else {
                tail->next = list1;
                list1 = list1->next;
            }
            tail = tail->next;
        }
        // One of the is going to be null
        tail->next = list1 ? list1 : list2;
        // attach ptr to 
        return dummy.next;




    }
};
