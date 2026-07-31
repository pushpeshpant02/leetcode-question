class Solution {
public:
    string shortestPalindrome(string s) {
           if (s.empty()) return s;
        string rev=s;
      reverse(rev.begin(),rev.end());
        string temp=s + "#" + rev;
        vector<int>lps(temp.size(),0);
       int i=1;
       int len=0;
       while(i<temp.size()){
            if(temp[i]==temp[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
       }
    int longest=lps.back();
    string remaining = s.substr(longest);
   reverse(remaining.begin(),remaining.end());
        return remaining+s;
    }
};