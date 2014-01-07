class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ans;
        set<int> used;
        vector<int> path;
        dfs(0, num, ans, path, used);
        return ans;
    }
private:
    void dfs(int d, vector<int>& num, vector<vector<int> >& ans, vector<int>& path, set<int>& used)
    {
        if(d == num.size()) {
            ans.push_back(path);
            return;
        }
        for(int n : num) {
            if(used.count(n)) continue;
            used.insert(n);
            path.push_back(n);
            dfs(d+1, num, ans, path, used);
            path.pop_back();
            used.erase(n);
        }
    }
};