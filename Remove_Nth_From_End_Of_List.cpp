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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if(!head) return NULL;
        vector<ListNode *> nodes;
        ListNode *cur = head;
        while(cur) {
            nodes.push_back(cur);
            cur=cur->next;
        }
        if(n == nodes.size()) return head->next;
        
        ListNode *nodes_to_remove = nodes[nodes.size()-n];
        ListNode *parent = nodes[nodes.size()-n-1];
        parent->next = nodes_to_remove->next;
        
        return head;
    }
};