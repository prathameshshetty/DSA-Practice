class Solution {
public:
        vector<int> getBiggestThree(vector<vector<int>>& grid) {
            int m=grid.size();
            int n=grid[0].size();

            set<int> sums;

            for(int r=0;r<m;r++)
            {
                for(int c=0;c<n;c++)
                {
                    //size=0 of the rhombus

                    sums.insert(grid[r][c]);

                    //try larger rhombus size

                    for(int k=1;;k++)
                    {
                        if(r-k<0 || r+k>=m || c+k>=n || c-k<0) break;

                        int sum=0;

                        //top to right
                        for(int i=0;i<k;i++)
                        {
                            sum+=grid[r-k+i][c+i];
                        }

                        //right to bottom
                        for(int i=0;i<k;i++)
                        {
                         sum+=grid[r+i][c+k-i];   
                        }

                        //bottom to left
                        for(int i=0;i<k;i++)
                        {
                            sum+=grid[r+k-i][c-i];
                        }


                        //left to top
                        for(int i=0;i<k;i++)
                        {
                            sum+=grid[r-i][c-k+i];
                        }

                        sums.insert(sum);

                    }
                }
            }


            vector<int> res(sums.rbegin(),sums.rend());

            if(res.size()>3)
            {
                res.resize(3);
            }
            return res;
        }
};