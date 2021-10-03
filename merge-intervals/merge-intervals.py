class Solution:
    def merge(self, ar: List[List[int]]) -> List[List[int]]:
        
        def cmp_sort(ar:List[List[int]]):
            ar.sort(key = lambda x: (x[0],x[1]))
            
            return ar
        
        ar=cmp_sort(ar)
        
        ans = []
        
        st=ar[0][0]
        end=ar[0][1]
        
        for i in range(1,len(ar)):
            print(ar[i])
        
        for i in range(1,len(ar)):
            if(ar[i][0]<=end):
                end=max(end,ar[i][1])
            else:
                ans.append([st,end])
                st=ar[i][0]
                end=ar[i][1]
        
        ans.append([st,end])
        
        return ans
