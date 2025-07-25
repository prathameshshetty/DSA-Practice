class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        vector<pair<double,int>> ratio;


        for(int i=0;i<n;i++)
        {
            ratio.push_back({(double)wage[i]/quality[i],i});
        }

        //now i sort them based on thier ratio
        sort(ratio.begin(),ratio.end());

        //The main thing is cost=minRatioPossibleInK * totalqualityOfKgroup
        //Inorder to make the cost less, i got try making both of them less
        //First I try decreasing the minRationINKPossible
        //Then I try the totalQUalityless by replacing it with current K group
        priority_queue<int> maxHeap;
        int totalQuality=0;
        double maxRatio=0;
        for(int i=0;i<k;i++)
        {
            totalQuality+=quality[ratio[i].second];
            maxRatio=max(maxRatio,ratio[i].first);
            maxHeap.push(quality[ratio[i].second]);

        }

        double res=maxRatio*totalQuality;

        //now try by using raming k 
        for(int i=k;i<n;i++)
        {
            maxRatio=max(maxRatio,ratio[i].first);
            totalQuality-=maxHeap.top();
            maxHeap.pop();
            totalQuality+=quality[ratio[i].second];
            maxHeap.push(quality[ratio[i].second]);

            res=min(res,totalQuality*maxRatio);
        }

        return res;

        //Now i got the least ratio possibt
    }
};