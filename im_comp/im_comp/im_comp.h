//
//  im_comp.h
//  im_comp
//
//  Created by Artem Lenskiy on 5/19/15.
//  Copyright (c) 2015 Artem Lenskiy. All rights reserved.
//

#ifndef __im_comp__im_comp__
#define __im_comp__im_comp__

#include <stdio.h>

struct Run3D {
    unsigned char run;
    short level;
    char last;
};


void quantize_block ( short coef[8][8] );
//inverse quantize one block
void inverse_quantize_block ( short coef[8][8] );


//input : Y,  output : Yr
void reorder ( short Y[8][8], short Yr[8][8] );
//input : Yr, output : Y
void reverse_reorder ( short Yr[8][8], short Y[8][8] );


void run_block ( short Y[8][8], struct Run3D runs[] );
void run_decode (struct Run3D runs[], short Y[8][8] );


#endif /* defined(__im_comp__im_comp__) */
