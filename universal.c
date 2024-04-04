int Transpose(double matrix[], double matrix_t[], int row_size, int colomn_size){
    for (int i=0; i<row_size; i++){
        for (int j=0; j<colomn_size; j++){
            matrix_t[j*row_size + i] = matrix[i*colomn_size + j];
        }
    }
    return 0;
}

int MatrixProd(double matrix1[], double matrix2[], double matrix_p[], int row_size, int colomn_size, int contract_size){
    for (int i=0; i<row_size; i++){
        for (int j=0; j<colomn_size; j++){
            matrix_p[i*colomn_size + j] = 0;
            for (int k=0; k<contract_size; k++){
                matrix_p[i*colomn_size + j] += matrix1[i*contract_size + k] * matrix2[k*colomn_size + j];
            }
        }
    }
    return 0;
}