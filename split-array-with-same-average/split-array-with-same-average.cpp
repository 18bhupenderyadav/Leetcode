class Solution {
public:
    
    
    // int memo[31][300001][31];
    
    unordered_map<string,int> mp;
    
    bool dp(int i,int n,int sum,int num,int tot,vector<int>& ar)
    {
        if(i>n)
            return false;
        
        if(i==n && num==n)
            return false;
        
        if(i==n)
        {
            if(num!=n && num!=0)
            {
                double a=sum/num;
                double b=(tot-sum)/num;
                int g1,g2;
                g1=__gcd(sum,num);
                g2=__gcd(tot-sum,n-num);
                if(sum/g1==(tot-sum)/g2 && num/g1==(n-num)/g2)
                    return true;
                else
                    return false;
            }
            else
                return false;
        }
        
        // if(memo[i][sum][num]!=-1)
        //     return memo[sum][num];
        
        string s=to_string(i)+'-'+to_string(sum)+'-'+to_string(num);
        if(mp.find(s)!=mp.end())
            return mp[s];
        
        return mp[s]=dp(i+1,n,sum+ar[i],num+1,tot,ar)||dp(i+1,n,sum,num,tot,ar);
        
    }
    
    bool splitArraySameAverage(vector<int>& A) 
    {
        int n = A.size(), m = n/2, totalSum = accumulate(A.begin(), A.end(), 0);
        bool isPossible = false;
        for (int i = 1; i <= A.size()/2 && !isPossible; ++i) 
            if (totalSum*i%n == 0) isPossible = true;
        if (!isPossible) return false;
        // int n=A.size();
        int tot=0;
        for(int i=0;i<n;i++)
            tot+=A[i];
        // memset(memo,-1,sizeof(memo));
        mp.clear();
        return dp(0,n,0,0,tot,A);

    }
};