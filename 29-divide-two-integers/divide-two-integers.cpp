class Solution {
public:
    int divide(int dividend, int divisor) {
if(dividend==INT_MIN && divisor==-1) return INT_MAX;
if(dividend==INT_MIN && divisor==1) return INT_MIN;

        if(dividend==divisor) return 1;


        //Both are negative
        bool isPositive=(dividend<0 == divisor<0);
        long long int a= abs((long long)dividend);
        long long int b= abs((long long)divisor);

        long long int ans=0;

        while(a>=b)
        {
            int q=0;
            while(a> (b<<(q+1)))
            {
                q++;
            }

            ans+=(1<<q);
            a=a-(b<<q);
        }

        if(ans==(1<<31) and isPositive) return INT_MAX;
        return isPositive?ans:-ans;
    }
};