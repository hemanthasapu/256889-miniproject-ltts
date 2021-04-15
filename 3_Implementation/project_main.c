#include "matrix_operations.h"

/* Status of the operation requested */
#define VALID   (1)
#define INVALID (0)

/* Calculator operation requested by user*/
unsigned int matrixcalc_operation = 0;

/* Operands on which calculation is performed */
int n;
mat operands;
error_t err;
/* Valid operations */
enum operations{ DET=1,ADD,SUB,MUL,TRN,INV,EXIT };

/* Display the menu of operations supported */
void calculator_menu(void);
/* Verifies the requested operations validity */
int valid_operation(int operation);


/* Start of the application */
int main(int argc, char *argv[])
{
    printf("\n****WELCOME TO THE MATRIX OPERATIONS PROGRAM****\n");
    while(1)
    {
        calculator_menu();
    }
}

void calculator_menu(void)
{
    printf("\nPress a key to select the appropriate operation\n");
    printf("\n1. Determinant\n2. Addition of matrices\n3. Subtraction of matrices\n4. Product of matrices\n5. Transpose of a matrix\n6. Inverse of a matrix\n7. Exit");
    printf("\n\tEnter your choice\n");
   
     // __fpurge(stdin);
    scanf("%d", &matrixcalc_operation);

    if(EXIT == matrixcalc_operation)
    {
        printf("\nThank you. Exiting the Application\n");
        exit(0);
    }

    if(INVALID != valid_operation(matrixcalc_operation))
    {
        printf("\n\tEnter your matrix elements with space between them\n");

        printf("Enter order of matrix: ");
        scanf("%d", &n);
        operands.matrix_1 = alloc_input_matrix(operands.matrix_1,n);
        if(((matrixcalc_operation != DET )&&(matrixcalc_operation != TRN )&&(matrixcalc_operation != INV))){
            operands.matrix_2 = alloc_input_matrix(operands.matrix_2,n);
        }
    }
    else
    {
        printf("\n\t---Wrong choice---\nEnter to continue\n");
        // __fpurge(stdin);
        getchar();
        return;
        
    }
    switch(matrixcalc_operation)
    {
        case DET:
            operands.result = determinant(operands.matrix_1,n);
            printf("Determinant of the matrix is: %f \n\n\n",operands.result);
            break;
        case ADD:
            err = add_matrices(operands.matrix_1,operands.matrix_2,n);
            free_matrix_structure(&operands);
            break;
        case SUB:
            err = subtract_matrices(operands.matrix_1,operands.matrix_2,n);
            free_matrix_structure(&operands);
            break;
        case MUL:
            err = product_matrices(operands.matrix_1,operands.matrix_2,n);
            free_matrix_structure(&operands);
            break;
        case TRN:
            dynamic_alloc_mat(operands.matrix_result,n);
            operands.matrix_result = transpose(operands.matrix_1,n);
            printf("The transpose of the matrix is: \n");
            output_matrix(operands.matrix_result,n);
            free_matrix_structure(&operands);
            break;
        case INV:
            if(determinant(operands.matrix_1,n) == 0.00){
                printf("Inverse cannot be found..! \n");
            }
            else{
                err = inverse(operands.matrix_1,n);
                free_matrix_structure(&operands);
            }
            break;
        case EXIT:
            free_matrix_structure(&operands);
            exit(0);
            break;
        default:
            printf("\n\t---It should never come here---\n");
    }
}

int valid_operation(int operation)
{
    /* Check if the operation is a valid operation */
    return ((DET <= operation) && (EXIT >= operation)) ? VALID: INVALID;
}