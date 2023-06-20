/* 
Program Name: Project1_Owen.c
Programmer: J. Lee Owen
Class: CS 3335
Project: 01
*/

#include <stdio.h>


/*
created a swap helper function to make the math easier.
I had to use pointers to make the function work.
I learned the basics of pointers here: 
https://www.tutorialspoint.com/cprogramming/c_pointers.htm
*/
void
Swap (int *v1, int *v2)
{
  int hold;
  hold = *v1;
  *v1 = *v2;
  *v2 = hold;
}

//days in the year calculation function.
int
daysInYear (int year)
{
  if (year % 4 == 0 && year % 100 != 0)
    {
      return 366;
    }
  else
    {
      return 365;
    }

}

//days in a month calculation function 
int
daysInMonth (int month, int year)
{
  if (month == 1)
    {
      return 31;
    }
  if (month == 2 && daysInYear (year) == 365)
    {
      return 28;
    }
  if (month == 2 && daysInYear (year) == 366)
    {
      return 29;
    }
  if (month == 3)
    {
      return 31;
    }
  if (month == 4)
    {
      return 30;
    }
  if (month == 5)
    {
      return 31;
    }
  if (month == 6)
    {
      return 30;
    }
  if (month == 7)
    {
      return 31;
    }
  if (month == 8)
    {
      return 31;
    }
  if (month == 9)
    {
      return 30;
    }
  if (month == 10)
    {
      return 31;
    }
  if (month == 11)
    {
      return 30;
    }
  if (month == 12)
    {
      return 31;
    }
}

//main function.
int
main ()
{
  int month1, month2, day1, day2, year1, year2;
  int totalDays = 0, month1daystotal = 0, month2daystotal = 0;

  //gets the first date
  printf ("Enter the first date:");
  scanf ("%d/%d/%d", &month1, &day1, &year1);

  //gets the second date
  printf ("Enter the second date:");
  scanf ("%d/%d/%d", &month2, &day2, &year2);

  // makes sure the date1 entered can be processed.
  while (12 < month1 || month1 < 1 || 31 < day1 || day1 < 1 || year1 < 0
	 || 10000 < year1)
    {
      printf ("Enter the first date:");

      scanf ("%d/%d/%d", &month1, &day1, &year1);
    }

  // makes sure the date2 entered can be processed.
  while (12 < month2 || month2 < 1 || 31 < day2 || day2 < 1 || year2 < 0
	 || 10000 < year2)
    {
      printf ("Enter the second date:");

      scanf ("%d/%d/%d", &month2, &day2, &year2);
    }

  //swaps the dates around so that date 1 is less than date 2.
  if (year1 > year2 || year1 == year2 && month1 > month2 || year1 == year2
      && month1 == month2 && day1 > day2)
    {
      Swap (&year1, &year2);
      Swap (&month1, &month2);
      Swap (&day1, &day2);
    }

  //gets the total days in all the years repersented by the two dates.
  for (int i = year1; i < year2; i++)
    {
      totalDays += daysInYear (i);
    }

//gets the days by months up to the month1 month so that they can be removed from the total days in years
  for (int i = 1; i < month1; i++)
    {
      month1daystotal += daysInMonth (i, year1);
    }
//I added the + 1 here because it seems the sample run is inclusive of 1 of the days.
  totalDays = totalDays - month1daystotal - day1 + 1;

//gets the days by months up to month 2 so they can be added to the total days in years
  for (int i = 1; i < month2; i++)
    {
      month2daystotal += daysInMonth (i, year2);
    }

  totalDays += month2daystotal + day2;

  printf ("Number of dates between the two dates is: %d", totalDays);

  return 0;

}
