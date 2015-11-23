/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // sort by start time
        std::sort(intervals.begin(), intervals.end(), [] (const Interval& a, const Interval& b) {return a.start < b.start;});
        
        vector<Interval> ans;
        
        for(const auto& i : intervals)
        {
            bool found = false;
            for(auto & j : ans)
            {
                if(this->intersect(j,i))
                {
                    this->merge(j, i);
                    found = true;
                    break;
                }
            }
            
            if(!found) ans.push_back(i);
        }
        
        return ans;
    }
    
private:
    
    bool intersect(const Interval& a, const Interval& b) {
        return a.end >= b.start;
    }
    
    void merge(Interval& a, const Interval& b) {
        a.end = std::max(a.end, b.end);
    }
};
