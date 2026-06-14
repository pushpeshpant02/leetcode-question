class Solution {
public:
    bool checkGoodInteger(int n) {
        int digitsum=0;
        int squaresum=0;
        int digit=0;
        while(n>0){
            digit=n%10;
            n=n/10;
            digitsum+=digit;
            squaresum+=digit*digit;
            }
            if(squaresum-digitsum>=50){
                return true;
            }
            return false;
    }
};