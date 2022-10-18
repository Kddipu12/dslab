#include<stdio.h>
#include<math.h>
typedef struct Polynomial
{
    int coeff;
    int exp;
}Polynomial;

Polynomial first[15];
void display(Polynomial poly[], int terms)
{
    int i;
    printf("\n");
    printf("%dX^%d ", poly[0].coeff, poly[0].exp);
    for(i = 1; i < terms ; i++)
    {
        printf("+%dX^%d ", poly[i].coeff, poly[i].exp);
    }
}

int readExpression(Polynomial poly[])
{
    int terms, i;
    printf("\nNumber of terms: ");
    scanf("%d", &terms);
    printf("\nEnter the coeffecients and exponents in DESCENDING order");
    for(i = 0 ; i<terms; i++)
    {
        printf("\nCoeffecient :");
        scanf("%d", &poly[i].coeff);
        printf("Exponent :");
        scanf("%d", &poly[i].exp);
    }
    return terms;
}
int evalExpressions(Polynomial poly[], int terms,int x)
{
    int i,sum=0;
    for(i = 0;i < terms; i++)
    {
        
        sum+=(poly[i].coeff)*pow(x,poly[i].exp);
    }
    return sum;


}
int main()
{
    int firstCount, resultSum,x;
    printf("\nFirst Expression:\n");
    firstCount = readExpression(first);
    printf("\nFirst Expression");
    display(first, firstCount);
    printf("\nEnter the value for x\n");
    scanf("%d",&x);
    resultSum=evalExpressions(first,firstCount,x);
    printf("\nThe sum is %d\n",resultSum);


}