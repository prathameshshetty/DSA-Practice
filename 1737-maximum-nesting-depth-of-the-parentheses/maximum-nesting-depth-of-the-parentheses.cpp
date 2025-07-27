class Solution {
public:
    int maxDepth(string s) {
        int cnt=0;

        int maxi=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                cnt++;
                maxi=max(maxi,cnt);
            }
            else if(s[i]==')')
            {
                cnt--;
                if(cnt<0) cnt=0;
            }
        }
        return maxi;
    }
};