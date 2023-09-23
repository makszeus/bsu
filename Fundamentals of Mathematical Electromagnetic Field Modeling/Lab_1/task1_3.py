def is_prime(num_r):
    if num_r <= 1:
        return False
    for i in range(2, int(num_r ** 0.5) + 1):
        if num_r % i == 0:
            return False
    return True

def is_equidistant_to_primes(num_r):
    if num_r <= 2:
        return False
    next_prime = num_r + 1
    while True:
        if is_prime(next_prime):
            break
        next_prime += 1
    prev_prime = num_r - 1
    while True:
        if is_prime(prev_prime):
            break
        prev_prime -= 1
    return num_r == (next_prime + prev_prime) / 2

num = int(input("Введите натуральное число: "))

if is_equidistant_to_primes(num):
    print("True")
else:
    print("False")
