class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False
        temp = ""
        for x in range(len(s)):
            temp = s[x:] + s[:x]
            print(temp)
            
            if temp==goal:
                return True
            else:
                temp = ""
            

        return False
        