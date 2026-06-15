class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size()) return {};
        vector<int>pfreq(26,0);
        vector<int>windowfreq(26,0);
        vector<int>ans;
        for(int i=0; i<p.size(); i++){
            pfreq[p[i]-'a']++;
            windowfreq[s[i]-'a']++;  //frequency for first window
            }
            if(pfreq==windowfreq){
                ans.push_back(0);
            }
            for(int i=p.size(); i<s.size(); i++){  //as we have considered the first window 
                windowfreq[s[i]-'a']++;
                windowfreq[s[i-p.size()]-'a']--;
                if(pfreq==windowfreq){
                    ans.push_back(i-p.size()+1);
                }
            }
        return ans;
    }
};