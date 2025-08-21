// Consider a special type of animal named Animal-X that reproduces following the rules below:
// - An Animal-X dies six months after it is born. That is, if an Animal-X is born in month
// 0, it will die in month 6.
// - An Animal-X gives birth to two Animal-Xes every two months until it dies. That is,
// if an Animal-X is born in month 0, it will reproduce in months 2 and 4. It does not
// reproduce in month 6 or beyond.
// - In each month, among all the Animal-Xes that have been alive for exactly three months,
// there is one that dies. That is, if there are n (n > 0) Animal-Xes that are born in
// month 0, one of them will die in month 3.

#include <stdio.h>
#include <stdlib.h>
int calculate_animal_x(int initial, int m); 
int main(int argc, char const *argv[])
{
    /* code */
    printf("%d\n", calculate_animal_x(1,8)); 

    return 0;
}

int calculate_animal_x(int initial, int m) {
    int *amount_diff = calloc(m ,sizeof(int)); 
    if (m < 2) return initial;
    amount_diff[0] = initial; 
    if (m > 0) amount_diff[1] = 0; 
    for (int i = 2; i < m; i++) {
        if (i % 2 == 0) {
            amount_diff[i] += amount_diff[i - 2]*2; 
            if (i -4 >= 0) {
                amount_diff[i] += amount_diff[i - 4] * 2; 
            }
        }
        if (i % 2 != 0) {
            if (amount_diff[i - 3] > 0) amount_diff[i] -= 1; 
        }
        if (i % 6 == 0) {
            amount_diff[i] -= amount_diff[i - 6]; 
        }
    }
    int final_amount = 0; 
    for (int i = 0; i < m; i++){
        final_amount += amount_diff[i];
        printf("%d ", final_amount); 
    }
    printf("\n");
    return final_amount; 
}
