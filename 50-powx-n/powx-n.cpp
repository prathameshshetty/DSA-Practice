class Solution {
public:
    double myPow(double x, int nn) {
        double ans=1.0;
        bool isNegN=false;
        long long n=nn;
        if(n<0)
        {
            isNegN=true;
            n=(n*-1);
        }

        while(n>0)
        {
            if((n&1)==0)
            {
                x=x*x;
                n/=2;
            }
            else{
                ans*=x;
                n--;
            }
        }

        if(isNegN)
        {
            return 1/ans;
        }

        return ans;


    }
};