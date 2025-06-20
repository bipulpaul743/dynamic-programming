#include <stdio.h>
#include <limits.h>
#define N 20 // Number of matrices is N-1 = 4

// Function to print the optimal parenthesization
void printoptimalParens(int s[N][N], int i, int j){
    if (i == j){
        printf("A%d", i);
    } else {
        printf("(");
        printoptimalParens(s, i, s[i][j]);
        printoptimalParens(s, s[i][j] +1,j);
        printf(")");
    }
}

int main() {
    int n;
    printf("Enter the number of element : ");
    scanf("%d",&n);
    printf("Enter the %d elements : ",n);
    int p[n];
    for(int i=0; i<n; i++){
        scanf("%d",&p[i]);
    }
    int m[N][N] ={0};   // Minimum cost table
    int s[N][N] = {0};  // k-values for optimal splits
    int q;

    // Fill m[][] and s[][] using dynamic programming
    for (int d=1; d<n-1; d++){
        for (int i=1; i<n-d; i++){
            int j = i+d;
            m[i][j] = INT_MAX;
            for (int k=i; k<=j-1; k++){
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];
                if (q < m[i][j]){
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Minimum number of multiplications : %d\n", m[1][n-1]);
    // Print the optimal parenthesization 
    printf("Optimal Parenthesization : ");
    printoptimalParens(s, 1, n-1);
    printf("\n");

    // Cost Table
    printf("\nCost Table m[][] : \n");
    for (int i=1; i<n; i++){
        for (int j=1; j<n; j++){
            if (i > j) printf("    - ");
            else printf("%5d ", m[i][j]);
        }
        printf("\n");
    }

    // Split Table
    printf("\nSplit Table s[][] : \n");
    for (int i=1; i<n; i++){
        for (int j=1; j<n; j++){
            if (i >= j) printf("    - ");
            else printf("%5d ", s[i][j]);
        }
        printf("\n");
    }

    return 0;
}