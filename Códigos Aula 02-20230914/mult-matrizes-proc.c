
#include <stdio.h>
#include <math.h>
#include <sys/time.h>

#include <sys/shm.h>
#include <stdlib.h>
#include "mede_time.h"

#define N_PROCS 3

typedef struct {
   double a[2000][2000], b[2000][2000], c[2000][2000];
} matrizes;
// matriz
matrizes *matriz;
pid_t pid_p;
int size;
int n_iter;

/*inicia matriz*/
inicia_matrizes(int id_proc)
{
  int i, j,k;
  int inicio_linhas,fim_linhas;

  inicio_linhas = (id_proc+1) * n_iter;
  fim_linhas = inicio_linhas + n_iter;
  printf("inicio_linhas=%d    fim_linhas=%d\n",inicio_linhas,fim_linhas);
  fflush(stdout);
  for(i = inicio_linhas; i < fim_linhas; i++){
    for (j = 0; j < size; j++){
      matriz->a[i][j]=0;
      matriz->b[i][j]=0;
      for (k=0;  k<size;  k++){
        matriz->a[i][j] = matriz->a[i][j]+0.2*i+1.03*j+1.5*k;
        matriz->b[i][j] = matriz->b[i][j]+0.3*i+0.2*j+1.7*k;
      }
      matriz->c[i][j]=0;
    }
  }
}



/*multiplicacao*/
mat_mult(int id_proc)
{
  int i, j, k;
  int inicio_linhas,fim_linhas;

  inicio_linhas = (id_proc+1) * n_iter;
  fim_linhas = inicio_linhas + n_iter;
  for(i = inicio_linhas; i < fim_linhas; i++){
    for(k = 0; k < size; k++) 
      for(j = 0; j < size; j++)
        matriz->c[i][j] += matriz->a[i][k] * matriz->b[k][j];
  }
}
// gabarito: c[0][0]=105014.250000  c[2][1]=110971.250000 c[9][9]=144947.250000

main(argc, argv)
int argc;
char **argv;
{  
  int i,j;
  pid_t pid[N_PROCS];
  int status;
  struct shmid_ds *buf;
  int id_matriz;
  int inicio_linhas,fim_linhas;
  int id_proc;

  if (argc > 1){
    size = atoi(argv[1]);
    printf("Matriz %dx%d\n",size,size);
  }

  else{
    printf("Tamanho da matriz: ");
    scanf("%d",&size);
  }

  TIMER_CLEAR;
  TIMER_START;
  id_matriz = shmget(IPC_PRIVATE, sizeof(matrizes), 0777 | IPC_CREAT);
  matriz = (matrizes *) shmat(id_matriz, 0, 0);

  //processo principal inicializa as matrizes   -  3 processos
  n_iter = size/(N_PROCS + 1);
  id_proc=-1;
//processo principal cria processos e armazena pid retornado em vetor
  pid_p=1;
  for (i=0;((i<N_PROCS) && (pid_p!=0));i++) {     
    pid_p = fork();
    if ((int)pid_p != 0)   //pai
      pid[i] = pid_p;
    else {    // filhos
      matriz = shmat(id_matriz, 0, 0);
      id_proc=i;
    }
  } 
  printf("id_proc=%d     n_iter=%d\n",id_proc,n_iter);
  fflush(stdout);
  inicia_matrizes(id_proc);
  if(pid_p == 0)
  {
    shmdt(matriz);
    exit(0);
  }

  for(i = 0; i < N_PROCS; i++) 
  {
    waitpid(pid[i],&status,0);
  }
  
  pid_p=1;
  for (i=0;((i<N_PROCS) && (pid_p!=0));i++) {     
    pid_p = fork();
    if ((int)pid_p != 0)   //pai
      pid[i] = pid_p;
    else {    // filhos
      matriz = shmat(id_matriz, 0, 0);
      id_proc=i;
    }
  } 
 
  mat_mult(id_proc);

  for(i = 0; i < N_PROCS; i++) 
    waitpid(pid[i],&status,0);
  TIMER_STOP;
  printf ("TEMPO TOTAL [SIZE %d]: %12.7f\n",size,TIMER_ELAPSED);
  printf("c[0][0]=%f   c[2][1]=%f c[%d][%d]=%f \n",matriz->c[0][0],matriz->c[2][1],size-1,size-1,matriz->c[size-1][size-1]);
  
  
  shmdt(matriz);
  shmctl(id_matriz, IPC_RMID, buf); //remove area compartilhada
}

