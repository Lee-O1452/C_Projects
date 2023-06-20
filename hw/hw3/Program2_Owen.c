/* 
Program Name: Program2_Owen.c 
Programmer: Lee Owen
Class: CS 3335
HW: 03
Problem: 02
*/
#include <stdio.h>
#include <stdlib.h>
int main (){
    
    int ans = 0, count = 0, i, holding;
    char RPN[50] = " ";
    int operands[50] = {0};
    
    
    
    printf ("Enter an RPN expression:");
    
    scanf ("%[^\n]", RPN);
    // goes over the whole input stream.
    for(i = 0; i < sizeof(RPN); i++){
        //adds the last two of stack then adds result
        if(RPN[i] == '+'){
            holding = operands[count - 1] + operands[count - 2];
            count--;
            count--;
            operands[count] = holding;
            count++;
        }
        //gets the answer
        else if(RPN[i] == '='){
            ans = operands[0];
            break;
        }
        //subtracts the last two of stack then adds result 
        else if(RPN[i] == '-'){
            holding = operands[count - 2] - operands[count - 1];
            count--;
            count--;
            operands[count] = holding;
            count++;
        }
        //multiplies the last two of stack then adds result 
        else if(RPN[i] == '*'){
            holding = operands[count - 1] * operands[count - 2];
            count--;
            count--;
            operands[count] = holding;
            count++;
        }
        //divids the last two of stack then adds result
        else if(RPN[i] == '/'){
            holding = operands[count - 2] / operands[count - 1];
            count--;
            count--;
            operands[count] = holding;
            count++;
        }
        // adds number to stack
        else {
          
          holding = RPN[i] - 48; 
          operands[count] = holding;
          count++;
        }
        
    }
    
    printf ("Value of expression:%d", ans);
 }