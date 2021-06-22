class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        long long int pos = 0;
        for(long long int i=1;i<=(long long)target*target;i++){
            pos+=i;
            if(pos==target){ 
                return i;
            }
            else if(pos>target && (pos-target)%2==0){
                return i;
            }
        }
        return 0;
    }
};