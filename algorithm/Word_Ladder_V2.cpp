class Solution {

struct Node {
    string w;
    int l;
    Node() {}
    Node(string w, int l) : w(w), l(l) {}
};

public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<Node> q;
        unordered_set<string> used;
        
        q.push(Node(start,1));
        
        int l = start.length();
        
        while(!q.empty()) {
            auto node = q.front();
            q.pop();
            for(int i=0;i<l;i++)
            {
                for(int j='a';j<='z';j++)
                {
                    string t = node.w;
                    if(t[i] == j) continue;
                    t[i] = j;
                    if(t == end) return node.l+1;
                    if(!dict.count(t) || used.count(t)) continue;
                    used.insert(t);
                    q.push(Node(t, node.l+1));
                }
            }
            
        }
        
        return 0;
    }
};
