#include <stdio.h>

struct Item{
    int profit;
    int weight;
};

// Function to find maximum profit
double fractionalKnapsack(struct Item items[], int n, int capacity)
{
    double totalProfit = 0.0; // Total profit initialized to 0
    int currentWeight = 0;    // Current weight of items in knapsack

    // Loop through each item until the knapsack is full or all items are considered
    for (int i = 0; i < n && currentWeight < capacity; i++)
    {
        // If adding the whole item is within capacity, add it completely
        if (currentWeight + items[i].weight <= capacity)
        {
            totalProfit += items[i].profit;
            currentWeight += items[i].weight;
        }
        // Otherwise, add a fraction of the item to fill the knapsack to its full capacity
        else
        {
            int remainingCapacity = capacity - currentWeight;
            totalProfit += items[i].profit * ((double)remainingCapacity / items[i].weight);
            break;
        }
    }
    return totalProfit;
}

int main()
{
    struct Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50;
    double maxProfit = fractionalKnapsack(items, n, capacity);
    printf("Maximum profit: %.2f\n", maxProfit);
    return 0;
}