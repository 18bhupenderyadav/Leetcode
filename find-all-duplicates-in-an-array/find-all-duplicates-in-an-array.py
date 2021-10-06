class Solution:
    def findDuplicates(self, ar: List[int]) -> List[int]:
        ans=[]
        for i in range(0,len(ar)):
            if(ar[abs(ar[i])-1]<0):
                ans.append(abs(ar[i]))
            index=abs(ar[i])-1
            ar[index]=-1*ar[index]

        return ans