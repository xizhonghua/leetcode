class Solution {
public:
    typedef unordered_map<int, unordered_set<int>> G;
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        G g;
        
        for(const auto p : prerequisites)
            g[p.first].insert(p.second);
        
        // states: 0 = unkonwn, 1 == visited, -1 = noloop
        vector<int> v(numCourses, 0);
        
        for(const auto p : g)
            if(dfs(g, p.first, v)) return false;
        
        return true;
    }
    
private:    
    bool dfs(G& g, int cur, vector<int>& v) {
        if(v[cur] == 1) return true;
        if(v[cur] == -1) return false;
        
        v[cur] = 1;
        
        for(const int t : g[cur])
            if(dfs(g, t, v)) return true;
        
        v[cur] = -1;
        
        return false;
    }
};
