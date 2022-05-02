class Solution {
public:
    bool isPossible(vector<int>& target) {
        
        if(target.size()==1){
            return target[0]==1;
        }

        priority_queue<int>pq;
        
        long long int sum = 0;
        
        for(int i=0;i<target.size();i++){
            pq.push(target[i]);
            sum += 1ll*target[i];
        }
        
        while(pq.size()){
            
            long long int curr = 1ll*pq.top();
            pq.pop();
            
            //cout<<curr<<" "<<sum<<endl;
            
            if(curr<=1){
                break; 
            }
            
            long long int new_sum = sum-curr;
            
            if(new_sum>=curr){
                return 0;
            } 
            
            if(new_sum==1){
                pq.push(1);
                break;
            }
            curr = curr%new_sum;
            
            new_sum += curr;
            sum = new_sum;
            
            pq.push(curr);
            
            if(curr<1){
                break;
            }

        } 
        
        while(pq.size()){
            if(pq.top()!=1){
                return 0;
            }
            pq.pop();
        }
        
        return 1;
        
    }
};