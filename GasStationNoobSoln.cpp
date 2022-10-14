class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int ans = -1;
        for(int i = n;i<2*n;i++)
        {
            gas.push_back(gas[i-n]);
        }
        for(int j = n;j<2*n;j++)
        {
            cost.push_back(cost[j-n]);
        }
        for(int i = 0;i<n;i++)
        {   int tank = gas[i];
            int j = (i+1);
            int prev;
            if(i==0)
            {
                prev = n-1;
            }
            else
            {
                prev = i-1;
            }
            while((j%n)!=i)
            {   if(tank>=cost[j-1])
                 {  tank = tank-cost[j-1]+gas[j];
                    j = j+1;
                 }
                else
                {
                    break;
                }
            }
             if((j%n) == i&&tank>=cost[prev])
             {
                 ans = i;
                 break;
             }
        }
        return ans==-1?-1:ans;
    }
};
