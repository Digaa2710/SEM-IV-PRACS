#include <stdio.h>

int coin_change[100][100];

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int n;
    printf("ENTER NUMBER OF COINS including 0: ");
    scanf("%d", &n);

    int m;
    printf("ENTER NUMBER OF COINS AVAILABLE: ");
    scanf("%d", &m);

    int coins[m];
    printf("ENTER THE COIN DENOMINATIONS: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &coins[i]);
    }

    // Initializing the first row
    for (int i = 0; i <= n; i++) {
        coin_change[0][i] = i;
    }

    // Initializing the first column
    for (int i = 0; i <= m; i++) {
        coin_change[i][0] = 0;
    }

    // Filling in the rest of the matrix
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
           if (j < coins[i - 1]) {
                 coin_change[i][j] = coin_change[i - 1][j];
            } 
            else {
                coin_change[i][j] = min(coin_change[i - 1][j], 1 + coin_change[i][j - coins[i - 1]]);
}

        }
    }

    printf("Minimum number of coins needed to make change for %d: %d\n", n, coin_change[m][n]);
    

    return 0;
}
//This code was made using the help of chatgpt
