#include<stdio.h>
#include<string.h>

char T[100], P[100];
int pi[100];
int m, n;

void prefix() {
    m = strlen(P);
    pi[0] = pi[1] = 0;
    int k = 0;
    for (int q = 2; q <= m; q++) {
        while (k > 0 && P[k] != P[q - 1]) {
            k = pi[k];
        }
        if (P[k] == P[q - 1]) {
            k = k + 1;
        }
        pi[q] = k;
    }
    printf("Prefix array: ");
    for (int i = 1; i <= m; i++) {
        printf("%d ", pi[i]);
    }
    printf("\n");
}

void KMP() {
    n = strlen(T);
    m = strlen(P);
    int q = 0;
    for (int i = 0; i < n; i++) {
        while (q > 0 && P[q] != T[i]) {
            q = pi[q];
        }
        if (P[q] == T[i]) {
            q = q + 1;
        }
        if (q == m) {
            printf("Pattern found at shift %d\n", i - m + 1);
            q = pi[q];
        }
    }
}

int main() {
    printf("Enter text: ");
    scanf("%s", T);
    printf("Enter pattern: ");
    scanf("%s", P);
    prefix();
    KMP();
    return 0;
}
