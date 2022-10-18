#include<stdio.h>
#include<stdlib.h>
#define MAX 100

typedef struct
{
         int row;
         int col;
         int val;
}sparse;

void readsparse(sparse a[])
{
         int i, j, k, item, p,n,m;
        printf("\nEnter  the no of rows and columns:\t");
        scanf("%d%d",&m, &n);
         a[0].row = m;
         a[0].col = n;
         k = 1;

        printf("\nEnter the elements:\n");
        for(i=0; i<m; i++)
       {
              for(j=0; j<n; j++)
             {
                    scanf("%d", &item);
                    if(item == 0)
                         continue;
                    a[k].row = i;
                    a[k].col = j;
                    a[k].val = item;
                     k++;
               }
        }
        a[0].val = k-1;


void sparseAdd(sparse a[],sparse b[],sparse sum[])
{
    int i=1,j=1,l=1;
    if(a[0].row!=b[0].row || a[0].col!=b[0].col)
    {
        printf("Cannot Add !");
        exit(0);
    }
    sum[0].row=a[0].row;
    sum[0].col=a[0].col;
    while(i<=a[0].val && j<=b[0].val)
    {
        if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col))
        {
            sum[l].row=a[i].row;
            sum[l].col=a[i].col;
            sum[l].val=a[i].val;
            i++;
            l++;
        }
        else if(a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col))
        {
            sum[l].row=b[j].row;
            sum[l].col=b[j].col;
            sum[l].val=b[j].val;
            j++;
            l++;
        }
        else if(a[i].row==b[j].row && a[i].col==b[j].col)
        {
            sum[l].row=a[i].row;
            sum[l].col=a[i].col;
            sum[l].val=a[i].val+b[j].val;
            j++;
            i++;
            l++;
        }
    }
    while(i<=a[0].val)
    {
        sum[l].row=a[i].row;
        sum[l].col=a[i].col;
        sum[l].val=a[i].val;
        i++;
        l++;
    }
    while(j<=b[0].val)
    {
        sum[l].row=b[j].row;
        sum[l].col=b[j].col;
        sum[l].val=b[j].val;
        j++;
        l++;
    }
    sum[0].val=l-1;
    
}
void printsparse(sparse a[])
{
        int p;
        printf("\nThe entered sparse matrix is:\n");
        printf("\nRow\tColumn\tValue\n");
        for(p=0; p<=a[0].val; p++)
        {
                 printf("%d\t", a[p].row);
                 printf("%d\t", a[p].col);
                 printf("%d\n", a[p].val);
         }
}
}

void main()
{
           
           sparse a[MAX],b[MAX],sum[MAX];
           
           readsparse(a);
           printsparse(a);
           readsparse(b);
           printsparse(b);
           sparseAdd(a,b,sum);
           printsparse(sum;



}