class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        
        //if there is only one guy in thtown
        if(n==1) return 1;

       

        vector<int> t(n+1,0);

        for(auto & it:trust)
        {
            t[it[0]]--;
            t[it[1]]++;
        }

        for(int i=0;i<=n;i++)
        {
            if(t[i]==n-1) return i;
        }
        return -1;
    }
};