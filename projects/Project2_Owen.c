/*
Program Name: Project2_Owen.c
Programmer: Lee Owen
Class: CS 3335
Project: 02
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//sets the position of the ship on the board for the player
void
setBoard (int *playBoard)
{
  int position = -1;
  while (position < 0 || position > 9)
    {
      printf ("Enter position:");
      scanf ("%d", &position);
    }
  *(playBoard + position) = 1;

}

//sets the position of the ship on the board for the computer
void
setComputerBoard (int *compBoard)
{
  time_t t;
  srand ((unsigned) time (&t));
  int position = rand () % 10;
  *(compBoard + position) = 1;
}

//runs a game against a computer
int
playGame (int *playBoard, int *compBoard)
{
  int running = 0, shot, result = -1, newShot = 0, compShots[10] =
    { 0 }, playShots[10] =
  {
  0}, i;
  time_t t;
  srand ((unsigned) time (&t));
  while (running == 0)
    {
      newShot = 0;
      shot = rand () % 10;
      while (newShot == 0)
	{
	  if (compShots[shot] == 1)
	    {
	      shot = rand () % 10;
	    }
	  else
	    {
	      compShots[shot] = 1;
	      newShot++;
	    }
	}
      printf ("Computer guesses %d\n", shot);
      if (*(playBoard + shot) == 1)
	{
	  result++;
	  *(playBoard + shot) = 3;
	  printf ("HIT!\n");
	}
      if (*(playBoard + shot) == 0)
	{
	  *(playBoard + shot) = 2;
	  printf ("MISS!\n");
	}
      newShot = 0;
      printf ("Enter guess ");
      scanf ("%d", &shot);
      while (newShot == 0)
	{
	  if (playShots[shot] == 1)
	    {
	      printf ("Enter guess ");
	      scanf ("%d", &shot);
	    }
	  else
	    {
	      playShots[shot] = 1;
	      newShot++;
	    }
	}
      printf ("You guessed %d\n", shot);
      if (*(compBoard + shot) == 1)
	{
	  result++;
	  result++;
	  *(compBoard + shot) = 3;
	  printf ("HIT!\n");
	}
      if (*(compBoard + shot) == 0)
	{
	  *(compBoard + shot) = 2;
	  printf ("MISS!\n");
	}
      printf ("Human Board:\n");
      for (i = 0; i < 10; i++)
	{
	  printf ("%d", i);
	}
      printf ("\n");
      for (i = 0; i < 10; i++)
	{
	  if (*(playBoard + i) == 1)
	    {
	      printf ("S");
	    }
	  else if (*(playBoard + i) == 2)
	    {
	      printf ("M");
	    }
	  else if (*(playBoard + i) == 3)
	    {
	      printf ("H");
	    }
	  else
	    {
	      printf ("*");
	    }
	}
      printf ("\n");
      printf ("Computer Board:\n");
      for (i = 0; i < 10; i++)
	{
	  if (*(compBoard + i) == 2)
	    {
	      printf ("M");
	    }
	  else if (*(compBoard + i) == 3)
	    {
	      printf ("H");
	    }
	  else
	    {
	      printf ("*");
	    }
	}
      printf ("\n");
      if (result >= 0)
	{
	  running++;
	  return result;
	}
    }
}

//calls the functions and creates the veriables
int
main ()
{
  int compBoard[10] = { 0 }, playBoard[10] =
  {
  0}, result;

  setBoard (playBoard);
  setComputerBoard (compBoard);
  result = playGame (playBoard, compBoard);
  if (result == 0)
    {
      printf ("Computer Wins!");
    }
  if (result == 1)
    {
      printf ("Human Wins!");
    }
  if (result == 2)
    {
      printf ("Tie!");
    }


  return 0;
}
