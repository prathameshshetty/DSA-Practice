class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {

        //MaxValue of the current window
        int maxVal=INT_MIN;

        //Minheap priorirty queue for {val,row,col}
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;


        int k=nums.size();

        //Put first element of each of the list
        for(int i=0;i<k;i++)
        {
            maxVal=max(maxVal,nums[i][0]);
            minHeap.push({nums[i][0],i,0});
        }

        //Range of our window
        int min_L=0; //start of our range
        int max_R=INT_MAX; //end of our range


        //Process until one of the list is finished
        while(1)
        {
            auto curr=minHeap.top();
            minHeap.pop();

            int r=curr[1];
            int c=curr[2];
            int currVal=curr[0];

            if(max_R-min_L>maxVal-currVal)
            {
                min_L=currVal;
                max_R=maxVal;
            }

            //push next item of list if possible
            if(c+1<nums[r].size())
            {
                minHeap.push({nums[r][c+1],r,c+1});
                maxVal=max(maxVal,nums[r][c+1]);
            }
            else break;
        }

        return {min_L,max_R};


    }
};