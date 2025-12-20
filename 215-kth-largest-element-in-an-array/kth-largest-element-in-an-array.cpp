class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
       sort(nums.begin(),nums.end(),greater<int>());
       return nums[k-1];
    }
};