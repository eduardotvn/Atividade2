#include <stdio.h>
#include <omp.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{

    int numSteps = 1000000000;
    double step; 
    int i;
    double x, pi, sum = 0.0;

    double inicio = omp_get_wtime();

    step = 1.0/(double) numSteps;

    int nprocs = omp_get_num_procs()/2;

    printf("Numero de procs: %d\n", omp_get_num_procs());

    #pragma omp parallel num_threads(nrpocs) private(x)
    {
        #pragma omp for reduction(+:sum)
        for( i = 0; i < numSteps; i++)
        {
            x = (i + 0.5) * step; 
            sum = sum + 4.0 / (1.0 + x*x); 
        }
    }

    pi = step * sum;
    double fim = omp_get_wtime();
    printf("%.5f\n", pi);
    printf("%f\n", fim-inicio);

    return 0; 
}