class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>mp;
        int freq=0;
        int longest=0;
        int j=0;
        for(int i=0; i<s.size(); i++){
            mp[s[i]]++;
            freq=max(freq,mp[s[i]]);
            while((i-j+1)-freq>k){
                mp[s[j]]--;
                j++;
            }
            longest=max(longest,i-j+1);
        }
    return longest;
    }
};