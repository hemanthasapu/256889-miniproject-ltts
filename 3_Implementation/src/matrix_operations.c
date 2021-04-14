#include "matrix_operations.h"
#include <math.h>

void free_matrix_structure(mat *m){
    free(m->matrix_1);
    free(m->matrix_2);
    free(m->matrix_result);
}

void dynamic_alloc_mat(float **matrix,int n){
    matrix = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        matrix[i] = (float *)calloc(n,sizeof(float));
    }
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
            matrix[i][j]= element;
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
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n\n\n");
}



float ** add_matrices(float **matrix1,float **matrix2, int n){
    int i,j;
    float **result;
    result = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        result[i] = (float *)calloc(n,sizeof(float));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
    free(result);
}

float ** subtract_matrices(float **matrix1,float **matrix2, int n){
    int i,j;
    float **result;
    result = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        result[i] = (float *)calloc(n,sizeof(float));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
    free(result);
}

float ** product_matrices(float **matrix1,float **matrix2, int n){
    int i,j,k;
    float **result;
    result = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        result[i] = (float *)calloc(n,sizeof(float));
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            result[i][j] = 0;
            for(k = 0;k < n; k++){
            result[i][j]+= matrix1[i][k] * matrix2[k][j];
            }
    }
    }
    return result;
    free(result);
}


float determinant(float **matrix,int k)
{

    float s = 1, det = 0, **b;
    b = (float **)calloc(k,sizeof(float));
    for(int i=0;i<k;i++){
        b[i] = (float *)calloc(k,sizeof(float));
    }
  int i, j, m, n, c;
  if (k == 1)
    {
     return (matrix[0][0]);
    }
  else
    {
     det = 0;
     for (c = 0; c < k; c++)
       {
        m = 0;
        n = 0;
        for (i = 0;i < k; i++)
          {
            for (j = 0 ;j < k; j++)
              {
                b[i][j] = 0;
                if (i != 0 && j != c)
                 {
                   b[m][n] = matrix[i][j];
                   if (n < (k - 2))
                    n++;
                   else
                    {
                     n = 0;
                     m++;
                     }
                   }
               }
             }
          det = det + s * (matrix[0][c] * determinant(b, k - 1));
          s = -1 * s;
          }
    }
 
    return (det);
    free(b);
}

float ** inverse(float **num, int f)
{
 float **b, **fac,**transp, **invers, d;

    int mem;
    b = (float **)calloc(f,sizeof(float));
    fac = (float **)calloc(f,sizeof(float));
    transp = (float **)calloc(f,sizeof(float));
    invers = (float **)calloc(f,sizeof(float));
    for(int mem=0;mem<f;mem++){
        b[mem] = (float *)calloc(f,sizeof(float));
        fac[mem] = (float *)calloc(f,sizeof(float));
        transp[mem] = (float *)calloc(f,sizeof(float));
        invers[mem] = (float *)calloc(f,sizeof(float));
    }


 int p, q, m, n, i, j;
 for (q = 0;q < f; q++)
 {
   for (p = 0;p < f; p++)
    {
     m = 0;
     n = 0;
     for (i = 0;i < f; i++)
     {
       for (j = 0;j < f; j++)
        {
          if (i != q && j != p)
          {
            b[m][n] = num[i][j];
            if (n < (f - 2))
             n++;
            else
             {
               n = 0;
               m++;
               }
            }
        }
      }
      fac[q][p] = pow(-1, q + p) * determinant(b, f - 1);
    }
  }

  d = determinant(num, f);
  transp = transpose(fac,f);
  for (i = 0;i < f; i++)
    {
     for (j = 0;j < f; j++)
       {
        invers[i][j] = transp[i][j] / d;
        }
    }
  return invers;
  free(b);
  free(fac);
  free(transp);
  free(invers);
}


float ** transpose(float **matrix,int n){
    float **result;
    int i,j;
    result = (float **)calloc(n,sizeof(float));
    for(int i=0;i<n;i++){
        result[i] = (float *)calloc(n,sizeof(float));
    }
    for (i = 0;i < n; i++)
    {
     for (j = 0;j < n; j++)
       {
         result[i][j] = matrix[j][i];
        }
    }
    return result;
    free(result);
}


