// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()
#include <math.h>

// user-defined header files
#include "mypcm.h"


// function prototypes
void run(asignal * inputsignal);


int main()
{
    asignal * inputsignal = (asignal *) malloc(sizeof(asignal));
    run(inputsignal);
    
    //call any other function here

    free(inputsignal);
	return 0;
}

void run(asignal * inputsignal) 
{
    float A, omega, sigma;
    int duration, interval, encoderbits;

    if (scanf("%f %f %f %d %d %d", &A, &omega, &sigma, &duration, &interval, &encoderbits) != 6)
    {
        printf("InputError: Invalid input.\n");
        return;  // Exit the function on invalid input.
    }

    // Consume any remaining characters in the input buffer.
    for (int a; (a = getchar()) != '\n' && a != EOF;)
        ;

    inputsignal->A = A;
    inputsignal->omega = omega;
    inputsignal->sigma = sigma;
    inputsignal->duration = duration;

    int pcmSize= (duration / interval) + 2;
    int encodedSize = (pcmSize - 1) * encoderbits;
    int quantizationLevels = 1 << encoderbits; // Use bitwise left shift for power of 2.

    // Use calloc to initialize the allocated memory to zero.
    float* sampleArray = (float*)calloc(pcmSize, sizeof(float));
    int* pcmPulseArray = (int*)calloc(pcmSize, sizeof(int));
    int* encodedSignal = (int*)calloc(encodedSize, sizeof(int));

    if (!sampleArray || !pcmPulseArray || !encodedSignal)
    {
        printf("AllocationError: Memory allocation failed.\n");
        // Free any allocated memory before exiting.
        free(sampleArray);
        free(pcmPulseArray);
        free(encodedSignal);
        return;
    }

    sampler(sampleArray, interval, *inputsignal);
    quantizer(sampleArray, pcmPulseArray, quantizationLevels, A);
    encoder(pcmPulseArray, encodedSignal, encoderbits);

    free(sampleArray);
    free(pcmPulseArray);
    free(encodedSignal);


}


