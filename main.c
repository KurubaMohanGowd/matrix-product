#include <stdio.h>
#include <stdlib.h>

int matrix_mul(int **, int, int, int **, int, int, int **, int, int);

int main()
{
    int **mat_a, **mat_b, **result;

    //read  first matrix rows and columns
    int a_rows,a_cols;
    printf("Enter number of rows : ");
    scanf("%d",&a_rows);
    printf("Enter number of columns : ");
    scanf("%d",&a_cols);

    //allocate memory for first matrix a
    mat_a=malloc(sizeof(int *)*a_rows);
    for(int i=0;i<a_rows;i++)
    {
        mat_a[i]=malloc(sizeof(int)*a_cols);
    }

    //read elements into matrix a
    printf("Enter values for %d x %d matrix :\n",a_rows,a_cols);
    for(int i=0;i<a_rows;i++)
    {
        for(int j=0;j<a_cols;j++)
        {
            scanf("%d",&mat_a[i][j]);
        }
    }

    //read  second matrix rows and columns
    int b_rows,b_cols;
    printf("Enter number of rows : ");
    scanf("%d",&b_rows);
    printf("Enter number of columns : ");
    scanf("%d",&b_cols);

    //check multiplication is possible or not
    if(a_cols!=b_rows)
    {
       puts("Matrix multiplication is not possible");
       return 0;
    }

    //allocate memory for second matrix b
    mat_b=malloc(sizeof(int *)*b_rows);
    for(int i=0;i<b_rows;i++)
    {
        mat_b[i]=malloc(sizeof(int)*b_cols);
    }

    //read elements into matrix b
    printf("Enter values for %d x %d matrix :\n",b_rows,b_cols);
    for(int i=0;i<b_rows;i++)
    {
        for(int j=0;j<b_cols;j++)
        {
            scanf("%d",&mat_b[i][j]);
        }
    }

    //allocate memory for result matrix
    int r_rows,r_cols;
    r_rows=a_rows;
    r_cols=b_cols;
    result=malloc(sizeof(int *)*r_rows);
    for(int i=0;i<r_rows;i++)
    {
        result[i]=malloc(sizeof(int)*r_cols);
    }

    matrix_mul(mat_a,a_rows,a_cols,mat_b,b_rows,b_cols,result,r_rows,r_cols);

    return 0;
}
int matrix_mul(int **mat_a,int a_rows,int a_cols,int **mat_b,int b_rows,int b_cols,int **result,int r_rows,int r_cols)
{

    int i,j,val;

    for(i=0;i<r_rows;i++)
    {
        //multiply a[i][c] and b[c][j] and add those values for each row
        for(j=0;j<r_cols;j++)
        {
            val=0;
            for(int c=0;c<a_cols;c++)
            {
                val+=mat_a[i][c]*mat_b[c][j];
            }
            //insert that avlue into result[i][j] index
            result[i][j]=val;
        }
    }
    // print the elements in result matrix
    printf("Product of two matrix :\n");
    for(i=0;i<r_rows;i++)
    {
        for(j=0;j<r_cols;j++)
        {
            printf("%d ",*(*(result+i)+j));
        }
        putchar('\n');
    }
}
