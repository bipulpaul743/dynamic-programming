#include<stdio.h>
#include<math.h>
typedef struct item{
    char id;
    int p, wt;
}knap;
knap y[] = {{'A',60,10},{'B',100,20},{'C',120,30}};
int n = 3;
int M = 40;
void display() {
    for(int i=0; i<n; i++) {
        printf("(%c,%d,%d)  ",y[i].id, y[i].p, y[i].wt);
    }
    printf("\n");
}
// int max(int a, int b) {
//     return (a > b) ? a : b;
// }
void knapsack() { 
    int x[n + 1][M + 1];
    int profit = 0;
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= M; w++) {
            if (i == 0 || w == 0)
                x[i][w] = 0;
            else if (y[i-1].wt > w)
                x[i][w] = x[i-1][w];
            else
                x[i][w] = fmax(x[i-1][w], x[i-1][w-y[i-1].wt] + y[i-1].p);
        }
    }
    printf("Intermediate state of profit table :\n");
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= M; w++) {
            printf("%4d ", x[i][w]);
        }
        printf("\n");
    }
    // Find selected items
    printf("Selected items :\n");
    int weight = M;
    int maxProfit = x[n][M];
    for (int i = n; i > 0 && maxProfit > 0; i--) {
        if (maxProfit == x[i - 1][weight])  
            continue;  // Item was not included
        
        printf("%c -> %d\n", y[i - 1].id, y[i - 1].p);
        maxProfit -= y[i - 1].p;
        weight -= y[i - 1].wt;
    }
    printf("Maximum value in Knapsack = %d\n",x[n][M]);
}
int main() {
    display();
    knapsack();

    return 0;
}