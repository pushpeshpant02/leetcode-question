class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>ans;
        int start=intervals[0][0];
        int end=intervals[0][1];
        for(int i=1; i<intervals.size(); i++){
           int nextstart=intervals[i][0];
           int nextend=intervals[i][1];
           if(end>=nextstart){
            end=max(end,nextend);
           }
           else{
            ans.push_back({start,end});
            start=nextstart;
            end=nextend;
           }
        }
        ans.push_back({start,end});
        return ans;
    }
};