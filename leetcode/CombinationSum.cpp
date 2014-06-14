class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        m_s.clear();
        sort(candidates.begin(), candidates.end());
        vector<int> cur;
        dfs(0,cur,candidates,target);
        return vector<vector<int> >(m_s.begin(), m_s.end());
    }
private:
    set<vector<int> > m_s;
    void dfs(int s, vector<int>& cur, vector<int>& c, int target) {
        if(target == 0) {
            if(!m_s.count(cur)) m_s.insert(cur);
            return;
        }
        for(int i=s;i<c.size();i++) {
            if(target < c[i]) return;
            cur.push_back(c[i]);
            dfs(i, cur, c, target-c[i]);
            cur.pop_back();
        }
    }
};