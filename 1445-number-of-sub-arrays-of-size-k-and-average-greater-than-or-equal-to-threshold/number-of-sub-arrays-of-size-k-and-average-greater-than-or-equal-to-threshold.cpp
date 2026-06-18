class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count=0,sum=0;
        for(int right=0; right<arr.size(); right++){
            sum+=arr[right];
            if(right>=k-1){
                double average=0;
                average=(double)sum/k;
                if(average>=threshold){
                    count++;
                }
                int left=right-k+1;
                sum-=arr[left];
            }
        }
        return count;
    }
};