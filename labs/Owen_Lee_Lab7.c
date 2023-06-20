#include <stdio.h>

double compute_inner_sq_diff(double *a, double *b, int n){
    int i;
    double result = 0;
    for(i = 0; i<n; i++){
        result = result + ((*(a+i)-*(b+i))*(*(a+i)-*(b+i)));
    }
    return result;
}

int main()
{
    int n, i;

    printf("Enter n:");
    scanf("%d", &n);
    double a[n], b[n], result;
    printf("enter values of a:");
    for(i=0;i<n;i++){
        scanf("%lf", &a[i]);
    }
    printf("enter values of b:");
    for(i=0;i<n;i++){
        scanf("%lf", &b[i]);
    }
    result = compute_inner_sq_diff(&a, &b, n);
    printf("%lf", result);
    
    return 0;
}
