class Solution { 
public:
    vector<int> findAnagrams(string s, string p) {
        
        if(p.size()>s.size()){
            return {};
        }
        
        vector<int>ans;
        
        vector<int>freq(26,0);
        vector<int>vis(26,0);
        
        for(char c:p){
            freq[c-'a']++;
        }
        
        
        int n = s.size();
        
        for(int i=0;i<p.size();i++){
            vis[s[i]-'a']++;
        }
        
        int i = 0, j = p.size()-1;
        while(j<n){
            if(freq==vis){
                ans.push_back(i);
            }
            vis[s[i]-'a']--;
            i++;
            j++;
            if(j<n){
                vis[s[j]-'a']++;
            }
            
        }
        return ans;
    }
};