/* --- Arquivo : exercicio1.c --- */

/* --- inicializacao () --- */
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
typedef struct {pthread_mutex_t sem; int ativado;} Event;
#define Semaph sem_t
#include "type_exercicio1.h"  /* typedef's */
#include "vgp_exercicio1.h"   /* global privada*/
#include "vsl_exercicio1.h"   /* shared local  */
#include "partask_exercicio1.h"
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

#include "cob_exercicio1.h"
#include <stdio.h>
#define print_count 10
void *tar1 (void * arg);   /* --- spec () */
void *tar2 (void * arg);   /* --- spec () */
void *tar3 (void * arg);   /* --- spec () */
void *tar4 (void * arg);   /* --- spec () */
void *tar5 (void * arg);   /* --- spec () */
void *tar6 (void * arg);   /* --- spec () */
/* -- rs400() : definicao de task  */
void *tar1 (void * arg) 
{  
 int i;

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
   for(i = 0; i < print_count; i++) {
 		printf("%c",'a');
  		fflush(stdout);
 	}

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *tar2 (void * arg) 
{  
 int i;

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
   for(i = 0; i < print_count; i++) {
 		printf("%c",'b');
  		fflush(stdout);
 	}

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *tar3 (void * arg) 
{  
 int i;

   _cpar_arg_task_2_ *_cpar_arg_t_;
   _cpar_arg_t_= (_cpar_arg_task_2_ *)arg;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=2;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   for(i = 0; i < print_count; i++) {
 		printf("%c",'c');
  		fflush(stdout);
 	}

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *tar4 (void * arg) 
{  
 int i;

   _cpar_arg_task_3_ *_cpar_arg_t_;
   _cpar_arg_t_= (_cpar_arg_task_3_ *)arg;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=3;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   for(i = 0; i < print_count; i++) {
 		printf("%c",'d');
  		fflush(stdout);
 	}

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *tar5 (void * arg) 
{  
 int i;

   _cpar_arg_task_4_ *_cpar_arg_t_;
   _cpar_arg_t_= (_cpar_arg_task_4_ *)arg;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=4;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   for(i = 0; i < print_count; i++) {
 		printf("%c",'e');
  		fflush(stdout);
 	}

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

/* -- rs400() : definicao de task  */
void *tar6 (void * arg) 
{  
 int i;

   _cpar_arg_task_5_ *_cpar_arg_t_;
   _cpar_arg_t_= (_cpar_arg_task_5_ *)arg;
   int _cpar_id_thread_;
   int _cpar_numthreads_;
   int _cpar_id_task_;
   _cpar_id_task_=5;
   _cpar_id_thread_=_cpar_arg_t_->id_thread;
   _cpar_numthreads_=_cpar_arg_t_->numthreads;
   int _id_thread_;
   insert_id_thread();
   _id_thread_=get_id_thread_gl();

   if (_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_))
   {
   for(i = 0; i < print_count; i++) {
 		printf("%c",'f');
  		fflush(stdout);
 	}

   }
   end_barrier(_cpar_id_task_,_cpar_id_thread_,_cpar_numthreads_);
   rm_thread_conflict();
}

main()
{

int _id_thread_,_i_;

int _cpar_id_thread_;
for (_i_=0;_i_<1000;_i_++)

   list_thread[_i_].id_thread = -1;

insert_id_thread();

_id_thread_=get_id_thread_gl();

  _cpar_arg_task_0_ *_cpar_arg_0_;

  _cpar_arg_task_1_ *_cpar_arg_1_;

  _cpar_arg_task_2_ *_cpar_arg_2_;

  _cpar_arg_task_3_ *_cpar_arg_3_;

  _cpar_arg_task_4_ *_cpar_arg_4_;

  _cpar_arg_task_5_ *_cpar_arg_5_;

  _cpar_num_tasks_=6;

  glbpriv=calloc(_MAX_THREADS_,sizeof(gl_priv));

  initial_main(_cpar_num_tasks_);


   printf("Seq1\n");
 	fflush(stdout);
 	
pthread_t  _cpar_tid_1;

pthread_mutex_lock(&_cpar_mutex_create_thread_);
pthread_create(&_cpar_tid_1,NULL,ROT1,(void *) NULL);

pthread_mutex_unlock(&_cpar_mutex_create_thread_);

pthread_t  _cpar_tid_2;
pthread_create(&_cpar_tid_2,NULL,ROT2,(void *) NULL);

pthread_join(_cpar_tid_1,NULL);

pthread_join(_cpar_tid_2,NULL);

    printf("\n");
    fflush(stdout);
   wait_all();      /* --- rs307()  */
}

#include "cob_exercicio1"
