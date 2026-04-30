class Solution {
public:
    double findMaxAverage(vector<int>& a, int k) {
        double maxi = FLT_MIN;
        double sum = FLT_MIN;
        for(int i = 0; i < k ; i++)
            sum += a[i];
        
        maxi = sum;

        for(int i = k; i < a.size(); i++){
            sum += a[i];
            sum -= a[i- k];
            maxi = max(sum,maxi);
        }
        return maxi/k;
    }
};