class Solution {
public:
    int count=0;
        int start=0;
        void expand(string&s, int left, int right){
            while(left>=0 && right<s.size() && s[right]==s[left]){
                count++;
                start=left;
                left--;
                right++;
            }
        }
    int countSubstrings(string s) {
        for(int i=0; i<s.size(); i++){
        expand(s,i,i);
        expand(s,i,i+1);
        }
        return count;
    }
};