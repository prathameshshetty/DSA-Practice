class Solution {

    private void backtrack(int ind, int []nums,List<Integer> tempArr,List<List<Integer>> ans)
    {
        //base case
        if(ind==nums.length)
        {
            ans.add(new ArrayList<>(tempArr));
            return;
        }


        //Take that element
        tempArr.add(nums[ind]);
        backtrack(ind+1,nums,tempArr,ans);

        //Not take element
        tempArr.remove(tempArr.size()-1);
        backtrack(ind+1,nums,tempArr,ans);

    }


    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans=new ArrayList<>();

        backtrack(0,nums,new ArrayList<>(),ans );

        return ans;
    }
}