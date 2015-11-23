class Solution {
public:
    string intToRoman(int num) {
        map<int, string> m;
        vector<int> v = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        m[1000] = "M";
        m[900] = "CM";
        m[500] = "D";
        m[400] = "CD";
        m[100] = "C";
        m[90] = "XC";
        m[50] = "L";
        m[40] = "XL";
        m[10] = "X";
        m[9] = "IX";
        m[5] = "V";
        m[4] = "IV";
        m[1] = "I";
        
        string r;
        
        int index = 0;
        while(num)
        {
            if(num >= v[index])
            {
                num -= v[index];
                r += m[v[index]];
            }
            else
            {
                index++;
            }
        }
        
        return r;
    }
};
