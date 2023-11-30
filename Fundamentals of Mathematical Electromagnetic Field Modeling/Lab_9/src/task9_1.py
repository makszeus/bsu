import math

class TrigPoly:
    def __init__(self, coeffs):
        self.coeffs = coeffs

    def __str__(self):
        terms = ["{}*cos({}*x) + {}*sin({}*x)".format(a, i, b, i) for i, (a, b) in enumerate(self.coeffs)]
        return " + ".join(terms)

    def __add__(self, other):
        new_coeffs = [(a + c, b + d) for (a, b), (c, d) in zip(self.coeffs, other.coeffs)]
        return TrigPoly(new_coeffs)

    def __sub__(self, other):
        new_coeffs = [(a - c, b - d) for (a, b), (c, d) in zip(self.coeffs, other.coeffs)]
        return TrigPoly(new_coeffs)

    def value_at(self, x):
        return sum(a * math.cos(i * x) + b * math.sin(i * x) for i, (a, b) in enumerate(self.coeffs))

    def derivative(self):
        new_coeffs = [(i * b, -i * a) for i, (a, b) in enumerate(self.coeffs)]
        return TrigPoly(new_coeffs)

# Пример использования
p1 = TrigPoly([(1, 2), (3, 4)])
p2 = TrigPoly([(5, 6), (7, 8)])

print("p1:", p1)
print("p2:", p2)

p3 = p1 + p2
print("p1 + p2:", p3)

p4 = p1 - p2
print("p1 - p2:", p4)

print("p1 value at pi:", p1.value_at(math.pi))

p5 = p1.derivative()
print("derivative of p1:", p5)
