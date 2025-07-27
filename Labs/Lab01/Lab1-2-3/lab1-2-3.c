// general purpose standard C lib
#include <stdio.h>
#include <stdlib.h> // stdlib includes malloc() and free()
#define MAX_TEMP_SIZE 300
// user-defined header files
#include "chain.h"

// function prototypes
void print_chain(chain * chn); 
void run(chain * chn);


int main()
{
    chain * chn = (chain *) malloc(sizeof(chain));
    chn->head = NULL;
	run(chn);
    print_chain(chn);
    free(chn);
	return 0;
}
// populate num 
void populate_arr(int num[],int num_columns, int num_of_rows,char temp[] ){
    int indx = 0;

    for (int i =0; i < num_columns*2; i++){
        num[indx] = (int)(temp[i]) -48;
        indx ++;
        i ++;
        if (indx > num_columns){
            break;
        }
    }
    for (int i = 0; i < num_columns*(num_of_rows-1); i++){
        int input;
        scanf("%i", &input);
        num[num_columns+i] = input;
    }
}
// increment matrix values 
void incrementMatrixValues(matrix *mat, int num[], int num_columns,int num_of_rows){
    int point = 0;
    for (int i = 0; i < mat->num_rows; i++){
        for (int j = 0; j < mat->num_cols; j++){
            mat->data[i][j] = num[point];
            point++;

        }
    }
}
// process of the first row 
void process_first_row(char temp[] , int *num_of_coloum){
    if (fgets(temp, MAX_TEMP_SIZE,stdin) != NULL){
        fgets(temp, MAX_TEMP_SIZE,stdin);
    }
    *num_of_coloum = 0;
    for (int i =0 ; i < 29; i++){
        if ((temp[i] == ' ' && temp[i+1] == ' ') || (((int)(temp[i])) < 48 || ((int)(temp[i])) > 57)){
            break; 
        } 
        i += 1;
        (*num_of_coloum) ++;
    }
}
// get a copy
matrix *get_copy(matrix *mat){
    matrix *copy = malloc(sizeof(mat));
    copy->num_cols =mat->num_cols;
    copy->num_rows = mat->num_rows;

    int num_rows = mat->num_rows;
    int num_column = mat->num_cols;

    int **row = malloc(sizeof(int *)*num_rows);
    int *col;
    for (int i = 0; i < num_rows; i++){
        col = malloc(sizeof(int *)*num_column);
        for (int j = 0; j < num_column; j++){
            col[j] = mat->data[i][j];
        }
        row[i] = col;
        
    }
    copy->data = row;
    return copy;

}
void handleCommand(matrix *mat, node **curr_node, chain *chn, int command){
    switch (command)
    {
    case 2:
        {
            int row[mat->num_cols];
            for (int i = 0; i < mat->num_cols; i++){
                int in_1 = 0;
                scanf("%i", &in_1);
                row[i] = in_1;
            }
            add_row(mat, row);
            break;

        }
    case 3:
        {
            int col[mat->num_rows];
            for ( int i = 0; i < mat->num_rows; i++){
                int in_1 = 0;
                scanf("%i", &in_1);
                col[i] = in_1;
            }
            add_col(mat, col);
            break;
        }
    case 4: 
        {
            int factor = 0;
            scanf("%i", &factor);
            increment(mat, factor);
            break;
        }
    case 5 :
        {
            int factor = 0;
            scanf("%i", &factor);
            scalar_multiply(mat, factor);
            break;
        }
    case 6:
        {
            int factor = 0;
            scanf("%i", &factor);
            scalar_divide(mat, factor);
            break;
        }
    case 7:
        {
            int factor = 0;
            scanf("%i", &factor);
            scalar_power(mat, factor);
            break;
        }
    default:
        return;
    }
    node *node1 = malloc(sizeof(node));
    node1->prev = *curr_node;
    node1->next = NULL;
    node1->mat = get_copy(mat);
    (*curr_node)->next = node1;
    *curr_node = (*curr_node)->next;
}

void processCommands(chain *chn, matrix* mat){
    node *curr_node = chn->head;
    int in_0 = 0;
    scanf("%i", &in_0);


    while( in_0 != 0){
        handleCommand(mat, &curr_node, chn, in_0);
        scanf("%i", &in_0);
    }
}


// parse the input
void run(chain *chn) 
{
	// get the num of rows 
    int num_of_rows;
    scanf("%i", &num_of_rows);

    char temp[300];
    int num_columns;

    process_first_row(temp, &num_columns);
    int num[num_columns*num_of_rows];
    // populate the arr
    populate_arr(num, num_columns, num_of_rows, temp );
    // create the matrix 
    matrix *mat = create_matrix(num_of_rows, num_columns);

    // increment matrix values 
    incrementMatrixValues(mat, num, num_columns,num_of_rows);

    node *node1 = malloc(sizeof(node));
    node1->prev = NULL;
    node1->next = NULL;
    node1->mat = get_copy(mat);
    chn->head = node1;

    // commands
    processCommands(chn, mat);






}; 

//Print the chain
void print_chain(chain * chn)
{
    node * current = chn->head;
    while(current != NULL){
        print_matrix(current->mat);
        printf("\n");
        current = current->next;
    }
    printf("\n");

}

