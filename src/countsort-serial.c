#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// Function that sorts a vector `a` of size `n`
double count_sort(double a[], int n) {
  int i, j, count;
  double *temp;
  double start, end, duracao;

  temp = (double *)malloc(n * sizeof(double));

  start = omp_get_wtime();
  for (i = 0; i < n; i++) {
    count = 0;
    for (j = 0; j < n; j++)
      if (a[j] < a[i])
        count++;
      else if (a[j] == a[i] && j < i)
        count++;
    temp[count] = a[i];
  }
  end = omp_get_wtime();

  duracao = end - start;

  memcpy(a, temp, n * sizeof(double));
  free(temp);

  return duracao;
}

int main(int argc, char *argv[]) {
  int i, n, nt;
  double *a, t_s;

  scanf("%d", &nt);

  // Read the number of elements
  scanf("%d", &n);

  // Allocate the vector to be ordered
  a = (double *)malloc(n * sizeof(double));

  // Populate the vector
  for (i = 0; i < n; i++)
    scanf("%lf", &a[i]);

  // Execute Counting Sort
  t_s = count_sort(a, n);

  // Print the ordered vector
  for (i = 0; i < n; i++)
    printf("%.2lf ", a[i]);

  printf("\n");

  // Print the time it took to sort
  fprintf(stderr, "%lf\n", t_s);

  return 0;
}
