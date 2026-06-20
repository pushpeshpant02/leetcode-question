class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left=0, minlength=INT_MAX,sum=0,length=0;
        for(int right=0; right<nums.size(); right++){
            sum+=nums[right];
            while(sum>=target){
                length=right-left+1;
                sum=sum-nums[left];
                left++;
                 minlength=min(minlength,length);
            }
           }
     if(minlength==INT_MAX) return 0;
     else return minlength;
    }
};