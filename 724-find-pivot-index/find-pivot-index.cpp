class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>leftsum(nums.size(),0);
        vector<int>rightsum(nums.size(),0);
        int sum=0;
        int i;
        for(i=0; i<nums.size(); i++){
            sum+=nums[i];
            leftsum[i]=sum;
        }
            sum=0;
         for(i=nums.size()-1; i>=0; i--){
            sum+=nums[i];
            rightsum[i]=sum;
        }
       for(int i=0; i<nums.size(); i++){
        if(leftsum[i] == rightsum[i]) {
        return i;
       }
       }
        return -1;
    }
};