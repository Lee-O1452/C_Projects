#include <stdio.h>

int tribonacci(int num){
    if(num == 1){
        return 0;
    }
    if(num == 2){
        return 1;
    }
    if(num == 3){
        return 1;
    }
    if (num > 2){
        return (tribonacci(num-1)+tribonacci(num-2)+tribonacci(num-3));
    }
}


int main()
{
int num, tri;
printf("Enter an integer:");
scanf("%d",&num);
tri = tribonacci(num);
printf("The Tribonacci value for %d is %d",num,tri);
}
