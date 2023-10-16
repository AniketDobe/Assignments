#   Fibonacci numbers without recursion
#   Created by Aniket Dobe

def fibonacci_series_up_to_number(max_number):
    fib_sequence = [0, 1]
    next_fib = 1
    
    while next_fib <= max_number:
        next_fib = fib_sequence[-1] + fib_sequence[-2]
        if next_fib <= max_number:
            fib_sequence.append(next_fib)
    
    return fib_sequence

max_number = int(input("Enter the maximum number for the Fibonacci series: "))
fib_series = fibonacci_series_up_to_number(max_number)

print("Fibonacci series up to", max_number, ":")
print(fib_series)
