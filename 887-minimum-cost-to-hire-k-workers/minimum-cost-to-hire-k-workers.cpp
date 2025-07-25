class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);

        vector<pair<double,int>> ratio;

        int n=quality.size();

        for(int i=0;i<n;i++)
        {
            ratio.push_back({(double)wage[i]/quality[i],i});
        }

        //now sort it
        sort(ratio.begin(),ratio.end());

        //use a priority queuw
        priority_queue<int> maxHeap;
        int qualitySum=0;
        double maxRate=0.0;

        for(int i=0;i<k;i++)
        {
            qualitySum+=quality[ratio[i].second];
            maxRate=max(maxRate,ratio[i].first);
            maxHeap.push(quality[ratio[i].second]);
        }

        double res=maxRate*qualitySum;

        for(int i=k;i<n;i++)
        {
            maxRate=max(maxRate,ratio[i].first);
            qualitySum-=maxHeap.top();
            maxHeap.pop();

            qualitySum+=quality[ratio[i].second];
            maxHeap.push(quality[ratio[i].second]);
            res=min(res,maxRate*qualitySum);
        }

        return res;
    }
};