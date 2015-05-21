//
//  main.c
//  dct2d
//
//  Created by Artem Lenskiy on 5/10/15.
//  Copyright (c) 2015 Artem Lenskiy. All rights reserved.
//

/*
 dct_direct.cpp
 A straight forward implementation of DCT and IDCT for the purpose
 of learning and testing. Floating-point arithmetic is used.  Such
 an implementation should not be used in practical applications.
 Compile: g++ -o dct_direct dct_direct.cpp -lm
 Execute: ./dct_direct
 */

#include <stdio.h>
#include <stdlib.h>


#define PI 3.141592653589

int main() {
    short f[16][16], F[16][16];
    int i, j, N;
    N = 16;
    //try some values for testing
    for ( i = 0; i < N; ++i )
        for ( j = 0; j < N; ++j )
            f[i][j] = i + j;

    printf("\nOriginal sample values");
    print_elements ( N, &f[0][0] );
    printf("\n--------------------\n");
    dct ( N, &f[0][0], &F[0][0] );
    printf("\nCoefficients of DCT:");
    print_elements ( N, &F[0][0] );
    printf("\n--------------------\n");
    idct ( N, &F[0][0], &f[0][0] );
    printf("\nValues recovered by IDCT:");
    print_elements ( N, &f[0][0] );
    printf("\n");
}

