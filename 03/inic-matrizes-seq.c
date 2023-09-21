/* #define IMPRIME 1 */
/*multiplicacao de matrizes: outer-product*/
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include "mede_time.h"
#include <stdlib.h>

int size;
double a[2000][2000];
double b[2000][2000];
double c[2000][2000]; 

/*inicia matriz*/
void init_matrix()
  { 

     int i,j,k;
      for (i=0;i<size;i++) {  
        for (j=0;j<size;j++){
      	  a[i][j]=0;
          b[i][j]=0;
          for (k=0;  k<size;  k++){
            a[i][j] = a[i][j]+0.2*i+1.03*j+1.5*k;
            b[i][j] = b[i][j]+0.3*i+0.2*j+1.7*k;
          }
          c[i][j]=0;
        }
      }
  }


void main(argc, argv)
int argc;
char **argv;
{
  if (argc>1) { 
    size = atoi(argv[1]);
    printf("Matriz %dx%d\n",size,size);
  }
  else {
    printf("Tamanho da matriz: ");
    scanf("%d",&size);
  }
 
  TIMER_CLEAR;
  TIMER_START; 
  init_matrix();
  TIMER_STOP;
  printf ("TEMPO [%d]: %12.7f\n",size,TIMER_ELAPSED );
  printf("a[ 0][0]=%f a[ 300][300]=%f a[ 999][999]=%f\n",a[0][0],a[300][300],a[999][999]);
  printf("b[ 0][0]=%f b[ 300][300]=%f b[ 999][999]=%f\n",b[0][0],b[300][300],b[999][999]);
  printf("c[ 0][0]=%f c[ 300][300]=%f c[ 999][999]=%f\n",c[0][0],c[300][300],c[999][999]);
fflush(stdout);
}

