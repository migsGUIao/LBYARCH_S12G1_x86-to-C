#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dot_product_c(float* A, float* B, int n, float* sdot) {
    *sdot = 0.0f;
    for (int i = 0; i < n; ++i) {
        *sdot += A[i] * B[i];
    }
}

void random_vals(float* A, float* B, int n) {
    // Initialize vectors A and B with random values
    srand(time(NULL));
    for (int i = 0; i < n; ++i) {
        A[i] = (float)rand() / RAND_MAX;
        B[i] = (float)rand() / RAND_MAX;
    }
}

void check_results(float sdot_c, float sdot_asm) {
    if (sdot_c == sdot_asm) {
        printf("The results match!! The x86-64 Kernel output is correct!\n");
    }
    else {
        printf("Warning! The x86-64 Kernel output is not correct\n");
    }
}

extern float dot_product_asm(float* a, float* b, int n);

void process_values(float* A, float* B, int n) {
    float sdot_c, sdot_asm;

    // Call and time the C version of the kernel
    clock_t start_c = clock();
    dot_product_c(A, B, n, &sdot_c);
    clock_t end_c = clock();
    double elapsed_c = (double)(end_c - start_c) / CLOCKS_PER_SEC;

    printf("C Version: sdot = %f\n", sdot_c);
    printf("Time taken (C): %f seconds\n", elapsed_c);

    // Call and time the assembly version of the kernel
    clock_t start_asm = clock();
    sdot_asm = dot_product_asm(A, B, n);
    clock_t end_asm = clock();
    double elapsed_asm = (double)(end_asm - start_asm) / CLOCKS_PER_SEC;

    printf("Assembly Version: sdot = %f\n", sdot_asm);
    printf("Time taken (Assembly): %f seconds\n", elapsed_asm);

    check_results(sdot_c, sdot_asm);
}

int main() {
    int n = 1 << 20; // 2^20

    float* A = (float*)malloc(n * sizeof(float));
    float* B = (float*)malloc(n * sizeof(float));

    printf("n = 2^20\n");
    random_vals(A, B, n);
    process_values(A, B, n);

    n = 1 << 24; // 2^24
    A = (float*)malloc(n * sizeof(float));
    B = (float*)malloc(n * sizeof(float));

    printf("\nn = 2^24\n");
    random_vals(A, B, n);
    process_values(A, B, n);

    n = 1 << 30; // 2^30
    A = (float*)malloc(n * sizeof(float));
    B = (float*)malloc(n * sizeof(float));

    printf("\nn = 2^30\n");
    random_vals(A, B, n);
    process_values(A, B, n);



    // Clean up
    free(A);
    free(B);

    return 0;
}
