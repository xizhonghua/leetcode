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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> t;
        ListNode *c = l1;
        while(c != NULL)
        {
            t.push_back(c->val);
            c = c->next;
        }
        c = l2;
        while(c != NULL)
        {
            t.push_back(c->val);
            c = c->next;
        }
        
        sort(t.begin(), t.end());
        
        ListNode *head = NULL;
        ListNode *cur = NULL;
        
        if(t.size())
        {
            head = new ListNode(t[0]);                    
            
            cur = head;
            
            for(int i=1;i<t.size();i++)
            {
                ListNode *l = new ListNode(t[i]);
                cur->next = l;
                cur = l;
            }
        }
        
        return head;        
    }
};