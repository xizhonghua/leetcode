/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        
        map<RandomListNode*, RandomListNode*> m;
        
        RandomListNode *h = new RandomListNode(head->label);
        RandomListNode *cur = h;
        
        m[head] = h;
        
        while(head) {
            
            if(head->random){
                if(!m.count(head->random)) {
                    RandomListNode *r = new RandomListNode(head->random->label);
                    m[head->random] = r;
                }
                cur->random = m[head->random];
            }
            
            if(head->next) {
                 if(!m.count(head->next)) {
                    RandomListNode *n = new RandomListNode(head->next->label);
                    m[head->next] = n;
                }
                cur->next = m[head->next];
            }
            
            head = head->next;
            cur = cur->next;
        }
        
        
        return h;
    }
};