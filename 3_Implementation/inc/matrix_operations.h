/**
 * @file matrix_operations.h
 * @author Hemanth A (hemanth.ec17@bmsce.ac.in)
 * @brief A program to calculate various operations on a matrix
 * @version 0.1
 * @date 2021-04-13
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef __MATRIX_OPERATIONS_H__
#define __MATRIX_OPERATIONS_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct{

float **matrix_1;
float **matrix_2;
float **matrix_result;
float *result;

}mat;

/**
 * @brief Inputting the matrix
 * 
 * @param matrix 
 */
float ** alloc_input_matrix(float **matrix, int n);

/**
 * @brief To print the matrix on the screen
 * 
 * @param matrix 
 * @param n 
 */
void output_matrix(float **matrix,int n);

/**
 * @brief Free dynamically allocated memory space
 * 
 * @param m 
 */
void free_matrix_structure(mat *m);

/**
 * @brief 
 * 
 * @param addm 
 * @param n 
 */
void add_matrices(mat *addm,int n);


/**
 * @brief To find the determinant of the matrix
 * 
 * @param matrix 
 * @return float 
 */
float determinant(float *matrix,int n);



#endif  /* #define __MATRIX_OPERATIONS_H__ */