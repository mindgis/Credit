from cs50 import get_int
import math

# Get number
while True:
    number = get_int("Number: ")
    if number > 99999999 and number < 10000000000000000:
        break

# Calculate length
length = int(math.log10(number))+1

# Define variables
sum1 = 0
sum2 = 0
number1 = number
number2 = number // 10

# Calculate sums
for i in range(length):
    # Sum of 1st Numbers
    sum1 = number1 % 10 + sum1
    number1 = number1 // 100
    # Sum of 2nd Numbers
    LastDigit2 = number2 % 10
    if LastDigit2 * 2 > 9:
        sum2 = (LastDigit2 * 2 // 10) + (LastDigit2 * 2 % 10) + sum2
    else:
        sum2 = number2 % 10 * 2 + sum2
    number2 = number2 // 100

LastDigit = (sum1 + sum2) % 10

if LastDigit is 0:
    # If AMEX
    if number // 10**13 == 34 or number // 10**13 == 37:
        print("AMEX")
    # If VISA
    elif number // 10**15 == 4 or number // 10**12 == 4:
        print("VISA")
    # If MASTERCARD
    elif number // 10**15 < 56 and number // 10*15 > 50:
        print("MASTERCARD")
    # If OTHER
    else:
        print("INVALID")
else:
    print("INVALID")
