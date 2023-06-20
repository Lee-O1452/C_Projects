/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int num, awnser = 0, holding, i;
    
    printf("Enter a number: ");
    
    scanf("%d", &num);
    
    holding = num / 3; 
    if(num % 3 == 0){
	holding--;
    }
    for (i = 1; i <= holding; ++i){
        awnser= awnser + (3 * i);
    }
    
    printf("sum of all positive multiples of 3 that are less than %d is: %d", num, awnser);

    return 0;
}
