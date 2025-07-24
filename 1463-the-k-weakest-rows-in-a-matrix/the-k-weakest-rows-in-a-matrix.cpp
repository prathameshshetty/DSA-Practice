class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
       
        vector<pair<int,int>> prs;

        int n=mat.size();
        int m=mat[0].size();


        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]==1) cnt++;
                else break;
            }

            prs.push_back({cnt,i});
        }


        sort(prs.begin(),prs.end(),[](pair<int,int> a,pair<int,int> b)
        {
            if(a.first!=b.first) 
            {
                return a.first<b.first;
            }
           return a.second<b.second;
           
                 

            
           

          
        });


        vector<int> ans;

        for(int i=0;i<k;i++)
        {
            ans.push_back(prs[i].second);
        }
        return ans;
    }
};