class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        for(int i=0;i<citations.size();++i) {
            int h = citations.size() - i;
            if(citations[i]>=h) return h;
        }
        return 0;
    }
};
