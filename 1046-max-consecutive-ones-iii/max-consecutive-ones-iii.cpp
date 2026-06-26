class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlength=0;
        int sum=0;
        int zerocount=0;
        int left=0;
        for(int right=0; right<nums.size(); right++){
          sum+=nums[right];
          if(nums[right]==0){
            zerocount++;
          }
          while(zerocount>k){
            if(nums[left]==0){
               zerocount--;
            }
            sum-=nums[left];
            left++;
          }
           maxlength=max(maxlength,right-left+1);
          
    }
    return maxlength;
    }
};