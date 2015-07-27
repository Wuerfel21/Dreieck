#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>

mpz_t **line;
int in;

int main(int argc, char *argv[]) {
    if (argc != 2) {puts("Error: Not Enough/Too Many arguments"); exit(EXIT_FAILURE);}
    sscanf(argv[1], " %d", &in);
    printf("\n%i %i", in, argc);
    line = calloc(in+1,sizeof(mpz_t*));
    for (int i=0;i<in+1;i++) {
        line[i] = calloc(i+1,sizeof(mpz_t));
        mpz_array_init(line[i][0],i+1,1024);
    }
    mpz_set_ui(line[0][0],1); //line[0][0] = 1;
    for (int l=1;l<in+1;l++) {
        mpz_set_ui(line[l][0],1); //line[l][0] = 1;
        for (int i=1;i<l;i++) {
            mpz_add(line[l][i],line[l-1][i-1],line[l-1][i]); //line[l][i] = line[l-1][i-1] + line[l-1][i];
        }
        mpz_set_ui(line[l][l],1); //line[l][l] = 1;
    }
    puts("");
    for (int i=0;i<in+1;i++) {char* lulz = mpz_get_str(NULL,10,line[in][i]); printf("%s ",lulz); free(lulz);} //printf("%lli ",line[in][i]);
    puts("");
    system("PAUSE");
    return 0;
}
