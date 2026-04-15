class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        int n=nums.size();
        vector<int> res(n);
        for(int i=n-1;i>=0;i--)
        {
            int s1=nums[left]*nums[left];
            int s2=nums[right]*nums[right];

            if(s2>s1)
            {
                res[i]=s2;
                right--;
            }
            else
            {
                res[i]=s1;
                left++;
            }
        }

        return res;
    }
};