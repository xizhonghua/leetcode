class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        unordered_map<int, set<int>> g;
        
        for(const auto e : edges) {
            g[e.first].insert(e.second);
            g[e.second].insert(e.first);
        }
        
        while(g.size()>2) {
            vector<int> leaves;
            for(const auto& kv : g) 
                if(kv.second.size()==1) leaves.push_back(kv.first);
            for(const auto l : leaves)
            {
                for(auto nb : g[l])
                    g[nb].erase(l);
                g.erase(l);
            }
        }
        
        if(g.size()==0) return {0};
        
        vector<int> roots;
        for(const auto kv : g) roots.push_back(kv.first);
        return roots;
    }
};
