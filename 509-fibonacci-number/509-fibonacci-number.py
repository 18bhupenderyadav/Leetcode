class Solution:
    def fib(self, n: int) -> int:
        
        if(n==0):
            return 0
        
        def f(n):
            if(n<=2):
                return 1
            return f(n-1)+f(n-2)
        
        return f(n)
        