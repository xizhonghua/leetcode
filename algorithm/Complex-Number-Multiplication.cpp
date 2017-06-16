class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int r1, i1, r2, i2;
        getComplexNumber(a, &r1, &i1);
        getComplexNumber(b, &r2, &i2);
        stringstream ss;
        ss<<(r1*r2-i1*i2)<<"+"<<(i1*r2+i2*r1)<<"i";
        return ss.str();
    }
    
    void getComplexNumber(const string& s, int* r, int* i) {
        stringstream ss(s);
        char c;
        ss>>*r>>c>>*i>>c;
    }
};
