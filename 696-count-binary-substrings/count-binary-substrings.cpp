class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevCnt=0,currCnt=1;
        int ans=0;
        int n=s.size();

        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                //now breaked the consecutivve part
                ans+=min(prevCnt,currCnt);
                prevCnt=currCnt;
                currCnt=1;
            }
            else currCnt++;
        }

        ans+=min(currCnt,prevCnt);
        return ans;
    }
};