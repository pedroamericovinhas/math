import math

def derivative(f, x, dx=1/2000):
    return (f(x + dx) - f(x))/dx  

print(derivative(lambda x: x**2 + 2*x, 3) # Derivative of f(x) = x^2 + 2x at x = 3
print(derivative(lambda x: math.exp(x), 1) # Derivative of e^x at x = 1
  
def integral(f, a, b, dx=1/2000):
    sum = 0
    for i in range(0,math.ceil((b-a)/dx) + 1):
        sum += f(a+(i*dx))
    return sum * (dx)

z = int(input())
print((2/(math.pi**0.5)) * integral(lambda x : exp(-x**2), 0, z)) # erf(z)
print(integral(lambda x : (x**(z-1)) * exp(-x), 0, 20)) # Γ(z)
