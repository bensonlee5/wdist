#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif


double drand()   /* just a uniform distribution for zscore, (0..1] */
{
  return (rand()+1.0)/(RAND_MAX+1.0);
}

double zscore()  /* normal distribution, mean 0, sd 1 - can make non-zscore if needed */
{
  return sqrt(-2*log(drand())) * cos(2*M_PI*drand());
}

void help_msg() {
  printf("Generates .map and .ped files to stress-test WDIST.\n\n");
  printf("gen_test [number of people] [number of markers]\n");
}

int main(int argc, char* argv[]) {
  int PEOPLE;
  int MARKERS;
  char* buf;
  char* str_end;
  if (argc != 3) {
    help_msg();
    return 1;
  }
  PEOPLE = atoi(argv[1]);
  MARKERS = atoi(argv[2]);
  if ((PEOPLE < 2) || (MARKERS < 1)) {
    help_msg();
    return 1;
  }
  buf = (char*)malloc((MARKERS * 4 + 30) * sizeof(char));
  srand(time(NULL));
  FILE* mapfile = fopen("wdist.map", "w");
  FILE* pedfile = fopen("wdist.ped", "wb");
  int ii;
  int jj;
  int rand2;    // p0 = 0.02, p1 = 0.49, p2 = 0.49 
  int rand50;
  for (ii = 0; ii < MARKERS; ii += 1) {
    fprintf(mapfile, "1\trs%d\t0\t1000\n", ii);
  }
  fclose(mapfile);
  for (ii = 0; ii < PEOPLE; ii += 1) {
    str_end = buf;
    str_end += sprintf(buf, "1 %d 0 0 1 %f ", ii + 1000000000, zscore());
    for (jj = 0; jj < (MARKERS * 2); jj += 2) {
      rand50 = rand() %50;
      if (rand50 < 1){
        rand2 = 0;}
      else 
        rand2 = rand() %2 +1;
      str_end += sprintf(str_end, "%d ", rand2);
      if (rand2 > 0){
        str_end += sprintf(str_end, "%d ", rand() %2 +1);
      }
      else 
	str_end += sprintf(str_end, "%d ", 0);
    }
    fprintf(pedfile, "%s \n", buf);
  }
  fclose(pedfile);
  return 0;
}