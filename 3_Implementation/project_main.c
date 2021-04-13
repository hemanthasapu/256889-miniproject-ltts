#include <matrix_operations.h>

/* Status of the operation requested */
#define VALID   (1)
#define INVALID (0)

/* Calculator operation requested by user*/
unsigned int matrixcalc_operation = 0;

/* Operands on which calculation is performed */
int n;
mat operands;
/* Valid operations */
enum operations{ DET=1,ADD,EXIT };

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
    printf("\nAvailable Operations\n");
    printf("\n1. Determinant\n2. Addition of matrices\n3. Exit");
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
        if(matrixcalc_operation != DET){
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
            //printf("Determinant of the matrix is: %f",determinant(operands.matrix_1,n));
            output_matrix(operands.matrix_1,n);
            // __fpurge(stdin);
            getchar();
            break;
        case ADD:
            dynamic_alloc_mat(operands.matrix_result,n);
            operands.matrix_result = add_matrices(operands.matrix_1,operands.matrix_2,n);
            printf("The sum of the matrices is: \n");
            output_matrix(operands.matrix_result,n);
            free_matrix_structure(&operands);
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