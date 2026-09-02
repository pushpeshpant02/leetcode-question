class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int j = 0;
    int count = 1;

    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] == nums[j])
            count++;
        else
            count--;

        if(count == 0) {
            j = i;
            count = 1;
        }
    }

    return nums[j];
}
};