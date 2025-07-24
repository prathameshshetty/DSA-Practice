class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int,vector<int>,greater<int>> pqFront;
         priority_queue<int,vector<int>,greater<int>> pqLast;

        int i=0;
        int j=costs.size()-1;
        long long ans=0;
        while(k--)
        {
            //First push all the front unitl size candidate

            while(pqFront.size()<candidates && i<=j)
            {
                pqFront.push(costs[i++]);
            }

            //Now push second untilsize candidate
            while(pqLast.size()<candidates && i<=j)
            {
                pqLast.push(costs[j--]);
            }

            int cost1=pqFront.size()>0 ? pqFront.top():INT_MAX;
            int cost2=pqLast.size()>0 ? pqLast.top():INT_MAX;

            if(cost1<=cost2)
            {
                ans+=cost1;
                pqFront.pop();
            }
            else{
                ans+=cost2;
                pqLast.pop();
            }
        }


        return ans;
    }
};