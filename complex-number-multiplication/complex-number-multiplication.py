class Solution:
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        Complex = namedtuple('Complex',['real','imag'])
        def parseImaginary(s):
            real,img=s.split("+")
            real=int(real)
            img=int(img[:-1])
            
            return Complex(real,img)
        
        i1 = parseImaginary(num1)
        i2 = parseImaginary(num2)
        
        def toString(c):
            return f"{c.real}+{c.imag}i"
        
        ans = Complex((i1.real * i2.real) - (i1.imag * i2.imag),
                     i1.real * i2.imag + i1.imag * i2.real)
        
        return toString(ans)
        