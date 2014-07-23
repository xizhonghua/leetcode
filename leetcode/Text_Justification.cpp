
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        size_t i = 0, n = words.size();
        vector<string> ans;
        while(i < n)
        {
            bool last_line = false;
            int ll = 0;
            vector<string> tw;
            while(ll <= L && i < n)
            {
                size_t wl = words[i].length();
                int tll = ll + (tw.size() == 0 ? 0 : 1) + wl;
                if (tll > L) break;
                ll = tll;
                tw.push_back(words[i]);
                if (++i==n) last_line=true;
                if (ll == L) break;
            }
            
            string line;
            
            if(!last_line)
            {
                int tl = 0; 
                for(auto& w : tw) tl += w.length();
                int avg_space = tw.size()==1 ? 0 : ((L-tl) / (tw.size() - 1));
                int extra_space = tw.size()==1 ? 0 : (L - avg_space * (tw.size() - 1) - tl);

                for(auto& w : tw)
                {
                    if (line.length() > 0)
                    {
                        line += string(avg_space, ' ');
                        if(extra_space>0) { line += ' '; extra_space--; }
                    }
                    
                    line += w;
                }
            }
            else
            {
                for(auto& w : tw)
                {
                    if (line.length() > 0)
                        line += ' ';
                    line += w;
                }
            }
            
            line += string(L-line.length(), ' ');
            
            ans.push_back(line);
        }
        
        return ans;
    }
};
