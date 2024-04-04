// This only works for NxN matrix

int GetCofactor(double matrix[], double cofactor[], int size, int row, int colomn){

    int cross_row = 0;
    for (int i=0; i<size; i++){
        if (i==row){
            cross_row = 1;
        }else{
            int cross_colomn = 0;
            for (int j=0; j<size; j++){
                if (j==colomn){
                    cross_colomn = 1;
                }else{
                    cofactor[(i - cross_row)*(size - 1) + (j - cross_colomn)] = matrix[i*size + j];
                }
            }
        }
    }

    return 0;
}

double Determinant(double matrix[], int size){

    double det = 0;

    if (size==1){
        return matrix[0];
    }

    double temp[(size - 1)*(size - 1)];
    
    int sign = 1;
    for (int i=0; i<size; i++){
        GetCofactor(matrix, temp, size, 0, i);
        det += sign * matrix[i] * Determinant(temp, size-1);
        sign = -sign;
    }
    return det;
}

int Adjoint(double matrix[], double adjoint[], int size){
    if (size==1){
        adjoint[0] = 1;
        return 0;
    }

    int row_sign = 1;
    double temp[(size-1) * (size-1)];
    for (int i=0; i<size; i++){
        int sign = row_sign;
        for (int j=0; j<size; j++){
            GetCofactor(matrix, temp, size, i, j);
            adjoint[j*size + i] = sign * Determinant(temp, size-1);
            sign = -sign;
        }
        row_sign = -row_sign;
    }

    return 0;
}

int Inverse(double matrix[], double inverse[], int size){

    double det = Determinant(matrix, size);

    if (det == 0){
        printf("Singular matrix, cannot find its inverse");
        return 1;
    }

    double adjoint[size*size];
    Adjoint(matrix, adjoint, size);

    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            inverse[i*size + j] = adjoint[i*size + j]/det;
        }
    }

    return 0;
}
