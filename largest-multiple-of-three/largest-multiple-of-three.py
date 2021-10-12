class Solution:
    def largestMultipleOfThree(self, di: List[int]) -> str:
        total=sum(di)
        
        if(total==0):
            return '0'
        
        rem=[[],[],[]]
        
        for i in range(0,len(di)):
            rem[(di[i]%3)].append(di[i])
            
        for i in range(0,3):
            rem[i].sort()
        
        if(total%3==1):
            
            if(len(rem[1])>=1):
                rem[1].pop(0)
            else:
                rem[2].pop(0)
                rem[2].pop(0)
        
        if(total%3==2):
            
            if(len(rem[2])>=1):
                rem[2].pop(0)
            else:
                rem[1].pop(0)
                rem[1].pop(0)
                
        ans=""
        
        for i in range(0,3):
            for j in range(0,len(rem[i])):
                ans=ans+str(rem[i][j])
        
        ans = ''.join(sorted(ans))
        ans = ans[::-1]
        
        sol=""
        
        flag=0
        pos=0
        for i in range(0,len(ans)):
            if(ans[i]!='0' and flag==0):
                flag=1
                pos=i
        
        for i in range(pos,len(ans)):
            sol+=ans[i]
        
        return sol
        