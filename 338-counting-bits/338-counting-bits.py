class Solution:
    def countBits(self, n: int) -> List[int]:
        ans = [0]
        for i in range(1,n+1):
            temp = str(bin(i))
            # print(temp)
            temp2=temp.replace("0","")
            ans.append(len(temp2)-1)
        
        return ans
        