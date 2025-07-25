class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n=tasks.size();
       unordered_map<char,int> mpp;
        for(char &ch:tasks)
        {
            mpp[ch]++;
        }

        priority_queue<int> pq;//max heap
        //we want to process the tasks with highest frequencies
        //So we dont have to finish it in the last with p gaps

        int time=0;
        for(auto &it:mpp)
        {
            pq.push(it.second);
        }

        while(!pq.empty())
        {
            vector<int> temp;

            for(int i=1;i<=p+1;i++)
            {
                //first first p+1 tasks

                if(!pq.empty())
                {
                    temp.push_back(pq.top()-1);
                    pq.pop();
                }
            }

            for(auto& freq:temp)
            {
                if(freq>0)
                {
                    pq.push(freq);
                }
            }


            if(pq.empty())
            {
                time+=temp.size();
            }
            else{
                time+=(p+1);

                //as we finished p+1 tasks abovoe in the loop
            }
        }

        return time;

    }
};