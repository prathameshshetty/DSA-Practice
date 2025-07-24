class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        //I will use max heap here
        priority_queue<int> pq;

        for(auto it:stones)
        {
            pq.push(it);
        }


        //now pop
        while(pq.size()>1)
        {
            int top1=pq.top();
            pq.pop();
            int top2=pq.top();
            pq.pop();

            if(top1==top2)
            {
                continue;   
            }
            else if(top1>top2)
            {
                pq.push(top1-top2);
            }
        }

        //is size if greater than 
        if(pq.size()==0) return 0;
        return pq.top();
    }
};