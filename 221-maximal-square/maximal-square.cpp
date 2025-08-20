class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        //now its time for bottom up

        int m=matrix.size();
        int n=matrix[0].size();
        int ans=0;
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int num=matrix[i][j]=='0'?0:1;

                if(i==0 || j==0)
                {
                    
                    dp[i][j]=num;
                }
                else{
                    if(num==1)
                    {
                        dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                    }
                    else dp[i][j]=0;
                }

                ans=max(ans,dp[i][j]);
            }
        }

        return ans*ans;
    }
};