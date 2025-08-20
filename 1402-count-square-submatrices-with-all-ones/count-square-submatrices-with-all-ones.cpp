class Solution {
public:
    int solve(int i,int j,vector<vector<int>>&matrix,vector<vector<int>>& dp)
    {
        int m=matrix.size();
        int n=matrix[0].size();
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(matrix[i][j]==0)  return 0;

        int right=solve(i,j+1,matrix,dp);
        int diag=solve(i+1,j+1,matrix,dp);
        int below=solve(i+1,j,matrix,dp);

        return dp[i][j]=1+min({right,diag,below});
    }



    int countSquares(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int res=0;

        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==1)
                {
                    res+=solve(i,j,matrix,dp);
                }
            }
        }


        return res;
    }
};