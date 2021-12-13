class Solution {
public:
    int sum(int st,int ed,vector<int>& ar)
    {
        if(st>0)
        {
            return ar[ed]-ar[st-1];
        }
        
        return ar[ed];
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int st, int k) 
    {
        int n=fruits.size();
        
        vector<int> ar(4*100000+5,0);
        
        for(int i=0;i<n;i++)
        {
            ar[fruits[i][0]]=fruits[i][1];
        }
        
        int cnt=0;
        
        for(int i=0;i<4*100000+5;i++)
        {
            cnt+=ar[i];
            ar[i]=cnt;
        }
        
        int ans=0;
        
        for(int i=st;i<=st+k;i++)
        {
            int temp=sum(st,i,ar);
            int left=(k-(i-st))/2;
            if(st-left<0)
                left=st;
            int temp2=sum(st-left,max(st-1,0),ar);
            int temp3=temp+temp2;
            if(i>0)
                temp3-=sum(i,i-1,ar);
            if(st==0)
                temp3-=temp2;
            ans=max(ans,temp3);
        }
        cout<<ans<<endl;

        for(int i=st;i>=max(0,st-k);i--)
        {
            int temp=sum(i,st,ar);
            int left=(k-(st-i))/2;
            int temp2=sum(st+1,st+left,ar);
            int temp3=temp+temp2;
            if(i>0)
                temp3-=sum(i,i-1,ar);
            ans=max(ans,temp3);
        }
        
        return ans;
    }
};

