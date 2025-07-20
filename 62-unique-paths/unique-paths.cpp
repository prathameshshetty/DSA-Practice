class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n,1);

        for(int i=1;i<m;i++)
        {
            vector<int> temp(n,0);

            for(int j=0;j<n;j++)
            {
                int up=0,left=0;
                //No need for an condiution since i can get up in evrytcase
                up=prev[j];
                if(j>0) left=temp[j-1];

                temp[j]=up+left;
            }

            prev=temp;
        }

        return prev[n-1];
    }
};