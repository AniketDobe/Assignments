#   Fibonacci numbers using recursion
#   Created by Aniket Dobe

def fibonacci_recursive(n):
    if n <= 1:
        return n
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)

def fibonacci_series_up_to_number(max_number):
    series = []
    num = 0
    while fibonacci_recursive(num) <= max_number:
        series.append(fibonacci_recursive(num))
        num += 1
    return series

max_number = int(input("Enter the maximum number for the Fibonacci series: "))
fib_series = fibonacci_series_up_to_number(max_number)

print("Fibonacci series up to", max_number, ":")
print(fib_series)
