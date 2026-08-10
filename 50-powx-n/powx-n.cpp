class Solution {
public:
    double Power(double x, long long n) {
        if (n==0) return 1;
        if (n==1) return x;
        if(n%2==0){
            return Power(x*x,n/2);
        }
        else{
            return x*Power(x,n-1);
        }
    }
    double myPow(double x,long long n){
        long long num = n;
        if(num<0){
            return(1/Power(x,-1*num));
        }
        return Power(x,num);
    }
};