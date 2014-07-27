/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if(points.empty()) return 0;
        
        int mp = 0;
        int s = points.size();
        const double v = 1e99;
        const double self = 2e99;
        for(int i=0;i<s;i++)
        {
            map<double, int> ks;
            int sp = 0;
            ks[self]=0;
            for(int j=0;j<s;j++)
            {
                if(i==j) continue;
                
                auto& pi = points[i];
                auto& pj = points[j];
                
                if(pi.x == pj.x && pi.y == pj.y)
                {
                   sp++;
                   continue;
                }
                
                int dx = pj.x - pi.x;
                int dy = pj.y - pi.y;
                
                double k = 0;
                
                if(dy == 0) k = v;
                else k = double(dy)/dx;
                
                ks[k]++;
            }
            
            for(auto kv : ks)
                if(kv.second + sp > mp) mp = kv.second + sp;
        }
        
        return mp+1;
    }
};
