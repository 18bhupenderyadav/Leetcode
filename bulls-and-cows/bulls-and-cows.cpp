class Solution {
public:
    string getHint(string secret, string guess)
    {
        int bull = 0, cow = 0;
        vector<int> freq1(10,0), freq2(10,0);
        
        for(int i=0;i<secret.size();i++)
        {
             
            if(secret[i]==guess[i])
            {
                bull++;
            }
             
            freq1[secret[i]-'0']++;
            freq2[guess[i]-'0']++; 
                
        }
        
        for(int i=0;i<=9;i++)
        {
            cow += min(freq1[i],freq2[i]);
        }
        
        cow-=bull;
        
        string ans = to_string(bull) + "A" + to_string(cow) + "B";
        return ans;       
    }
};