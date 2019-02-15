#include <Rcpp.h>
#include <omp.h>

using namespace Rcpp;

// [[Rcpp::export]]
NumericMatrix my_matrix(int I, int J, int nthreads) {
  NumericMatrix A(I,J);
  int i,j,tid;
  omp_set_num_threads(nthreads);
#pragma omp parallel for private(i, j, tid)
  for(int i = 0; i < I; i++) {
    for(int j = 0; j < J; j++) {
      tid = omp_get_thread_num();
      A(i,j) = tid ;
    }
  }
  
  return A;
}

