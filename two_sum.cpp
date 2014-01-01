class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> answer;
        
        int size = numbers.size();
        for(int i=0;i<size;i++)
        {
            for(int j=i+1;j<size;j++)
            {
                if(numbers[i] + numbers[j] == target)
                {
                    answer.push_back(i+1);
                    answer.push_back(j+1);
                    return answer;
                }
            }
        }
        
    }
};