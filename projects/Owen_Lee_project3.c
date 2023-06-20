/* 
Program Name: Lee_Owen_project3.c 
Programmer: J. Lee Owen
Class: CS 3335
Project: 03
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//declaring functions.
struct Line * readFile(char file_name[], int *n);
void computeLengths(struct Line *lines, int n);
void saveLengths(struct Line *lines, int n);
void printStats(struct Line *lines, int n);
//declaring int n.
int n;

//Point struct.
struct Point
{
    int x;
    int y;
};
//Line struct.
struct Line
{
    struct Point a;
    struct Point b;
    float length;
};
//Function reads a file and dynamicly creates an array of Lines.
struct Line * readFile(char file_name[], int *n)
{
    FILE *fp;
    struct Line *ptr;
    char temp[300];
    //opening the file provided in command-line, and making sure it opens.
    if ((fp = fopen(file_name, "r")) == NULL) 
    {
        printf("%s can't be opened\n", file_name);
        exit(1);
    }
    //getting the total number of lines.
    fgets(temp, 300, fp);
    sscanf(temp, "%d", n);
    
    //line ptr being given dynamic memory.
    ptr = (struct Line*)calloc(*n, sizeof(struct Line));
    
    //making sure memory was allocated.
    if (ptr == NULL) 
    {
		printf("Memory not allocated.\n");
		exit(0);
	}
	printf("Array of size %d created.\n",*n);
	//
	struct Point points[*n * 2];
	
	//getting points from file and putting points into point array.
	int even=0,odd=1;
	for(int i=0; i< *n;(i++))
	{
	    fgets(temp, 300, fp);
        sscanf(temp, "%d %d %d %d",&points[even].x, &points[even].y,&points[odd].x, &points[odd].y);
        even = even + 2;
	    odd = odd + 2;
	}
	
	//closing the file.
	fclose(fp);
	
	//putting points into Line ptr.
	    int i=0;
	for (int l = 0; l<*n; l++)
	{
	    (*(ptr + l)).a = points[i];
	    i++;
	    (*(ptr + l)).b = points[i];
	    i++;
	}
	
	//data has been processed.
    printf("Data read\n");
    return ptr; 
}
//Function goes through all the lines and computes there lengths.
void computeLengths(struct Line *lines, int n)
{
    printf("Computing lengths...\n");
    //computes the lengths of each line.
    for(int i=0;i<n;i++)
    {
        (*(lines +i)).length = sqrt(pow((*(lines +i)).b.x - (*(lines +i)).a.x, 2) + pow((*(lines +i)).b.y - (*(lines +i)).a.y, 2));
    }
    printf("length computation completed\n");
}
//Function writes the lengths of each line into lengths_Owen_Lee.txt.
void saveLengths(struct Line *lines, int n)
{
    printf("Saving lengths...\n");
    //creating the file, and making sure the file can be opened.
    FILE *fp;
    char file_name[]= "lengths_Owen_Lee.txt";
    if ((fp = fopen(file_name, "w")) == NULL) 
    {
        printf("%s can't be opened\n", file_name);
        exit(1);
    }
    //writing the lenghts into the file.
    for(int i=0; i<n; i++)
    {
        fprintf(fp, "%.1f\n", (*(lines +i)).length);
    }
    
    fclose(fp);
}
//Function goes through, finds, and prints the min, max, and average of all the lines. 
void printStats(struct Line *lines, int n)
{
    //initalizing min, max, and avg.
    float min=0,max=0,avg=0;
    for (int i=0;i<n;i++)
    {
        //setting original min.
        if(i==0)
        {
            min = (*(lines +i)).length;    
        }
        //checking if this length is less than the current min.
        if(min > (*(lines +i)).length)
        {
            min = (*(lines +i)).length; 
        }
        //checking if this length is greater than the current max.
        if(max < (*(lines +i)).length)
        {
            max = (*(lines +i)).length;
        }
        //adding all of the lengths together.
        avg+= (*(lines +i)).length;
    }
    //calculating the average.
    avg= avg/n;
    //printing max.
    printf("Line of max length: %.1f\n\n", max);
    //printing min.
    printf("Line of min length: %.1f\n\n", min);
    //printing the avg.
    printf("Average line length: %.1f\n", avg);
}

//main function
int main(int argc, char *argv[])
{   
    struct Line *lines = readFile(argv[1], &n);
    computeLengths(lines, n);
    saveLengths(lines, n);
    printStats(lines, n);
    free(lines);
    
    return 0;
}
