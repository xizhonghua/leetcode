class Solution {
public:
    int compareVersion(string version1, string version2) {
        auto v1 = this->parseVersion(version1);
        auto v2 = this->parseVersion(version2);
        auto s = max(v1.size(), v2.size());
        while(v1.size()<s) v1.push_back(0);
        while(v2.size()<s) v2.push_back(0);
        for(auto i=0;i<s;i++) {
            if(v1[i] < v2[i]) return -1;
            if(v1[i] > v2[i]) return 1;
        }
        return 0;
    }
private:
    vector<int> parseVersion(const string& version) {
        vector<int> v;
        istringstream iss(version);
        string token;
        while (std::getline(iss, token, '.')) {
            if (!token.empty())
            v.push_back(atoi(token.c_str()));
        }
        return v;
    }
};
