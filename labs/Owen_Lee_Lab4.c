/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int num, holding, i, l;
    
    printf("Enter the number of lines: ");
    
    scanf("%d", &num);
    holding = num;
    
    for(i = 1; i <= num; i++){
        for(l = 1; l <= num; l++){
            if(l >= holding){
                printf("%d", i);
            }
            else{
                printf(".");
            }
            
        }
        holding--;
        printf("\n");
    }
}
