 /* 
Program Name: Program1_owen.c 
Programmer: Lee Owen
Class: CS 3335 
HW: 04
Problem: 01 
*/ 

#include <stdio.h>
//pay amount function
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones){
    //get total twenties
    *twenties = dollars / 20;
    dollars -= (20 * *twenties);
    //get total tens
    *tens = dollars / 10;
    dollars -= (10 * *tens);
    //get total fives
    *fives = dollars / 5;
    dollars -= (5 * *fives);
    //get total ones
    *ones = dollars;
}
//main function
int main()
{
    //create varibles
    int dollars, twenties, tens, fives, ones;
    //get dollars
    printf("Enter a dollar amount: ");
    scanf("%d", &dollars);
    //call pay_amount function
    pay_amount(dollars, &twenties, &tens, &fives, &ones);
    //print results
    printf("$20 bills: %d\n$10 bills: %d\n$5 bills: %d\n$1 bills: %d", twenties, tens, fives, ones);

    return 0;
}
