class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
          vector<int>lps(n,0);
    int len=0;
    int i=1;
    while(i<s.size()){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }
        else {
            if(len!=0){
            len=lps[len-1];
        }
        else{
            lps[i]=0;
            i++;
        }
    }
    }
        int longest=lps[n-1];
        int pattern=n-longest;
    
    return(longest>0&&n%pattern==0);
    }
};