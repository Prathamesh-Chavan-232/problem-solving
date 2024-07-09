"""
    Link -
    Problem - Sequential numbers
    Difficulty - Medium
    Status -
    Date - 5/2/2024

    Description - Give a Range low - high find all the numbers in it whose digits are Sequential.
    Eg. low = 100, high = 300
        sequential= [123,234]

    100 - 300


    Approach 1 -
        1)
        2)
        3)

    Notes -
       1)
       2)
       3)
"""

def sequentialDigits(low: int, high: int):
    low_str = str(low)
    high_str = str(high)

    l_ptr = low_str[0]
    h_ptr = high_str[0]

    x = ""
    nums = []
    while int(l_ptr) < int(h_ptr):
        print(x)
        nums.append(x)
        x = ""

    print(nums)


low = 100
high = 3000

sequentialDigits(low, high)
