/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int computeFactorial(int n);
int computeFactorial(int n){
   
   int factN = n;
   
   for(int i = n; i > 1; i--)
   {
    factN = factN * (i-1); 
   }
   
   
   return factN; 
}
    


int main()
{
    int n, factN;
    
    printf ("Enter n:");
    scanf ("%d", &n);
    if (n < 0){
        printf("The factorial of %d is: undefind", n);
        
    }
    if (n == 0){
        printf("The factorial of %d is: 1", n);
    }
    if (n > 0){
        factN = computeFactorial(n);
        printf("The factorial of %d is: %d", n, factN);
    }
    return 0;
}
