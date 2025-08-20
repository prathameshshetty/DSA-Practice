class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int ans=0;

        vector<vector<int>> dp(m,(vector<int>(n,0)));

        //first row and first col must be filled as it is

        //for first col
        for(int i=0;i<m;i++)
        {
            dp[i][0]=matrix[i][0];
            ans+=matrix[i][0];
        }

        //first row
        for(int i=1;i<n;i++)
        {
            dp[0][i]=matrix[0][i];
            ans+=matrix[0][i];
        }



        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    dp[i][j]=1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]});
                    ans+=dp[i][j];
                }
                else dp[i][j]=0;
            }
        }

        return ans;

    }
};