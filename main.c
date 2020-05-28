#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#include <errno.h>
#include <pthread.h>
#include <semaphore.h>


void * thread_function_1(void * arg){
	printf("[thread 1] Entry\n");

  return NULL;
}

void * thread_function_2(void * arg){
	printf("[thread 2] Entry\n");

  return NULL;
}

void * thread_function_3(void * arg){
	printf("[thread 3] Entry\n");

  return NULL;
}


int main(void) {
  pthread_t threads[3];

  // Creo e lancio i thread
  if(pthread_create(&threads[0], NULL, thread_function_1, NULL) != 0){
		perror("pthread_create()\n");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&threads[1], NULL, thread_function_2, NULL) != 0){
		perror("pthread_create()\n");
		exit(EXIT_FAILURE);
	}
	if(pthread_create(&threads[2], NULL, thread_function_3, NULL) != 0){
		perror("pthread_create()\n");
		exit(EXIT_FAILURE);
	}

  // Catturo i thread che terminano
  void * res1;
	if(pthread_join(threads[0], &res1) != 0){
		perror("pthread_join()\n");
		exit(EXIT_FAILURE);
	}

	void * res2;
	if(pthread_join(threads[1], &res2) != 0){
		perror("pthread_join()\n");
		exit(EXIT_FAILURE);
	}

	void * res3;
	if(pthread_join(threads[2], &res3) != 0){
		perror("pthread_join()\n");
		exit(EXIT_FAILURE);
	}

  return 0;
}