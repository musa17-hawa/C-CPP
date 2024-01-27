#include <stdio.h>

int main() {
    
    int first_val, second_val;
    printf("Please choose your first number: ");
    scanf("%d", &first_val);
    printf("Please choose your second number: ");
    scanf("%d", &second_val);
    get_sum(second_val) == first_val ? printf("yes") : printf ("no");
    return 0;
}

int get_sum (int value){
    int result = 0;
    int tmp;
    while (value > 0){
        tmp = value%10;
        result = result + tmp;
        value = value/10;
    }
    return result;
}