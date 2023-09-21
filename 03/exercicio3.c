/* --- Arquivo : exercicio3.c --- */

/* --- inicializacao () --- */
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
typedef struct {pthread_mutex_t sem; int ativado;} Event;
#define Semaph sem_t
#include "type_exercicio3.h"  /* typedef's */
#include "vgp_exercicio3.h"   /* global privada*/
#include "vsl_exercicio3.h"   /* shared local  */
#include "partask_exercicio3.h"
#define _MAX_THREADS_ 100
void insert_id_thread();
int get_id_thread_gl();
char _barrier(int id_task,int id_thread,int numthreads);
void end_barrier (int id_task,int id_thread,int numthreads);
void rm_thread_conflict();
void initial_main(int _cpar_num_tasks_);
void init_create_task(int id_task,int n_threads);
int wait_all();
int wait_proc(int id_task);
int lock(sem_t *sem);
int unlock(sem_t *sem);
int create_sem(sem_t *sem,int valor);
int create_ev(Event *ev);
int rem_ev(Event *ev);
int wait_ev(Event *ev);
int set_ev(Event *ev);
void res_ev(Event *ev);
int read_ev(Event *ev);
int get_mi_id(int mi_id);
#define get_mi_id() get_mi_id(_cpar_id_thread_)
pthread_t **_cpar_tid_;
int *_cpar_task_nthreads_;
extern int *_cpar_sec_parbegin_ ;
extern int *_cpar_count_bar_ ;
extern int *_cpar_count_end_bar_ ;
extern int *_cpar_end_barrier_;
int _cpar_id_task_;
extern int _cpar_num_tasks_;

extern int *_cpar_task_wait_flag_;

extern pthread_mutex_t *_cpar_create_task_flag_;

extern pthread_mutex_t _cpar_mutex_create_thread_ ;

extern pthread_mutex_t *_cpar_mutex_task_flag_ ;

extern pthread_mutex_t *_cpar_mutex_parbegin_ ;

extern pthread_mutex_t *_cpar_mutex_ ;

extern pthread_mutex_t *_cpar_mutex2_ ;

extern pthread_mutex_t *_cpar_mutex3_ ;

extern pthread_mutex_t *_cpar_mutex_bar_ ;

gl_priv *glbpriv;

extern int id_thread_global_next;

typedef struct {unsigned long int tid;int id_thread;struct type_next_id_thread *next;} type_next_id_thread;

typedef struct {unsigned long int tid;int id_thread;type_next_id_thread *next_id_thread;}type_list_id_thread;

extern type_list_id_thread list_thread[1000];

#include "cob_exercicio3.h"
/* #define IMPRIME 1 */
/*multiplicacao de matrizes: outer-product*/
#include <stdio.h>
#include <math.h>
#include <sys/time.h>
#include "mede_time.h"
#include <stdlib.h>
   int size;

   int search_val;

   int count[4];

   double a[2000][2000];

void *init_matrix (void * arg);   /* --- spec () */
void *pesquisa_elem (void * arg);   /* --- spec () */
/*inicia matriz*/
/* -- rs400() : definicao de task  */
void *init_matrix (void * arg) 
{  
 int i, j, k;

   _cpar_arg_task_0_ *_cpar_arg_t_;
   _cpar_arg_t_= (_cpar_arg_task_0_ *)arg;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=0;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
             };

      end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);

{
   int i_, n_;
   n_ = (size-1 - 0 + 1) / _cpar_numthreads_;
   if (((size-1 - 0 + 1) % _cpar_numthreads_) != 0)
      n_++;
   i_ = 0 + _cpar_id_thread_ * n_;

   for (i = i_; ((i < (i_ + n_)) && (i <= size-1)); i++) {   
        for (j=0;j<size;j++){
            a[i][j]=i*j;
        }
    }
}
     if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))  /* --- forall () */
  {

  
   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *pesquisa_elem (void * arg) 
{  
 int i, j;

   _cpar_arg_task_1_ *_cpar_arg_t_;
   _cpar_arg_t_= (_cpar_arg_task_1_ *)arg;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=1;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
             };

      end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);

{
   int i_, n_;
   n_ = (size-1 - 0 + 1) / _cpar_numthreads_;
   if (((size-1 - 0 + 1) % _cpar_numthreads_) != 0)
      n_++;
   i_ = 0 + _cpar_id_thread_ * n_;

   for (i = i_; ((i < (i_ + n_)) && (i <= size-1)); i++) {  
        for (j=0;j<size;j++)
            if(a[i][j] == search_val)
                count[get_mi_id()] = count[get_mi_id()] + 1;
    }
}
     if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))  /* --- forall () */
  {


   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

void main(argc, argv)
int argc;
char **argv;
{

int _id_thread_,_i_;

int _cpar_id_thread_;
for (_i_=0;_i_<1000;_i_++)

   list_thread[_i_].id_thread = -1;

insert_id_thread();

_id_thread_=get_id_thread_gl();

  _cpar_arg_task_0_ *_cpar_arg_0_;

  _cpar_arg_task_1_ *_cpar_arg_1_;

  _cpar_num_tasks_=2;

  glbpriv=calloc(_MAX_THREADS_,sizeof(gl_priv));

  initial_main(_cpar_num_tasks_);


   size = 2000;
    for (size_t i = 0; i < 4; i++)
        count[i] = 0;
    
    if (argc>1) { 
        search_val = atoi(argv[1]);
        printf("Valor a ser perquisado: %d\n",search_val);
    }
    else {
        printf("Valor a ser perquisado: \n");
        scanf("%d",&search_val);
    }
    TIMER_CLEAR;
    TIMER_START;
      
   init_create_task(0,4);

   sh_0=(shared_local_0 *) calloc(1,sizeof(shared_local_0));

   _cpar_arg_0_=(_cpar_arg_task_0_ *) calloc(4,sizeof(_cpar_arg_task_0_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<4;_cpar_id_thread_++) {

      _cpar_arg_0_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_0_[_cpar_id_thread_].numthreads=4;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[0][_cpar_id_thread_],NULL,init_matrix,(void *)&_cpar_arg_0_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[0]);

      _cpar_task_wait_flag_[0]=0;

    
   wait_proc (0);    /* --- wait_proc() --- */

    TIMER_STOP;
    printf ("TEMPO INICIA [SIZE %d]: %12.7f\n",size,TIMER_ELAPSED);
    

    TIMER_CLEAR;
    TIMER_START; 
      
   init_create_task(1,4);

   sh_1=(shared_local_1 *) calloc(1,sizeof(shared_local_1));

   _cpar_arg_1_=(_cpar_arg_task_1_ *) calloc(4,sizeof(_cpar_arg_task_1_ ));

   for(_cpar_id_thread_=0;_cpar_id_thread_<4;_cpar_id_thread_++) {

      _cpar_arg_1_[_cpar_id_thread_].id_thread=_cpar_id_thread_;

      _cpar_arg_1_[_cpar_id_thread_].numthreads=4;

      pthread_mutex_lock(&_cpar_mutex_create_thread_);

      if (pthread_create(&_cpar_tid_[1][_cpar_id_thread_],NULL,pesquisa_elem,(void *)&_cpar_arg_1_[_cpar_id_thread_])){

        fprintf(stderr,"Cannot create thread ");

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

        exit(1);

    } 

      pthread_mutex_unlock(&_cpar_mutex_create_thread_);

 }  

      pthread_mutex_unlock(&_cpar_create_task_flag_[1]);

      _cpar_task_wait_flag_[1]=0;

    
   wait_proc (1);    /* --- wait_proc() --- */

    TIMER_STOP;

    int count_fim = count[0] + count[1] + count[2] + count[3];

    printf("TEMPO PESQUISA [SIZE %d]: %12.7f\n",size,TIMER_ELAPSED);
    printf("NUMERO DE OCORRENCIAS: %d\n", count_fim);
    fflush(stdout);
   wait_all();      /* --- rs307()  */
}

#include "cob_exercicio3"
