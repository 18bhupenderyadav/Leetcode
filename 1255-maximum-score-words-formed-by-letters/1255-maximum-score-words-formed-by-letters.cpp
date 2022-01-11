class Solution {
public:
    int f(vector<int>& index, vector<int>& freq, vector<int>& score, vector<string>& words)
    {
        int cnt = 0;
        vector<int> act(26,0);
        for(int i=0;i<index.size();i++)
        {
            for(int j=0;j<words[index[i]].size();j++)
            {
                act[words[index[i]][j]-'a']++;
            }
        }
        
        for(int i=0;i<26;i++)
        {
            if(act[i]>freq[i])
                return 0;
            cnt+=(score[i]*act[i]);
        }
        
        return cnt;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) 
    {
        int n = words.size(),ans=0;
        
        vector<int>freq(26,0);
        
        for(int i=0;i<letters.size();i++)
        {
            freq[letters[i]-'a']++;
        }
        
        for(int i=0;i<=(int)pow(2,n);i++)
        {
            vector<int>index;
            
            for(int j=0;j<words.size();j++)
            {
                if(((1<<j)&i)){
                    index.push_back(j);
                }
                
            }
            
            ans = max(ans,f(index,freq,score,words));
        }
        
        return ans;
    }
};