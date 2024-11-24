// C Program for 0-1 KnapSack Problem using Tabulation
#include <stdio.h>

// Maximum number of items and maximum capacity of the
// knapsack
#define MAX_ITEMS 100
#define MAX_CAPACITY 100

// Function that returns maximum of two integers
int max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

// Tabulation function for 0-1 Knapsack
int knapSackTabulation(int W, int wt[], int val[], int n)
{
    // Create a DP table
    int dp[n + 1][W + 1];

    // Initialize DP table (base cases)
    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (wt[i - 1] <= w)
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Return the maximum value that can be put in the
    // knapsack of capacity W
    return dp[n][W];
}

int main()
{
    int values[] = { 3, 4, 5, 6 };
    int weight[] = { 2, 3, 4, 5 };
    int W = 8;
    int n = sizeof(values) / sizeof(values[0]);

    // Output the maximum profit of the knapSack
    printf(
        "Maximum value that can be put in knapsack: %d\n",
        knapSackTabulation(W, weight, values, n));

    return 0;
}
