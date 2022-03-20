class Solution {
public:
    pair<int,int>cnt(string &floor, int l){
        
        int curr = 0;
        
        for(int i=0;i<l;i++){
            if(floor[i]=='1'){
                curr++;
            }
        }
        
        int i = 0 , j = l;
        int start = i , end = j-1, mx = curr;
        
        while(j<floor.size())
        {
            curr += floor[j]=='1';
            curr -= floor[i]=='1';
            i++;
            j++; 
            if(mx<curr){ 
                start = i;
                end = j-1;
                mx = curr;
            }
            
        } 
         
        
        return {start,end};
        
    }
    pair<int,int>cnt2(string &floor, int l){
        
        int curr = 0;
        
        for(int i=0;i<l;i++){
            if(floor[i]=='1'){
                curr++;
            }
        }
        
        int i = 0 , j = l;
        int start = i , end = j-1, mx = curr;
        
        while(j<floor.size())
        {
            curr += floor[j]=='1';
            curr -= floor[i]=='1';
            i++;
            j++; 
            if(mx<=curr){ 
                start = i;
                end = j-1;
                mx = curr;
            }
            
        } 
         
        
        return {start,end};
        
    }
    int solve(string& s,int t,int l)
    {
        int ans = 0;

        while(t--)
        {
            auto it = cnt(s,l);
            
            for(int i=it.first;i<=it.second;i++){
                s[i]='0';
            }
 
        }
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')
                ans ++;
        }

        return ans;
    }
    int solve2(string& s,int t,int l)
    {
        int ans = 0;

        while(t--)
        {
            auto it = cnt2(s,l);
            
            for(int i=it.first;i<=it.second;i++){
                s[i]='0';
            }
 
        }
        
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')
                ans ++;
        }

        return ans;
    }
    int minimumWhiteTiles(string floor, int t, int l) {
        
        string s=floor;
        
        return min(solve(floor,t,l),solve2(s,t,l));
        
    }
};