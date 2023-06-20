/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    float K = 0.0f;

    float L = 0.0f;
    
    printf("Enter the weight in kg:");
    scanf("%f" , &K);
    L = (K * 2.205);
    printf("Weight in pounds: %.1f" , L);

    return 0;
}
