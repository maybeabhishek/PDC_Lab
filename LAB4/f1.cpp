# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <time.h>
# include <omp.h>
#define chunk 40
int main ( void );
int n = 400;
int main ( void )
{
  double a[n][n];
  double angle;
  double b[n][n];
  double c[n][n];
  int i;
  int j;
  int k;
  
  int th = omp_get_max_threads ( );

  printf ( "Number of processors: %d\n", omp_get_num_procs ( ) );
  printf ( "Num threads: %d\n", th );
  printf ( "Matrix order: %d\n", n );

  double wtime = omp_get_wtime ( );
    srand(time(0));
# pragma omp parallel shared ( a, b, c, n) private ( i, j, k )
{
  # pragma omp for
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      a[i][j] = rand()%100;
    }
  }

  # pragma omp for
  for ( i = 0; i < n; i++ )
  {
    for ( j = 0; j < n; j++ )
    {
      b[i][j] = rand()%100;
    }
  }

  # pragma omp for schedule(static)
  for ( i = 0; i < n; i++ )
  {
    # pragma omp for schedule(static)
    for ( j = 0; j < n; j++ )
    {
      c[i][j] = 0.0;
      # pragma omp for schedule(static)
      for ( k = 0; k < n; k++ )
      {
        c[i][j] = c[i][j] + a[i][k] * b[k][j];
      }
    }
  }

}
  wtime = omp_get_wtime ( ) - wtime;
  printf ( "Time: %g\n", wtime );
  


  return 0;
}

