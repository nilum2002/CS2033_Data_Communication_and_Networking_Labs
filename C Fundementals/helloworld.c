#include <stdio.h>



void main(){
    const double pi = 22/7;
    printf("Calculating the Area of a circle...\n");
    double radius;
    printf("Enter the radius of the circle: ");
    scanf("%lf", &radius);
    double area = pi * radius * radius;
    printf("The area of the circle with radius %.2lf is: %.2lf\n", radius, area);
    printf("Thank you for using the program!\n");


}
