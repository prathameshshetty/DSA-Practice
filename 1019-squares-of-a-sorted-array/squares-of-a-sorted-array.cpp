class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);

        int l=0,r=n-1;
        int i=n-1;
        while(l<=r)
        {
            int lSquare=nums[l]*nums[l];
            int rSquare=nums[r]*nums[r];

            if(lSquare>rSquare)
            {
                 ans[i--]=lSquare;
                 l++;
            }
            else{
                    ans[i--]=rSquare;
                    r--;
            }
        }

        return ans;
    }
};