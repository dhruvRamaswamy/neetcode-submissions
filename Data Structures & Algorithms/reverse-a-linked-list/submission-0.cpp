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
    ListNode* reverseList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        // auto l1 = *ListNode();
        // We can do this in two passes:
        vector<int> nums;
        auto nodePtr = head;
        while(nodePtr != nullptr) {
            // This needs to be (val)
            nums.push_back(nodePtr->val);
            nodePtr = nodePtr->next;
        }
        for(int i : nums) {
            printf("%d, ", i);
        }
        
        ListNode dummy;
        ListNode* tail = &dummy;
        for (int i = nums.size() - 1; i >= 0; i--) {
            tail->next = new ListNode(nums[i]);
            tail = tail->next;
        }

        return dummy.next;
    }
};
