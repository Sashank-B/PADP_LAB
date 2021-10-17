#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
#define SEED 35791246

void main(int argc,char **argv)
{
	
 int n=0,i,count=0;
 int n_threads=1;
 double z,pi,x,y;
double st =0.0, end=0.0;
for (n=1000;n<=1000000;n*=10)
{ printf("# of iterations = %d\n",n);
 n_threads=1;
	while(n_threads<=8){
 count=0;
 
	

 srand(SEED);
 st =0.0;
 end=0.0;
 st = omp_get_wtime();
 omp_set_num_threads(n_threads);
 

 #pragma omp parallel for

 for (i = 1; i <n ;i++) {
  x=(double)rand()/RAND_MAX;
  y=(double)rand()/RAND_MAX;
  z=x*x+y*y;
  if(z<=1) count++;
}
pi=(double)count/n*4;
end = omp_get_wtime();
printf("# of threads = %d\ttime taken = %lf\tpi value = %lf\n",n_threads,end-st,pi);
n_threads=n_threads*2;

}}
 
	
}