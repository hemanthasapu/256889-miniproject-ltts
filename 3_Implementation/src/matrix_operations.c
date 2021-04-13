#include <matrix_operations.h>


void free_matrix_structure(mat *m){
    free(m->matrix_1);
    free(m->matrix_2);
    free(m->matrix_result);
    free(m->result);
}

float ** alloc_input_matrix(float **matrix,int n){
    int i,j;
    matrix = (float **)calloc(n,sizeof(float));
    for(i=0;i<n;i++){
        matrix[i] = (float *)calloc(n,sizeof(float));
    }

    float element;
    printf("Enter the matrix: \n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            scanf("%f", &element);
            **(matrix + i*n + j) = element;
        }
    }
    return matrix;
}

void output_matrix(float **matrix,int n){
    int i,j;
    float x;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            //x = **(matrix + i*n + j);
            printf("%f", (matrix + i*n + j));
        }
    }
}

/*

void add_matrices(mat *addm, int n){
    int i,j;
    float mat1[10][10];
    float mat2[10][10];
    float result[10][10];
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            mat1[i][j] = *(addm->matrix_1 + i*n + j);
            mat2[i][j] = *(addm->matrix_2 + i*n + j);
            result[i][j] = mat1[i][j] + mat2[i][j];
            *(addm->matrix_result + i*n + j) = result[i][j];
        }
    }
        
}
float determinant(float *matrix,int n)
    {
    float ratio, det;
    int i, j, k;
    /* Conversion of matrix to upper triangular 
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(j>i){
                ratio = *(matrix + j*n + i)/ *(matrix + i*n + i);
                for(k = 0; k < n; k++){
                    *(matrix + j*n + k) -= ratio * *(matrix + i*n + k);
                }
            }
        }
    }
    det = 1; //storage for determinant
    for(i = 0; i < n; i++)
        det *= *(matrix + i*n + i);
    return det;
    
}

*/