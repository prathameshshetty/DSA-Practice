class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();

        int profit=0;
        int maxi=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            profit=max(profit,maxi-prices[i]);
            maxi=max(maxi,prices[i]);
        }

        return profit;
    }
};