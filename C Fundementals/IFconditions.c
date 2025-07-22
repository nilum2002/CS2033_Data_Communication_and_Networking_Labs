#include <stdio.h>
#include <stdbool.h>
bool isEven(int num) {
    return (num%2 == 0)? true: false;
}

int main(){
    printf("The Odd even identifier...\n");
    printf("Enter the number:\n");
    int num;
    scanf("%d", &num);
    isEven(num)? printf("The number is %d  even\n", num) : printf("The number is %d is odd\n", num );



    return 0;
}