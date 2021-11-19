class Solution {
public:
    bool static cmp(pair<string,pair<int,int>>& a,pair<string,pair<int,int>>& b)
    {
        return a.first.size()<b.first.size();
    }
    vector<string> maxNumOfSubstrings(string s) 
    {
        int n=s.size();
        vector<int> st(26,n+1),end(26,-1);
        
        for(int i=0;i<n;i++)
        {
            st[s[i]-'a']=min(st[s[i]-'a'],i);
            end[s[i]-'a']=max(end[s[i]-'a'],i);
        }
        
        vector<pair<string,pair<int,int>>> cand;
        
        for(int i=0;i<26;i++)
        {
            int beg=st[i];
            string temp="";
            int max_ending=end[i];
            
            int j=beg;
            int iscorrect=1;
            while(j<=max_ending && j<n)
            {
                if(st[s[j]-'a']<beg)
                {
                    iscorrect=0;
                    break;
                }
                if(!iscorrect)
                    break;
                
                temp+=s[j];
                max_ending=max(max_ending,end[s[j]-'a']);
                j++;
            }
            
            if(iscorrect && temp.size()>0)
            {
                cand.push_back({temp,{beg,max_ending}});
            }
        }
        
        sort(cand.begin(),cand.end(),cmp);
        
        vector<string> ans;
        vector<int> vis(n+1,0);
        
        for(auto& i:cand)
        {
            int can=0;
            for(int j=i.second.first;j<=i.second.second;j++)
            {
                if(vis[j])
                {
                    can=1;
                    break;
                }
            }
            
            if(!can)
            {
                ans.push_back(i.first);
                for(int j=i.second.first;j<=i.second.second;j++)
                {
                    vis[j]=1;
                }
            }
        }
        
        return ans;
    }
};