class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0]
        for i in range(1,n+1):
            temp = str(bin(i))
            count=0
            for x in temp:
                if(x=="1"):
                    count+=1
            ans.append(count)
        
        return ans
        