/* do not add other includes */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

double getTime(){
  struct timeval t;
  double sec, msec;
  
  while (gettimeofday(&t, NULL) != 0);
  sec = t.tv_sec;
  msec = t.tv_usec;
  
  sec = sec + msec/1000000.0;
  
  return sec;
}
 
/* for task 1 only */
void usage(void)
{
	fprintf(stderr, "Usage: cachetest2/2 [--repetitions M] [--array_size N]\n");
	exit(1);
}

int main (int argc, char *argv[])
{
  double t1, t2; 
  
  /* variables for task 1 */
  unsigned int M = 1000;
  unsigned int N = 256*1024; 
  unsigned int i, j;

  
	
  /* declare variables; examples, adjust for task */
	//int *a;
	//double  a[100];
    int *a, *b, sum;
  
  /* parameter parsing task 1 */
  for(i=1; i<(unsigned)argc; i++) {
	  if (strcmp(argv[i], "--repetitions") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &M);
		  else
			  usage();
	  } else if (strcmp(argv[i], "--array_size") == 0) {
		  i++;
		  if (i < argc)
			  sscanf(argv[i], "%u", &N);
		  else
			  usage();
	  } else usage();
  }

    
  /* allocate memory for arrays; examples, adjust for task */
	 //a = malloc (N * sizeof(int));
    a = malloc(N * sizeof(int));
    b = malloc(N * sizeof(int));
	 /* initialise arrray elements */
    for (i=0; i<N; i++) {
        b[i] = i;
        a[i] = 0;
    }

    sum = 0;
    
    //test that sum is correct
    for (i=0; i<50; i++) {
        a[N - 1 - i] = i;
        sum += i;
    }
    
    printf("Expected: %d\n", sum);

    //Shuffle array B 2N times
    srand(time(NULL));

    for (i=0; i<2*N; i++) {
        int index1 = rand() % N;
        int index2 = rand() % N;

        int temp = b[index1];
        b[index1] = b[index2];
        b[index2] = temp;
    }

	 
  t1 = getTime();
  /* code to be measured goes here */
  /***************************************/
  //repeat the task M times
    for (i=0; i<M; i++) {
        sum = 0;

        for (j=0; j < N; j++) {
            sum += a[b[j]];
        }
    }
	
	
	
  /***************************************/
	t2 = getTime(); 
  
  /* output; examples, adjust for task */
  printf("time: %6.2f secs\n",(t2 - t1));

  /* IMPORTANT: also print the result of the code, e.g. the sum, 
   * otherwise compiler might optimise away the code */
  printf("sum: %d\n", sum);
  
  /* free memory; examples, adjust for task */
  //free(a);
  free(a);
  free(b);

  return 0;  
}
