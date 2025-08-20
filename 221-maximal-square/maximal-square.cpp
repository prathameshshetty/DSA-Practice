class Solution {
public:
    int solve(int i,int j,vector<vector<char>>&matrix,vector<vector<int>>& dp)
    {
        int m=matrix.size();
        int n=matrix[0].size();

        if(i>=m || j>=n)
        {
            return 0;
        }
        if(matrix[i][j]=='0') return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        //now chec in all the remaining 3 directiosn
        int right=solve(i,j+1,matrix,dp);
        int diag=solve(i+1,j+1,matrix,dp);
        int down=solve(i+1,j,matrix,dp);

        return dp[i][j]=1+min({right,diag,down});
    }



    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int res=0;

        vector<vector<int>> dp(m,vector<int>(n,-1));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    res=max(res,solve(i,j,matrix,dp));
                }
            }
        }

        return res*res;
    }
};