#include <stdio.h>
#include <math.h> 
#define NUM_SAMPLES 10


int main() {
    
    double input_signal[NUM_SAMPLES] = {1.0, 2.0, 3.0, 4.0, 5.0, 34.0, 2.0, 4.0, 2.0, 7.0};

   
    double dft_real_part[NUM_SAMPLES];
    double dft_imag_part[NUM_SAMPLES];

 
    long long total_multiplications = 0;
    long long total_additions = 0;

    printf("Input Signal: x[n]\n");
    for (int i = 0; i < NUM_SAMPLES; i++) {
        printf("%.2f ", input_signal[i]);
    }
    printf("\n\n---------------------------------------\n");
    printf("DFT Output: X[k] = Real + j(Imaginary)\n");
    printf("---------------------------------------\n");


    // Loop through each frequency component 'k' from 0 to N-1
    for (int k = 0; k < NUM_SAMPLES; k++) {
        double current_sum_real = 0.0;
        double current_sum_imag = 0.0;

        
        for (int n = 0; n < NUM_SAMPLES; n++) {
            double angle = (2.0 * M_PI * k * n) / (double)NUM_SAMPLES;
            total_multiplications += 3; // For 2*pi, *k, *n
            // From Euler's formula: e^(-j*angle) = cos(angle) - j*sin(angle)
            // Real part contribution: input_signal[n] * cos(angle)
            current_sum_real += input_signal[n] * cos(angle);
            total_multiplications++; // For input_signal * cos()
            total_additions++;       // For the += operation
            // Imaginary part contribution: -input_signal[n] * sin(angle)
            current_sum_imag -= input_signal[n] * sin(angle);
            total_multiplications++; // For input_signal * sin()
            total_additions++;       // For the -= operation
        }

        dft_real_part[k] = current_sum_real;
        dft_imag_part[k] = current_sum_imag;

        // Print the calculated DFT component for the current 'k'
        printf("X[%d] = %8.4f + j(%8.4f)\n", k, dft_real_part[k], dft_imag_part[k]);
    }


    // --- 3. Print Computation Count ---
    
    printf("\n---------------------------------------\n");
    printf("Computational Complexity Analysis\n");
    printf("---------------------------------------\n");
    printf("Number of Samples (N): %d\n", NUM_SAMPLES);
    printf("Total Multiplications/Divisions: %lld\n", total_multiplications);
    printf("Total Additions/Subtractions: %lld\n", total_additions);
    printf("\nNote: This is a rough estimate. It counts the basic arithmetic operations\n");
    printf("but does not account for the complexity of the sin() and cos() functions themselves.\n");
    printf("The complexity of a direct DFT is O(N^2).\n");

    return 0;
}
