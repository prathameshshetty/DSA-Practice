class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();

        //put first k elements into the max heap
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i],i});
        }

        ans.push_back(pq.top().first);

        int l=0,r=k;

        while(r<n)
        {
            pq.push({nums[r],r});
            l++;

            while(!pq.empty() && l>pq.top().second ) pq.pop();
            r++;
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};