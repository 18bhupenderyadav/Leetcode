class Solution {
public:
    string nearestPalindromic(string num) 
    {
        long long int ans=INT_MAX;
        long long int diff=INT_MAX;
        int n=num.length();
        long long int val=stoll(num);
        
        if(val<10)
            return to_string(val-1);
        
        auto cand = [&](long long int h)
        {
            string ans="";
            ans+=to_string(h);
            string temp=to_string(h);
            reverse(temp.begin(),temp.end());
            ans+=temp;
            return stoll(ans);
        };
        
        auto odcand = [&](long long int h,char c)
        {
            string ans="";
            ans+=to_string(h);
            string temp=to_string(h);
            reverse(temp.begin(),temp.end());
            ans+=c;
            ans+=temp;
            return stoll(ans);
        };
        
        if(n%2==0)
        {
            string half="";
            for(int i=0;i<n/2;i++)
            {
                half+=num[i];
            }
            
            long long int h=stoll(half);
            
            long long int c1=cand(h);
            
            if(abs(val-c1)<diff && c1!=val)
            {
                diff=abs(val-c1);
                ans=c1;
            }
            if(abs(val-c1)==diff && c1!=val)
            {
                ans=c1;
            }
            
            long long int c2=cand(h+1);
            
            if(abs(val-c2)<diff && c2!=val)
            {
                diff=abs(val-c2);
                ans=c2;
            }
            if(abs(val-c2)==diff && c2!=val)
            {
                ans=min(c2,ans);
            }
            
            long long int c3=cand(h-1);
            
            if(abs(val-c3)<diff && c3!=val)
            {
                diff=abs(val-c3);
                ans=c3;
            }
            if(abs(val-c3)==diff && c3!=val)
            {
                ans=min(ans,c3);
            }
            
        }
        else
        {
            string half="";
            for(int i=0;i<n/2;i++)
            {
                half+=num[i];
            }
            
            long long int h=stoll(half);
            
            long long int c1=odcand(h,num[n/2]);
            
            if(abs(val-c1)<diff && c1!=val)
            {
                diff=abs(val-c1);
                ans=c1;
            }
            if(abs(val-c1)==diff && c1!=val)
            {
                ans=c1;
            }
            
            long long int c2=odcand(h+1,num[n/2]);
            
            if(abs(val-c2)<diff && c2!=val)
            {
                diff=abs(val-c2);
                ans=c2;
            }
            if(abs(val-c2)==diff && c2!=val)
            {
                ans=min(ans,c2);
            }
            
            long long int c3=odcand(h-1,num[n/2]);
            
            if(abs(val-c3)<diff && c3!=val)
            {
                diff=abs(val-c3);
                ans=c3;
            }
            if(abs(val-c3)==diff && c3!=val)
            {
                ans=min(ans,c3);
            }
            
            int ch=num[n/2]-'0';
            
            if(ch!=9)
            {
                int tch=ch;
                tch++;
                long long int c5=odcand(h,char('0'+tch));

                if(abs(val-c5)<diff && c5!=val)
                {
                    diff=abs(val-c5);
                    ans=c5;
                }
                if(abs(val-c5)==diff && c5!=val)
                {
                    ans=min(ans,c5);
                }
            }
            
            if(ch!=0)
            {
                int tch=ch;
                tch--;
                long long int c4=odcand(h,char('0'+tch));

                if(abs(val-c4)<diff && c4!=val)
                {
                    diff=abs(val-c4);
                    ans=c4;
                }
                if(abs(val-c4)==diff && c4!=val)
                {
                    ans=min(ans,c4);
                }
            }
            
        }
        
        
        long long int a,b;
        a=pow(10,n);
        b=pow(10,n-1);
        a++;
        b--;

        if(abs(val-a)<diff && a!=val)
        {
            diff=abs(val-a);
            ans=a;
        }
        if(abs(val-a)==diff && a!=val)
        {
            ans=min(ans,a);
        }
        
        if(abs(val-b)<diff && b!=val)
        {
            diff=abs(val-b);
            ans=b;
        }

        if(abs(val-b)==diff && b!=val)
        {
            ans=min(ans,b);
        }
        
        return to_string(ans);
    }
};
// 12321