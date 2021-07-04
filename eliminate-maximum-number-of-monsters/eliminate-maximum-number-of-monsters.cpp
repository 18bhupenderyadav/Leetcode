class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) 
    {
        vector<int>time(dist.size(),0);
        
        for(int i=0;i<dist.size();i++)
        {
            time[i] = (dist[i]+speed[i]-1)/speed[i];
        }
        
        sort(time.begin(),time.end()); 
        
        for(int i=1;i<time.size();i++)
        {
            if(i>=time[i])
            {
                return i;  
            }
        }
        
        return time.size();
    }
};
