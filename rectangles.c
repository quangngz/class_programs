#include <stdio.h>

double max_profit_achieveable(double prices[], int n);

int main(int argc, char*argv[]) {
    double prices[] = {1.0, 5.1, 7.3, 9.4, 4.7, 8.0, 15.0, 6.2};
    int n = 8;
    double result = max_profit_achieveable(prices, n);
    printf("Maximum profit: %lf", result); 
    return 0; 
}

double max_profit_achieveable(double prices[], int n) {
    double min = prices[0];
    double profit[n]; 
    profit[0] = prices[0]; 
    for (int i = 1; i < n; i++){
        if (prices[i] <= min){
            min = prices[i]; // Indicating you should buy at this date
            profit[i] = 0; 
        }
        else if (prices[i] - min > 0) {
            profit[i] = prices[i] - min; 
        }
    }
    double max_profit = 0; 
    for (int i = 0; i < n; i++) {
        printf("%lf, ", profit[i]); 
        if (profit[i] > max_profit) {
            max_profit = profit[i]; 
        }
    }
    printf("\n");
    return max_profit; 
}