class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if(n<=2) return n;
        
        int index = 1;
        int len = 1;
        int last = A[0];
        
        while(index<n)
        {
            int count = 1;
            
            while(A[index] == last && index < n)
            {
                count++;
                index++;
            }
            
            if(count>=2)
            {
                A[len++] = last;
            }
            
            if(index < n)
            {
                last = A[index++];
                A[len++] = last;
            }
        }
        
        return len;
    }
};