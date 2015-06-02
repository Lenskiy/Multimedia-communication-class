/*
 * imdec.c
 *
 *  Created on: May 27, 2015
 *      Author: user
 */
#include <stdio.h>\

struct Run3D {
    unsigned char run;
    short level;
    char last;
};

int main(){
	struct Run3D runs[1024][64];
	char c;
	int cur_bnum, i, num_blocks = 1024;

	for(cur_bnum = 0; cur_bnum < num_blocks; cur_bnum++){
		i = -1;
		do{
			i++;
			scanf("%d %c %d %c %d", &runs[cur_bnum][i].run,
									&c,
									&runs[cur_bnum][i].level,
									&c,
									&runs[cur_bnum][i].last);

//			printf("%d,%d,%d\n", 	runs[cur_bnum][i].run,
//									runs[cur_bnum][i].level,
//									runs[cur_bnum][i].last);
		}while(runs[cur_bnum][i].last == 0);
	}

	return 0;
}
