
/* 
Program Name: Program1_Owen.c 
Programmer: Lee Owen
Class: CS 3335
HW: 03
Problem: 01
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encryptLower (int n, char *l);
void encryptUpper (int n, char *l);
// encrypts Lower case char
void
encryptLower (int n, char *l)
{

  char alp[26] =
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
  int index = 0;

  for (int i = 0; i < sizeof (alp); i++)
    {
      if (alp[i] == *l)
	{
	  index = i;
	  break;
	}
    }
 
  int adjust = (index + n) % 26  ;

  *l = alp[adjust];

}
// encrypts Uppercase char
void
encryptUpper (int n, char *l)
{

  char alp[] =
    { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N',
'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
  int index = 0;

  for (int i = 0; i < sizeof (alp); i++)
    {
      if (alp[i] == *l)
	{
	  index = i;
	  break;
	}
    }

  int adjust = (index + n) % 26;

  *l = alp[adjust];




}



int
main ()
{
  int n;
  char msg[80] = " ";

  printf ("Enter a message to be encrypted:");
  scanf ("%[^\n]", msg);
  printf ("Enter shift amount:");
  scanf ("%d", &n);
// make sure the input is in the alphabet, and finds the type
  for (int i = 0; i < sizeof (msg); i++)
    {
      if (isalpha (msg[i]))
	{
	  if (isupper (msg[i]))
	    {
	      encryptUpper (n, &msg[i]);
	    }
	  else
	    {
	      encryptLower (n, &msg[i]);
	    }
	}
    }


  printf ("Encrypted message: %s", msg);
  // printf("%ld", sizeof(msg));
  return 0;
}
