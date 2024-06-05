class Item:
    def __init__(self, value, weight):
        self.value = value
        self.weight = weight
        self.ratio = value / weight

def fractional_knapsack(values, weights, capacity):
    n = len(values)
    items = [Item(values[i], weights[i]) for i in range(n)]
    items.sort(key=lambda item: item.ratio, reverse=True)

    total_value = 0
    fractions = [0] * n

    for i in range(n):
        if items[i].weight <= capacity:
            fractions[i] = 1
            capacity -= items[i].weight
            total_value += items[i].value
        else:
            fractions[i] = capacity / items[i].weight
            total_value += items[i].value * fractions[i]
            break

    return total_value, fractions

# Example usage
values = [60, 100, 120]
weights = [10, 20, 30]
capacity = 50

total_value, fractions = fractional_knapsack(values, weights, capacity)
print(f'Total value in the knapsack: {total_value}')
print(f'Fractions of items: {fractions}')
