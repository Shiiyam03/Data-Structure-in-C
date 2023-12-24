#include <stdio.h>
#include <math.h>

struct poly
{
    int coefficient;
    int exponent;
};

int main()
{
    int i;
    int deg1, deg2;
    int k = 0, l = 0, m = 0;

    printf("Enter the highest degree of polynomial 1:");
    scanf("%d", &deg1);

    struct poly a[deg1 + 1];

    for (i = 0; i <= deg1; i++)
    {
        printf("\nEnter the coeff of x^%d :", i);
        scanf("%d", &a[i].coefficient);
        a[k++].exponent = i;
    }

    printf("\nEnter the highest degree of polynomial 2:");
    scanf("%d", &deg2);

    struct poly b[deg2 + 1];

    for (i = 0; i <= deg2; i++)
    {
        printf("\nEnter the coeff of x^%d :", i);
        scanf("%d", &b[i].coefficient);
        b[l++].exponent = i;
    }

    // Assuming the result polynomial won't exceed the sum of degrees
    struct poly c[deg1 + deg2 + 1];

    if (deg1 > deg2)
    {
        for (i = 0; i <= deg2; i++)
        {
            c[m].coefficient = a[i].coefficient + b[i].coefficient;
            c[m].exponent = a[i].exponent;
            m++;
        }

        for (i = deg2 + 1; i <= deg1; i++)
        {
            c[m].coefficient = a[i].coefficient;
            c[m].exponent = a[i].exponent;
            m++;
        }
    }
    else
    {
        for (i = 0; i <= deg1; i++)
        {
            c[m].coefficient = a[i].coefficient + b[i].coefficient;
            c[m].exponent = a[i].exponent;
            m++;
        }

        for (i = deg1 + 1; i <= deg2; i++)
        {
            c[m].coefficient = b[i].coefficient;
            c[m].exponent = b[i].exponent;
            m++;
        }
    }

    printf("\nExpression after addition  = %d", c[0].coefficient);
    for (i = 1; i < m; i++)
    {
        printf(" + %d x^%d", c[i].coefficient, c[i].exponent);
    }

    return 0;
}
