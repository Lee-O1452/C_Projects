#include <stdio.h>

int main()
{
    int n, max, min, i, holding;
    float sum = 0.0,avg;
    printf("Enter n:");
    scanf("%d", &n);
    int a[n];
    printf("Enter the values:");
    for(i=0;i<n;i++){
        scanf("%d", &holding);
        if(i == 0){
            max = holding;
            min = holding;
        }
        if(holding > max){
            max = holding;
        }
        if(holding < min){
            min = holding;
        }
        a[i] = holding;
        sum += holding;
    }
    avg = sum / n;
    printf("Max:%d\n", max);
    printf("Min:%d\n", min);
    printf("Average of elements:%f\n", avg);
    printf("Even index elements:");
    for(i=0;i<n;i=i+2){
        holding = a[i];
        printf("%d\n", holding);
    }
    
    return 0;
}
