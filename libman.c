//Library Project

#include <stdio.h>
#include <conio.h>
#include <windows.h>

//Book Structure
 char categories [][17] = {"mathematics","computer","Education","Psychology","Medicine","engineering"};

void mainmenu(void) //displays main menu of this project
void returnfunc(void) //main menu function is called when user presses a key(a user can return back to main menu)
void addBooks(void)
void deleteBooks(void)
void editBooks(void)
void searchBooks(void)
void viewBooks(void)
void issuerecord(void) //keeps record of the student to whom book has been issued
void closeapplication(void)
//int getdata() //asks for data input from the user
int checkid(int) //ID entered exists in file or not
void password()
delay(unsigned int mseconds)

//global files 
FILE *fp, *ft ,*fs;

//global variables
int option;
char searchBook;
char password[8] = {"@kishnice"};

struct borrowingDate
{
	int 
}
typedef struct Book
{
	char *categories;
	char title[20];
	char author[20];
	int rack_number; 
	int book_id;
	int quantity;
}Book;

Book *book;      //Global Book Type Pointer

int count = 0;  //Global Count Variable
int size;      //Global Variable for Dynamic Memory Allocation

//Function to Add New Book

void addBook()
{
	system("cls");
	system("color CF");
	
	printf("\n************Add New Book Detail*************");
	printf("\nEnter Book Title : ");
	gets(book[count].title);
	printf("\nEnter Book Author : ");
	fflush(stdin);
	gets(book[count].author);
	printf("\nEnter Rack number : ");
	scanf("%d",&book[count].rack_number);
	printf("\nEnter Book ID : ");
	scanf("%d",&book[count].book_id);
	printf("\nEnter Quantity : ");
	scanf("%d",&book[count].quantity);
	count++;
}

//Function To Show All Books Record
void showAllBook()
{
	int i;
	system("cls");
	
	printf("\n\n\t\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Books Details @@@@@@@@@@@@@@@@@@@@@@@@@");
	printf("\n\n\t\t......................................................................................");
	printf("\n\n\t\tBOOK TITLE\tBOOK AUTHOR\tRACK NUMBER\tBOOK ID\t   QUANTITY"); 
	printf("\n\t\t........................................................................................");
	for(i=0; i<count; i++)
	{
		printf("\n\t\t%s",book[i].title);
		printf("\n\t\t%s",book[i].author);
		printf("\n\t\t%d",book[i].rack_number);
		printf("\n\t\t%d",book[i].book_id);
		printf("\n\t\t%d",book[i].quantity);
	}
}


//Function To Search Book By Title

void searchBook()
{
	system("color CF");
	char btitle[10];
	int i;
	printf("\nEnter Book Title To Search : ");
	gets(btitle);
	for(i=0; i<count; i++)
	{
		if(strcmp(book[i].title,btitle)==0)
		{
		system("cls");
		
		printf("\n\n\t\t ############### Book Details ##################");
		printf("\n\n\t\t Book Title : %s",book[i].title);
		printf("\n\n\t\t  Book Author : %s",book[i].author);
		printf("\n\n\t\t  Book Rack Number : %d",book[i].rack_number);
		printf("\n\n\t\t  Book ID : %d",book[i].book_id);
		printf("\n\n\t\t  Book Quantity : %d",book[i].quantity);
		}
	}

}
//Function To Remove Book By Title
void removeBook()
{
//	FILE *book2;
//	book2 = fopen("book2.dat", "ab+");

	char btitle[10];
	int i,j;
	//char *book, Book[30];
	//Book  *temp;
	printf("\nEnter Book Title To  Remove : ");
	gets(btitle);
	for(i=0; i<count; i++)
	{
		if(strcmp(book[i].title,btitle)==0)
		{
			system("cls");
			
			printf("\n\n\t\t ########## Remove Book Details #######");
			printf("\n\n\t\t Book Title : %s ",book[i].title);	
			printf("\n\n\t\t  Book Author : %s ",book[i].author);
			printf("\n\n\t\t  Book Rack Number : %d ",book[i].rack_number);
			printf("\n\n\t\t  Book ID : %d ",book[i].book_id);
			printf("\n\n\t\t  Book Quantity : %d ",book[i].quantity);
			for(j=i; j<count-1; j++)
				book=book+1;
			count--;
			return;
		}
	}
}
//Function To Update Book By Title
void updateBook()
{
	
	char btitle[10];
	int i;
	//Book temp;
	printf("\nEnter Book title to be Update : ");
	gets (btitle);
	for (i=0; i<count; i++)
	{
		if(strcmp(book[i].title,btitle)==0)
		{
			system("cls");
			
			printf("\n\n\t\t ########## Book Details ##########");
			printf("\n\n\t\tBook Title : %s",book[i].title);
			printf("\n\n\t\tBook Author : %s",book[i].author);
			printf("\n\n\t\t  Book Rack Number : %d ",book[i].rack_number);
			printf("\n\n\t\t  Book ID : %d ",book[i].book_id);
			printf("\n\n\t\t  Book Quantity : %d ",book[i].quantity);
			
			
			printf("\n******* Add New Book Detail ******");
			printf("\nEnter Book Title : ");
			gets(book[i].title);
			printf("\nEnter Book Author : ");
			fflush(stdin);
			gets(book[i].author);
			printf("\n Enter Book Rack Number :  ");	
			scanf("%d",&book[i].rack_number);
			printf("\nEnter Book ID : ");
			scanf("%d",&book[count].book_id);
			printf("\nEnter Quantity : ");
			scanf("%d",&book[count].quantity);
		}
	}
	
}

typedef struct Password
{
	char name[20];
	char password[25] ;
}password;

int main()
{
	
	int choice ;
	printf("Welcome to Book Section : ");
		
	//Create Book Array Dynamic using size input by User
	
	do	
	{
		system("cls");
		printf("\t\t\t\n1.Add Book\n2.Show All Books\n3.Search Book\n4.Update Books\n\t\n\n");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice)
		{
			case 1:
				addBook(); //Function Call to Add New Book Detail
				break;
			case 2:
				showAllBook(); //Function Call to Show Book Detail
				break;
			case 3:
				searchBook();//Function Call to search  Book Detail
				break;
			case 4:
				updateBook(); //Function Call to Update Book Detail
				break;
			case 5:
				removeBook(); //Function Call to Remove Book Detail
			 	break;
			case 6:
				return 0;	
		}
		getch();
	}
	while(1);

}

