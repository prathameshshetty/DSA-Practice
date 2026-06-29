class Solution {
    public void generate(int i,ArrayList<Integer> row, List<List<Integer>> ans, int[] nums){
        if(i==nums.length){
            ans.add(new ArrayList<>(row));
            return;
        }
        row.add(nums[i]);
        generate(i+1,row,ans,nums);
        
        row.remove(row.size()-1);
        while(i+1<nums.length && nums[i]==nums[i+1]){
            i++;
        }
        generate(i+1,row,ans,nums);
    }
    public List<List<Integer>> subsetsWithDup(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        generate(0,new ArrayList<>(),ans,nums);
        return ans;
    }
}