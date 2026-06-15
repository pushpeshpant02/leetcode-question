class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         if(s2.size() < s1.size()) return {}; 
        vector<int> s1freq(26,0);
        vector<int> windowfreq(26,0);

        for(int i=0; i<s1.size(); i++){
            s1freq[s1[i]-'a']++;
            windowfreq[s2[i]-'a']++;
        }

        if(s1freq == windowfreq){
            return true;
        }

        for(int i=s1.size(); i<s2.size(); i++){
            windowfreq[s2[i]-'a']++;                     
            windowfreq[s2[i - s1.size()]-'a']--;         

            if(s1freq == windowfreq){
             return true;
            }
        }
        return false;
      
  
    }
};