class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mpp;

        int n=s.size();
        int l=0,r=0;
        int ans=0;

        while(r<n)
        {
            if(mpp.find(s[r])!=mpp.end() && mpp[s[r]]>=l)
            {
                l=mpp[s[r]]+1;
            }
            mpp[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
        }

        return ans;
    }
};