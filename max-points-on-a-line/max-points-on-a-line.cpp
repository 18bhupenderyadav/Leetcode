class Solution {
public:
    int maxPoints(vector<vector<int>>&c) {
       if(!c.size()){
        return 0;
    }
    
    int ans = 0;
    
    for(int i=0;i<c.size();i++){

        unordered_map<string,int>mp;
        int same = 0,vertical =0, cnt=0;

        for(int j=i+1;j<c.size();j++){
            int x = c[i][0] - c[j][0];
            int y = c[i][1] - c[j][1];
            int g = __gcd(abs(x),abs(y));
            if(x<0 && y<0){
                x*=-1;
                y*=-1;
            }
            else if(y<0){
                x*=-1;
                y*=-1;
            }
            if(x==0 && y==0){
                same++;
                continue;
            }
            else if(y==0){
                x=1;
            }
            else if(x==0){
                vertical++;
                continue;
            }
            else{
                x/=g;
                y/=g;
            }
            string temp = to_string(y);
            temp+='-';
            temp+= to_string(x);
            mp[temp]++;
            cnt = max(cnt,mp[temp]);
        }

        ans = max({ans,cnt+same+1,vertical+1});
    }
    
    return ans;
    }
};