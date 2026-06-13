class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
       string res="";
        for(string word:words){
            int totalweight=0;
            for(char ch:word){
                totalweight+=weights[ch-'a'];
            }
            int rem=totalweight % 26;
            char mapped= 'z'-rem;
            res+=mapped;
        }
        return res;
    }
};