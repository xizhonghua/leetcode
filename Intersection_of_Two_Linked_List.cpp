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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int stepA, stepB;
        ListNode* lastA = this->getLastNode(headA, stepA);
        ListNode* lastB = this->getLastNode(headB, stepB);
        if (lastA == lastB) {
            int diff = stepA - stepB;
            for(auto i=0;i<diff;i++) headA = headA->next;
            for(auto i=0;i>diff;i--) headB = headB->next;
            while(headA!=headB) {
                headA = headA->next;
                headB = headB->next;
            }
            return headA;
        }
        return NULL;
    }
private:
    ListNode* getLastNode(ListNode* head, int& steps) {
        steps = 0;
        while(head && head->next) {
            head = head->next;
            steps++;
        }
        return head;
    }
};
