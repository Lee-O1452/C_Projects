#include <stdio.h>

int main()
{
    struct Books {
        char name[20];
        char author[20];
        int num_pages;
    };
    struct Books books[10];
    int num_books,i,l,largest=0, holding;
    printf("No Of Books (less than 10):");
    scanf("%d",&num_books);
    getchar();
    printf("Enter the book details\n-----------------------\n");
    for(i=1;i<=num_books;i++){
        printf("Details of book No %d\n",i);
        printf("Book Name:");
        fgets(books[i-1].name, 20, stdin);
        printf("Author:");
        fgets(books[i-1].author, 20, stdin);
        printf("Number of Pages:");
        scanf("%d",&books[i-1].num_pages);
        getchar();
    }
    printf("======================================\nS.No | Book Name | Author | Number of pages\n======================================\n");

    for(i=1;i<=num_books;i++){
        printf("%d|%s",i,books[i-1].name);
        printf("|%s",books[i-1].author);
        printf("|%d\n",books[i-1].num_pages);
        
    }    
    printf("\n======================================\n");
    
    for(i=1;i<=num_books;i++){
       if(largest < books[i-1].num_pages){
           largest = books[i-1].num_pages;
           holding = i-1;
       } 
    }
    printf("Book with highest number of pages: %s", books[holding].name);
    return 0;
}
