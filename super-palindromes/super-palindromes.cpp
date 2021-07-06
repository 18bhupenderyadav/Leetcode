class Solution {
public:
    bool ispal(long long int x)
    {
        string temp = to_string(x);
        string curr = temp;
        reverse(curr.begin(),curr.end());
        return temp==curr;
    }
    
    bool check(long long int x)
    {
        return ispal(x*x);
    }
    
    long long int eve(long long int x)
    {
        string temp = to_string(x);
        string curr = temp;
        reverse(curr.begin(),curr.end());
        return stoll(temp+curr);
    }
    
    long long int oddo(long long int x)
    {
        string temp = to_string(x);
        string curr = temp;
        curr.pop_back();
        reverse(curr.begin(),curr.end());
        return stoll(temp+curr);
    }
    
    long long int cnt(long long int x)
    {
        set<long long int>s;
        for(long long int i=1;;i++)
        {
            long long int even = eve(i), odd = oddo(i);
        
            if(even>sqrt(x) && odd>sqrt(x))
            {
                break;
            }
            
            if(even<=sqrt(x) && ispal(even) && ispal(even*even) && even*even<=x)
            {
                s.insert(even*even); 
            }
            
            if(odd<=sqrt(x) && ispal(odd) && ispal(odd*odd) && odd*odd<=x)
            {
                s.insert(odd*odd);
            }
            
            if(i<=sqrt(x) && ispal(i) && ispal(i*i) && i*i<=x)
            {
                s.insert(i*i);
            }
        }
        
        return s.size();
    }
    int superpalindromesInRange(string left, string right) 
    {
        return cnt(stoll(right)) - cnt(stoll(left)-1);    
    }
};

// 10^16 -> 10^8 so half so 9999__  

// 21 -> 2112 , 212