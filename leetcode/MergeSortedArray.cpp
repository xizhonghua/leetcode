class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> v;
        for(int i=0;i<m;i++)
            v.push_back(A[i]);
            
        for(int i=0;i<n;i++)
            v.push_back(B[i]);
            
        sort(v.begin(), v.end());
        
        for(int i=0;i<v.size();i++)
            A[i] = v[i];
    }
};