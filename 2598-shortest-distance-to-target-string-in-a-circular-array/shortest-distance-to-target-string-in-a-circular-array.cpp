class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n=words.size();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(words[i]==target)
            {
                //dist between two points in a cricle
                int distance=abs(startIndex-i);
                distance=min(distance,n-distance);
                ans=min(ans,distance);
            }
        }

        return ans==INT_MAX? -1:ans;
    }
};