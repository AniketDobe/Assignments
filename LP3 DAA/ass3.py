def fractional_knapsack(items, capacity):
    # Calculate the value-to-weight ratio for each item and sort them in descending order.
    items.sort(key=lambda item: item[1] / item[0], reverse=True)
    
    total_value = 0.0
    knapsack = []

    for item in items:
        if capacity == 0:
            break
        weight, value = item[0], item[1]
        fraction = min(weight, capacity)
        total_value += fraction * (value / weight)
        capacity -= fraction
        knapsack.append((weight, fraction, value))

    return total_value, knapsack

# Example usage:
items = [(10, 60), (20, 100), (30, 120)]
capacity = 50
max_value, selected_items = fractional_knapsack(items, capacity)
print("Maximum value:", max_value)
print("Selected items:", selected_items)
