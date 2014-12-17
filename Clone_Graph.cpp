/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL) return NULL;
        
        typedef UndirectedGraphNode Node;
        
        set<Node*> v;
        queue<Node*> q;
        unordered_map<Node*, Node*> m;
        
        q.push(node);
        while(!q.empty())
        {
            const auto n = q.front();
            q.pop();
            if(v.count(n)!=0) continue;
            v.insert(n);
            if(m[n]==NULL) m[n] = new Node(n->label);
            for(const auto& nb : n->neighbors)
            {
                q.push(nb);
                if(m[nb]==NULL) m[nb] = new Node(nb->label);
                m[n]->neighbors.push_back(m[nb]);
            }
        }
        
        return m[node];
    }
};
