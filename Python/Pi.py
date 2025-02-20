import decimal
import sys
import math

#!/usr/bin/env python3

def compute_pi(digits):
    # Set precision: add extra digits for intermediate steps.
    decimal.getcontext().prec = digits + 10
    # Chudnovsky constants.
    C = 426880 * decimal.Decimal(10005).sqrt()
    
    # Estimated number of iterations needed.
    iterations = digits // 14 + 1

    M = decimal.Decimal(1)
    L = decimal.Decimal(13591409)
    X = decimal.Decimal(1)
    S = L

    for k in range(1, iterations):
        M = (M * (12*k - 5) * (12*k - 3) * (12*k - 1)) / (k*k*k * 640320**3)
        L += 545140134
        S += M * L

    pi = C / S
    return +pi  # Unary plus applies the precision

if __name__ == '__main__':
    # Accept the number of digits as a command-line argument; default is 50.
    try:
        digits = int(sys.argv[1]) if len(sys.argv) > 1 else 50
    except ValueError:
        print("Usage: python Pi.py [number_of_digits]")
        sys.exit(1)
    
    pi = compute_pi(digits)
    # Format output: include "3." and desired number of digits after decimal.
    pi_str = str(pi)[:digits+2]
    print(pi_str)