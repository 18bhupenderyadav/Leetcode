class Solution:
    def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
        
        # @lru_cache()
        memo={}
        def dp(pos):
            
            if(pos>=len(rides)):
                return 0
            if(pos in memo):
                return memo[pos]
            
            ans=dp(pos+1)
            
            l=pos
            r=len(rides)
            while(l<r):
                mid=(l+r)//2
                if(rides[mid][0]>=rides[pos][1]):
                    r=mid
                else:
                    l=mid+1
            
            ans=max(ans,rides[pos][1]-rides[pos][0]+rides[pos][2])
            ans=max(ans,rides[pos][1]-rides[pos][0]+rides[pos][2] + dp(r))
        
            memo[pos]=ans
            return ans
        
        rides.sort(key = lambda x: (x[0], x[1]* -1, x[2]))
        return dp(0)
        

# class Solution:
#     def maxTaxiEarnings(self, n: int, rides: List[List[int]]) -> int:
#         dp={}
#         rides.sort(key=lambda x:x[0]) #sorting based on start points
#         def recurse(i):
#             if(i>=len(rides)):return 0 #no other taxi rides left
#             if(i in dp):return dp[i]
#             x=recurse(i+1) #not considering i'th ride
#             #binary searching for the value in right of i to find the next ride
#             l=i
#             r=len(rides)
#             while(l<r):
#                 mid=(l+r)//2
#                 if(rides[mid][0]>=rides[i][1]):
#                     r=mid
#                 else:
#                     l=mid+1
#             x=max(x,rides[i][1]-rides[i][0]+rides[i][2]) #considering i as last element
#             x=max(x,recurse(r)+rides[i][1]-rides[i][0]+rides[i][2]) #considering i and next ride
#             dp[i]=x
#             return x
#         return recurse(0)