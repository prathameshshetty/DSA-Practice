class Solution {
public:
void CombSum(int ind,int target,vector<int>&candidates,vector<vector<int>>&ans,int& n,vector<int>&nums)
{
    //base case
    if(ind>=n || target==0)
    {
        if(target==0)
        {

            ans.push_back(nums);
        }
        return;
    }


    //generalcase
   if(candidates[ind]<=target){
        nums.push_back(candidates[ind]);
        CombSum(ind,target-candidates[ind],candidates,ans,n,nums);
        nums.pop_back();
       
    }

 CombSum(ind+1,target,candidates,ans,n,nums);
}
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>> ans;

        
        vector<int> nums;
        CombSum(0,target,candidates,ans,n,nums);
        // vector<vector<int>> ans1={ans.begin(),ans.end()};
        return ans;
    }
};