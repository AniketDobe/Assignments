def knapsack(values, weights, capacity):
    n = len(values)
    
    # Initialize a table to store the maximum values for each subproblem
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
    
    # Fill the table using dynamic programming
    for i in range(n + 1):
        for w in range(capacity + 1):
            if i == 0 or w == 0:
                dp[i][w] = 0
            elif weights[i - 1] <= w:
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]])
            else:
                dp[i][w] = dp[i - 1][w]
    
    # Trace back to find the selected items
    selected_items = []
    i, w = n, capacity
    while i > 0 and w > 0:
        if dp[i][w] != dp[i - 1][w]:
            selected_items.append(i - 1)
            w -= weights[i - 1]
        i -= 1

    return dp[n][capacity], selected_items

# Example usage:
values = [60, 100, 120]
weights = [10, 20, 30]
capacity = 50
max_value, selected_items = knapsack(values, weights, capacity)
print("Maximum value:", max_value)
print("Selected items:", selected_items)
