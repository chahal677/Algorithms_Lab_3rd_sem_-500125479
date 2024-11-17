#include <stdio.h>
#include <stdbool.h>
#include <time.h>

bool isSubsetSum(int set[], int n, int sum) {
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++) {
        subset[i][0] = true;
    }

    for (int i = 1; i <= sum; i++) {
        subset[0][i] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (set[i - 1] <= j) {
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]];
            } else {
                subset[i][j] = subset[i - 1][j];
            }
        }
    }

    return subset[n][sum];
}

int main() {
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);

    clock_t start, end;
    double time_spent;

    start = clock();
    if (isSubsetSum(set, n, sum)) {
        printf("There is a subset with the given sum %d\n", sum);
    } else {
        printf("No subset with the given sum %d\n", sum);
    }
    end = clock();
    
    time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken for subset sum: %f seconds\n", time_spent);

    return 0;
}
