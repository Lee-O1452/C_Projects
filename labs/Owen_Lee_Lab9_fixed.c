#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char holding[20], answer[20];
    int n, i=1;
    
    printf("Enter n:");
    scanf("%d", &n);
    getchar();
    for(;n>0; n--){
        printf("Enter word:");
        fgets(holding, 20, stdin);
        
        if(i==1){
            strncpy(answer,holding,sizeof(answer) - 1);
            i--;
        }
        if(i==0){
            if(strlen(holding)>strlen(answer)){
                strncpy(answer,holding,sizeof(answer) - 1);    
            }
            
        }  
        printf("\n");
        
        
    }
    printf("Answer:");
    for(i=0;i<strlen(answer);i++){
        printf("%c",answer[i]);
    }
 
 
    return 0;   
}