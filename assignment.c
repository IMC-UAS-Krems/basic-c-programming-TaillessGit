#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // initialize random number generator
    srand(time(NULL));
    int minrand = 1;
    int maxrand = 100;
    
    // 1.
    if (argc != 2){
        printf("Incorrect usage. You provided %d arguments. The correct number of arguments is 2", argc-1);
        return 0;
    }
    
    // 2.
    int r = argv[0]-"0";
    int c = argv[1]-"0";
    
    if ((r % 1 != 0) || (c % 1 != 0) || (r < 1) || (c < 1)) {
        printf("Incorrect usage. The parameters you provided are not positive integers");
        return 0;
    }
    
    // 3.
    int matrix[r][c];
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            matrix[i][j] = rand() % (maxrand + 1 - minrand) + minrand; //Stackoverflow
        }
    }

    // 4.
    FILE * mfile = fopen("matrix.txt", "w");
    
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            fprintf(mfile,"%d",matrix[i][j]);
            if (j != c-1) {
                fprintf(mfile," ");
            } else {
                fprintf(mfile,"\n");
            }
        }
    }

    fclose(mfile);
    
    return 0;
}
