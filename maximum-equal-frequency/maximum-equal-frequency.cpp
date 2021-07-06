class Solution { 
public:
    int maxEqualFreq(vector<int>& nums) 
    {
        
        unordered_map<int,int>mp;
        map<int,int>f;
        
        int n = nums.size();
        int ans = 1;
        
        for(int i=0;i<n;i++)
        {
            
            if(mp.find(nums[i])!=mp.end() && f[mp[nums[i]]])
            {
                
                f[mp[nums[i]]]--;
                
                if(f[mp[nums[i]]]==0)
                {
                    f.erase(mp[nums[i]]);
                }
            }
            
            mp[nums[i]]++;
            f[mp[nums[i]]]++;
            
            if(f.size()>2)
            {
                continue;
            }
            
            auto st = f.begin(); 
            int mn = st->first;
            
            auto end = f.rbegin();
            int mx = end->first;
            
            
            if(mn==1 && f[mn]==1)
            { 
                ans = i+1;
            }
            if(mp.size()==1)
            {
                ans = i+1;
            }
            if(mn==mx && mx==1 && f[mn]!=1)
            {
                ans = i+1;
            } 
            if(mx-mn==1 && f[mx]==1)
            {
                ans = i+1;
            }
        }
        
        return ans;
    }
};

// maintain the frequency of each element in mp
// also maintain the count of different frequencies till now in f
// will it not be in the start of mp? and rbegin haan i think
// if size of map>2 , this prefix cannot be the answer 
// if min==1 and f[min]=1 , update ans
// if mp.size()==1 , update ans
// if min==max==1 and f[min]!=1 , update ans
// if max-min = 1 and f[max] = 1 , update ans