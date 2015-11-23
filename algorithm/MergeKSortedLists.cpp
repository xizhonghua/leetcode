//Run Time 88mm

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        ListNode *ans = new ListNode(0);
        ListNode *cur = ans;
        while(true) {
            bool flag = true;
            int min = INT_MAX;
            int min_id = -1;
            for(int i=0;i<lists.size();i++) {
                ListNode* head = lists[i];
                if(!head) continue;
                flag = false;
                if(head->val < min) {
                    min = head->val;
                    min_id = i;
                }
            }
            if(flag) break;
            cur->next = new ListNode(min);
            cur = cur->next;
            lists[min_id] = lists[min_id]->next;
        }
        
        return ans->next;
    }
};
