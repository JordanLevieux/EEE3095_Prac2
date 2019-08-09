#include "Prac2.h"

extern float data [SAMPLE_COUNT];
extern float carrier[SAMPLE_COUNT];

int dis = 0;
float result [SAMPLE_COUNT];
float check [SAMPLE_COUNT];
int main(int argc, char**argv){
    printf("Running Unthreaded Test\n");
    printf("Precision sizeof %d\n", sizeof(float));

    tic(); // start the timer
    for (int i = 0;i<SAMPLE_COUNT;i++ ){
        result[i] = data[i] * carrier[i];
    }
    double t = toc();
    printf("Time: %lf ms\n",t/1e-3);
    printf("End Unthreaded Test\n");
	for (int k=0;k<10;k++){printf("check: %f",result[k]);}
	FILE *f = fopen("temp.data", "wb");
	fwrite(result, sizeof(float), sizeof(result), f);
	fclose(f);
	FILE *ifp = fopen("out.data", "rb");
	fread(check, sizeof(float), sizeof(check), ifp);
	for (int i=0;i<SAMPLE_COUNT;i++)
	{
		if(check[i]!=result[i])
		{
			dis++;
			//break;
			printf("discrepency %d: check %f, result  %f\n",i, check[i], result[i]);
		}
	}
	if (dis == 0){printf("same\n");}
	else{printf("discrepencies\n");}
    return 0;
}
