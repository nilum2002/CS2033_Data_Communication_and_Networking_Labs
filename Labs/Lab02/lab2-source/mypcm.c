// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // includes malloc(),free()
//Add any necessary headers here
#include <math.h>
// user-defined header files
#include "mypcm.h" // do not modify this file
#define pi 
// put your function prototypes for additional helper functions below:


// implementation
float analog_signal_generator(asignal signal, int t)
{
	//TODO
	// x(t) = A*sin(𝜔𝑡 + omega )
	printf("%s\n","Working signal generator ");
	return (signal.A)*(sin(signal.omega*t + signal.sigma ));



}
void sampler(float *samples, int interval, asignal signal)
{
	//TODO
	int temp_num = 0;
	int interval_count = signal.duration / interval;
	while (temp_num <= interval_count){
        // analog generator 
        *samples = analog_signal_generator(signal, temp_num*interval);
		samples++;
		temp_num = temp_num +1;
	}
	*samples = 2*signal.A;
	printf("%s\n","Working signal sampler ");


}
void quantizer1(float *samples, int *pcmpulses, int levels)
{
	//TODO
}
void quantizer(float *samples, int *pcmpulses, int levels, float A)
{
	//TODO
	for (; *samples != 2 * A; samples++, pcmpulses++)
    {
        *pcmpulses = floor((*samples - A) * levels / (2 * A));
    }
    *pcmpulses = levels * 2;
}
void encoder(int *pcmpulses, int *dsignal, int encoderbits)
{
	//TODO
	int *bitsArr = (int *)malloc(sizeof(int) * encoderbits);
    int levels = pow(2, encoderbits);
    int len = 0;
    int i; // Declare the loop variable outside

    while (*pcmpulses != 2 * levels)
    {
        len++;
        int value = *pcmpulses;
        for (i = 0; i < encoderbits; i++) // Initialize i outside the loop
        {
            bitsArr[i] = value % 2;
            value /= 2;
        }

        i = encoderbits - 1; // Initialize i outside the loop

        while (i >= 0) // Convert the following loop from for to while
        {
            *dsignal = bitsArr[i];
            dsignal++;
            i--; // Increment i inside the loop
        }

        pcmpulses++;
    }

    len *= 2;

    for (i = len - 1; i >= 0; i--) // Initialize i outside the loop
    {
        dsignal--;
    }

    for (i = 0; i < len; i++) // Initialize i outside the loop
    {
        printf("%d", *dsignal);
        dsignal++;
    }
}