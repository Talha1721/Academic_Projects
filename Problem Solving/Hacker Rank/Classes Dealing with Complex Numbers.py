"""
import math
class Complex:

    def __init__(self, real, imaginary):
        self.real=real
        self.imaginary=imaginary


    def __add__(self, no):
        ar=self.real + no.real
        ai=self.imaginary+ no.real
        return Complex(ar,ai)

    def __sub__(self, no):
        sr=self.real - no.real
        si=self.imaginary- no.real
        return Complex(sr,si)
    def __mul__(self, no):
        a=self.real
        b=self.imaginary
        c=no.real
        d=no.real
        mr=(a*c)-(b*d)
        mi=(a*d)+(b*c)
        return Complex(mr,mi)
    def __div__(self, no):
        a=self.real
        b=self.imaginary
        c=no.real
        d=no.real
        x=a*a+b*b
        dr=((a*c) + (b*d))/(x)
        di=((a*d) - (b*c))/(x)
        return Complex(dr,di)
    def mod(self):
        a=self.real
        b=self.imaginary
        return Complex(math.sqrt(a**2+b**2),0)

    def __str__(self):
        if self.imaginary == 0:
            result = "%.2f+0.00i" % (self.real)
        elif self.real == 0:
            if self.imaginary >= 0:
                result = "0.00+%.2fi" % (self.imaginary)
            else:
                result = "0.00-%.2fi" % (abs(self.imaginary))
        elif self.imaginary > 0:
            result = "%.2f+%.2fi" % (self.real, self.imaginary)
        else:
            result = "%.2f-%.2fi" % (self.real, abs(self.imaginary))
        return result


if __name__ == '__main__':
    c = map(float, input().split())
    d = map(float, input().split())
    x = Complex(*c)
    y = Complex(*d)
   # print(x,y)
    print(x+y)
    print(x-y)
    print(x*y)
    print(x/y)
    print(x.mod())
    print(y.mod())






"""
import math
class Complex(object):
    def __init__(self, real, imaginary):
        self.real=real
        self.imaginary=imaginary

    def __add__(self, no):
        a = self.real
        b = self.imaginary
        c = no.real
        d = no.imaginary
        return Complex(a+c,b+d)

    def __sub__(self, no):
        a = self.real
        b = self.imaginary
        c = no.real
        d = no.imaginary
        return Complex(a-c,b-d)

    def __truediv__(self, no):
        a = self.real
        b = self.imaginary
        c = no.real
        d = no.imaginary
        real_numerator = a * c + b * d
        imag_numerator = b * c - a * d
        denom = c * c + d * d
        real_div = real_numerator/(denom)
        imag_div = imag_numerator/(denom)
        return Complex(real_div, imag_div)
    def __mul__(self, no):
        a = self.real
        b = self.imaginary
        c = no.real
        d = no.imaginary
        real_mult = (a * c) - (b * d)
        imag_mult = (a * d) + (b * c)
        return Complex(real_mult,imag_mult)

    def mod(self):
        a = self.real
        b = self.imaginary
        return Complex(math.sqrt(a**2+b**2),0)

    def __str__(self):
        if self.imaginary == 0:
            result = "%.2f+0.00i" % (self.real)
        elif self.real == 0:
            if self.imaginary >= 0:
                result = "0.00+%.2fi" % (self.imaginary)
            else:
                result = "0.00-%.2fi" % (abs(self.imaginary))
        elif self.imaginary > 0:
            result = "%.2f+%.2fi" % (self.real, self.imaginary)
        else:
            result = "%.2f-%.2fi" % (self.real, abs(self.imaginary))
        return result


if __name__ == '__main__':
    c = map(float, input().split())
    d = map(float, input().split())
    x = Complex(*c)
    y = Complex(*d)
    """
    print(str(x + y))
    print(str(x - y))
    print(str(x * y))
    print(str(x / y))
    print(str(x.mod()))
    print(str(y.mod()))
    """
    print(*map(str, [x + y, x - y, x * y, x / y, x.mod(), y.mod()]), sep='\n')
    """

    print(x+y)
    print(x-y)
    print(x*y)
    try:
        print(x / y)
    except Exception as e:
        print(e)
    finally:
        print(x.mod())
        print(y.mod())

   """