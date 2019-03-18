import numpy as np
import matplotlib.pyplot as plt

a = []
b = []
c = []
d = []
e = []
f = []

file = open("coefficients.txt")
for line in file:
    data = line.split()
    a.append(float(data[0]))
    b.append(float(data[1]))
    c.append(float(data[2]))
    d.append(float(data[3]))
    e.append(float(data[4]))
    f.append(float(data[5]))
file.close()


x = np.linspace(-1, 1, 10, endpoint = True)
y = (a * (x * x * x * x * x)) + (b * (x * x * x * x)) + (c * (x * x * x)) + (d * (x * x)) + (e * (x)) + f

plt.plot(x, y, '-g', label=r'$y = '+ data[0] + 'x^5 + ' + data[1] + ' x^4 + ' + data[2] + 'x^3 + ' + data[3] + ' x^2 + '
                           + data[4] + ' x + $' + data[5])
plt.xlabel('x')
plt.ylabel('y')
plt.title('Polynomial Curve')
plt.legend(loc='lower left')


x = []
y = []
file = open("data_positive.txt")
for line in file:
    data = line.split()
    x.append(float(data[0]))
    y.append(float(data[1]))
file.close()

plt.plot(x, y, 'ro', color='red')

x = []
y = []
file = open("data_negative.txt")
for line in file:
    data = line.split()
    x.append(float(data[0]))
    y.append(float(data[1]))
file.close()

plt.plot(x, y, 'ro', color='blue')

plt.axis([-1, 1, -1, 1])
plt.show()