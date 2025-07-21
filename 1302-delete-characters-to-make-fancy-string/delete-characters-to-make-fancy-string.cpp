class Solution {
public:
    string makeFancyString(string s) {
        int n=s.size();
        int l=0;
        string ans="";
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            int j=i;
            while(j<n && s[i]==s[j])
            {
                cnt++;
                j++;
            }

            if(cnt>=2)
            {
                ans+=s[i];
                ans+=s[i];
            }
           else
            
            ans+=s[i];
            i=j-1;
        }

        return ans;
        
    }
};