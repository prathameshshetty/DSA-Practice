class Solution {
public:
    long long countSubstrings(string s, char c) {
        long long cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++) if(s[i]==c) cnt++;

        return cnt*(cnt+1)/2;
    }
};