class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) 
    {
        map<int,int>mp;
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        
        int cnt = arr.size()/2;
        for(auto &it : mp)
        {
            if(it.first>0)
            {
                if(mp[2*it.first]>=it.second)
                {
                    mp[2*it.first]-=it.second;
                    if(mp[2*it.first]==0)
                    {
                        mp.erase(2*it.first);
                    }
                    cnt--;
                }
                else
                {
                    return 0;
                }
            }
            else if(it.first<0)
            {
                if(abs(it.first)%2==1)
                {
                    return 0;
                }
                
                if(mp[it.first/2]>=it.second)
                {
                    mp[it.first/2]-=it.second;
                    if(mp[it.first/2]==0)
                    {
                        mp.erase(it.first/2);
                    }
                    cnt--;
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                if(it.second%2==1)
                {
                    return 0;
                }
            }
        }

       return 1;
    }
};