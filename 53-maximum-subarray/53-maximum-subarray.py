class Solution:
    def maxSubArray(self, ar: List[int]) -> int:
        
        
        def mxcro(st,mid,ed):
            
            tot,lsum,rsum = 0,float(-inf),float(-inf)
            
            for i in range(mid,st-1,-1):
                tot+=ar[i]
                lsum = max(lsum,tot)
            
            tot = 0;
            
            for i in range(mid+1,ed+1):
                tot+=ar[i]
                rsum = max(rsum,tot)
    
            return max(lsum,max(rsum,lsum+rsum))
        
        def mxsub(st,ed):
            if st==ed:
                return ar[st]
            mid = (st+ed)//2
            return max(mxsub(st,mid),max(mxsub(mid+1,ed),mxcro(st,mid,ed)))
        
        return mxsub(0,len(ar)-1)
