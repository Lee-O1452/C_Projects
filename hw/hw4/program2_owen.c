/*
Program Name: program2_owen.c 
Programmer: Lee Owen
Class: CS 3335 
HW: 04
Problem: 02 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{   
    //seting variables, pointers, arrays
    int i, l;
    char* half;
    int pal = 1;
    char str[1000000];
    char holding[1000000];
    //getting input string
    printf("Enter a message:");
    fgets(str, 1000000, stdin);
    // normalizing the string to make it easier to work on
    for(i = 0;i<strlen(str); i++){
        if(isalpha(str[i])){    
            holding[l] = tolower(str[i]);
            l++;
        }
    }
    
    //setting my pointers value
    half = &holding[strlen(holding) / 2];

    //finds if the string is a palindrome or not
    for(i = 0; i < strlen(holding) / 2; i++){
        if(strlen(holding) % 2 == 1){
            if(*(half - i) != *(half + i)){
                printf("Not a palindrome");
                pal = 0;
                break;
            }
        }
        else{
            if(*(half - i - 1) != *(half + i)){
                printf("Not a palindrome");
                pal = 0;
                break;
            }
        }
    }
    if(pal == 1){
        printf("Palindrome");
    }    
    
    return 0;
}
