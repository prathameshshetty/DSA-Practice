class Solution {
public:

   void merge(int l,int mid,int h,vector<int>&arr)
    {
    int i=l;
    int j=mid+1;
   
    vector<int> temp;

    while(i<=mid && j<=h)
    {
        if(arr[i]<=arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }


    while(i<=mid)
    {
        temp.push_back(arr[i++]);
    }

    while(j<=h)
    {
        temp.push_back(arr[j++]);
    }


    
    

for(int k=l;k<=h;k++)
{
    arr[k]=temp[k-l];
}


    }
int cntPairs(int low,int mid,int high,vector<int>&arr)
{
    int cnt=0;int right=mid+1;
    for(int i=low;i<=mid;i++)
    {
        while(right<=high && arr[i]>2*(long long)arr[right]) right++;
        cnt+=(right-(mid+1));
    }

    return cnt;
}

    int mergeSort(int l,int h,vector<int>&arr)
    {
        int cnt=0;

        if(l<h)
        {
            int mid=l+(h-l)/2;

            cnt+=mergeSort(l,mid,arr);
            cnt+=mergeSort(mid+1,h,arr);
            cnt+=cntPairs(l,mid,h,arr);
            merge(l,mid,h,arr);
        }
        return cnt;

    }
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        return mergeSort(0,n-1,nums);
    }
};