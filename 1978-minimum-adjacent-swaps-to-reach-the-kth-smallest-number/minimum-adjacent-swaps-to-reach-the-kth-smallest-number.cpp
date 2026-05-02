class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target=num;
        int n=num.size();
        int ans=0;
        //Step 1: Kth permutation
        while(k--)
        {
            next_permutation(num.begin(),num.end());
        }

        //step2: count swaps

        for(int i=0;i<n;i++)
        {
            if(target[i]==num[i]) continue;

            int j=i;

            while(target[i]!=num[j]) j++;

            //Once i get to the point where it is matching

            while(j>i)
            {
                swap(num[j],num[j-1]);
                j--;
                ans++;
            }
        }

        return ans;
    }
};