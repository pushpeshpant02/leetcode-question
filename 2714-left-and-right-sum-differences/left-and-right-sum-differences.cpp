class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int>left;
        vector<int>right;
        vector<int>ans;
        int n=nums.size();
        int sum=0;
        left.push_back(0);
        right.push_back(0);
        for(int i=n-1; i>0; i--){
            sum=sum+nums[i];
            right.push_back(sum);
            }
            reverse(right.begin(),right.end());
        sum=0;
         for(int i=0; i<n-1; i++){
            sum=sum+nums[i];
            left.push_back(sum);
        }
        for(int i = 0; i < n; i++) {
            ans.push_back(abs(left[i] - right[i]));
        }

        return ans;
        
    }
};