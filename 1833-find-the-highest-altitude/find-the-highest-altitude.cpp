class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int caltitude = 0;
        int maxaltitude = 0;
        for(int i=0; i<gain.size(); i++){
            caltitude+=gain[i];
            maxaltitude=max(maxaltitude,caltitude);
        }
        return maxaltitude;
    }
};