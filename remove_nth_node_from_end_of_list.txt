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
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p = head;
        
        vector<ListNode *> v;
        
        while(p)
        {
            v.push_back(p);
            p = p->next;
        }
        
        if(v.size()>1)
        {
            if(n==1)
            {
                p = v[v.size()-2];
                p->next = NULL;
            }
            else if(n==v.size())
            {
                head = v[1];
            }
            else
            {
                p = v[v.size()-n-1];
                p->next = p->next->next;
            }
        
        }
        else
        {
            return NULL;
        }
        
        
        return head;        
    }
};