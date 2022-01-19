class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        
        int i = k, j = k, mn = nums[k];
        int ans = mn;
        
        while(i>0 && j<nums.size()-1){
            
            int next = max(nums[j+1],nums[i-1]);
            if(next==nums[i-1]){
                i--;
            }
            else{
                j++;
            }
            mn = min({mn,next});
            ans = max(ans,mn*(j-i+1));
        }
        
        while(i>0){
            
            int next = nums[i-1];
            mn = min({mn,next});
            i--;
            ans = max(ans,mn*(j-i+1));
            
        }
        
        while(j<nums.size()-1){
            
            int next = nums[j+1];
            mn = min({mn,next});
            j++; 
            ans = max(ans,mn*(j-i+1));
        }
        
        return ans;
    }
};