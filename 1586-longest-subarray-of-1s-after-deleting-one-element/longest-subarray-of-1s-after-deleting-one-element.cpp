class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zerocount=0;
        int maxlength=0;
        int sum=0;
        int left=0;
        for(int right=0; right<nums.size(); right++){
            sum+=nums[right];
            if(nums[right]==0){
                zerocount++;
            }
            while(zerocount>1){
                if(nums[left]==0){
                    zerocount--;
                }
                sum-=nums[left];
                left++;
            }
            maxlength=max(maxlength,right-left);
        }
        return maxlength;
    }
};