/*
It solve sudoku.
It take input as 2D array and vacent place occupy by zero (0).
It return No solution if no found any solution for given sudoku.
*/
#include<stdio.h>
int SolveSudoku(int n,int sudoku[n][n],int ,int);
int CheckValid(int n,int sudoku[n][n],int ,int ,int);
int rowfind(int n,int sudoku[n][n],int ,int );
int colfind(int n,int sudoku[n][n],int ,int  );
int boxfind(int n,int sudoku[n][n],int k,int row,int col);
int main()
{
    int n=9;
    int sudoku[n][n];
    for(int i=0;i<n;i++)
      for(int j=0;j<n;j++)
         scanf("%d",&sudoku[i][j]);
    
    int temp=SolveSudoku(n,sudoku,0,0);
    if(temp)
    {
       for(int i=1;i<=n;i++)
       {
          if(i==1) 
          printf("_________________________\n");
          for(int j=1;j<=n;j++)
          {
             if(j==1)
               printf("| ");
             printf("%d ",sudoku[i-1][j-1]);
             if(j%3==0)
             printf("| ");
          }
          printf("\n");
          if(i%3==0)
             printf("_________________________\n");
       }
    }
    else 
      printf("No Solution");
    return 0;
    
}

int SolveSudoku(int n,int sudoku[n][n],int row,int col)
{
    if(col>=n)
    {
        row++;
        col=0;
    }
    if(row>=n)
    {
        return 1;
    }
    else if(sudoku[row][col]!=0)
       return SolveSudoku(n,sudoku,row,col+1);
    for(int num=1;num<=n;num++)
    {
        if(CheckValid(n,sudoku,num,row,col))
        {
            sudoku[row][col]=num;
            if(SolveSudoku(n,sudoku,row,col+1))
               return 1;
            sudoku[row][col]=0;
        }
    }
    return 0;
}

int CheckValid(int n,int sudoku[n][n],int num,int row,int col)
{
    int rowvalid=rowfind(n,sudoku,num,row);
    int colvalid=colfind(n,sudoku,num,col);
    int boxvalid=boxfind(n,sudoku,num,row,col);
    return ((!rowvalid) && (!colvalid) && (!boxvalid));
}
int rowfind(int n,int sudoku[n][n],int k,int row)
{
    for(int i=0;i<n;i++)
    {
        if(sudoku[row][i]==k)
          return 1;
    }
    return 0;
}
int colfind(int n,int sudoku[n][n],int k,int col)
{
    for(int i=0;i<n;i++)
    {
        if(sudoku[i][col]==k)
          return 1;
    }
    return 0;
}
int boxfind(int n,int sudoku[n][n],int k,int row,int col)
{
    for(int i=0;i<9;i=i+3)
        for(int j=0;j<9;j=j+3)
            if((i<=row)&&(row<i+3)&&(j<=col)&&(col<j+3))
                for(int a=i;a<=i+2;a++)
                    for(int b=j;b<=j+2;b++)
                        if(sudoku[a][b]==k)
                          return 1;
    return 0;
}
