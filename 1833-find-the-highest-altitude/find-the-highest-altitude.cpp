class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>arr(gain.size()+1,0);
        int sum=0; int max=INT_MIN;
        int maxgain=INT_MIN;
        for(int i=0; i<gain.size(); i++){
            sum+=gain[i];
            arr[i+1]=sum;
        }
        for(int i=0; i<arr.size(); i++){
            if(arr[i]>max){
                max=arr[i];
            }
        }
        return max;
    }
};