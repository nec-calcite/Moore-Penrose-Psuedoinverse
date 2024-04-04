#include<stdio.h>
#include<math.h>

int Cholesky(double A[], double L[], int size){
    for (int i=0; i<size; i++){
        for (int j=0; j<=i; j++){
            double sum = 0;
            for (int k=0; k<j; k++){
                sum += L[i*size + k] * L[j*size + k];
            }

            if (i==j){
                L[i*size + i] = sqrt(A[i*size + i] - sum);
            }else{
                L[i*size + j] = (1.0 / L[j*size + j] * (A[i*size + j] - sum));
            }
        }
    }
    return 0;
}
