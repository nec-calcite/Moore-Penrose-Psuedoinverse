#include<stdio.h>
#include"universal.c"
#include"inverse.c"
#include"cholesky.c"

int PrintMatrix(double matrix[], int row, int colomn){
    for (int i=0; i<row; i++){
        for (int j=0; j<colomn; j++){
            printf("%lf ", matrix[i*colomn + j]);
        }
        printf("\n");
    }
}

int main(){

    double A[30];
    for (int i=0; i<30; i++){
        A[i] = i+1;
    }

    double b[10];
    for (int i=0; i<10; i++){
        b[i] = 10 * (i + 1);
    }

    double AT[30];
    Transpose(A, AT, 10, 3);

    double ATA[9];
    MatrixProd(AT, A, ATA, 3, 3, 10);
    printf("ATA is:\n");
    PrintMatrix(ATA, 3, 3);

    double L_temp[9];
    Cholesky(ATA, L_temp, 3);
    printf("L_temp is:\n");
    PrintMatrix(L_temp, 3, 3);

    double L[6];
    for (int i=0; i<3; i++){
        for (int j=0; j<2; j++){
            L[i*2 + j] = L_temp[i*3 + j];
        }
    }
    printf("L is:\n");
    PrintMatrix(L, 3, 2);

    double LT[9];
    Transpose(L, LT, 3, 2);

    double LTL[9];
    MatrixProd(LT, L, LTL, 2, 2, 3);

    double LLT[9];
    MatrixProd(L, LT, LLT, 3, 3, 2);
    printf("LLT is:\n");
    PrintMatrix(LLT, 3, 3);

    double LTL_inv[4];
    Inverse(LTL, LTL_inv, 2);

    double dbl_inv[4];
    MatrixProd(LTL_inv, LTL_inv, dbl_inv, 2, 2, 2);

    double L_dbl_inv[6];
    MatrixProd(L, dbl_inv, L_dbl_inv, 3, 2, 2);

    double L_dbl_inv_LT[9];
    MatrixProd(L_dbl_inv, LT, L_dbl_inv_LT, 3, 3, 2);

    double A_inv[30];
    MatrixProd(L_dbl_inv_LT, AT, A_inv, 3, 10, 3);

    double x[3];
    MatrixProd(A_inv, b, x, 3, 1, 10);
    printf("x is:\n");
    for (int i=0; i<3; i++){
        printf("%lf  ", x[i]);
    }
    printf("\n");

    return 0;
}