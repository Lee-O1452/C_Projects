/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int input = 0;
    int tens = 0;
    int ones = 0;
    int output = 0;
    
    printf("enter a two digit number.");
    scanf("%d",&input);
    
    tens = input / 10;
    ones = input % 10;
    output = (tens * tens * tens) + (ones * ones * ones);
    printf("%d",output);
    

    return 0;
}
