/*This is the admin Section--- The one for the librarian
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
// Global functions

void Librarian_home(void);
void addbooks(void);
void viewbooks(void);
void searchbook(void);
void deletebooks(void);


// book structure
struct Book
{
	int book_id;
	char Title[15];
	char Author[15];
	int quantity;
	int rack_no;
	
};
struct Book book;

int main() {
	Librarian_home();
	return 0;
}

// function for the homepage
void Librarian_home(void){
	int choice;
	
	system("cls");
	printf("\t\t 1:Add books\n\t");
	printf("\t 2:Delete books\n\t");
	printf("\t 3:Search books\n\t");
	printf("\t 4:Issue books\n\t");
	printf("\t 5:View Books List\n\t");
	printf("\t 6:Update Books Records\n\t");
	printf("\t 7:Return Books\n\t");
	printf("\t 8:Log out \n");
	printf("\t Enter your choice: ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			addbooks();
			break;
		
		case 2:
			deletebooks();
			break;
			
		case 3:
			searchbook();
			break;
			
		case 4:
			//issuebooks();
			break;
			
		case 5:
			viewbooks();
			break;
			
		case 6:
			//editbooks();
			break;
			
		case 7:
		//returnbook();
			break;
		case 8:{
			system("color 01");
			system("cls");
			
			
			printf("\t\t Successful Logout");
			exit(0);
			
		}
		
		default:
			system("cls");
			
			system("color 7C");
			printf("\t\t Invalid choice! Try Again");
			Librarian_home();
			
	}
}

//returnfunction

//adding books
void addbooks(void)
{
    system("cls");
    puts("\t********************** Add Books ********************");
    int n;
    FILE *bks;
    bks=fopen("books_info.dat","ab+"); //open book login file for appending and updating

	if (bks == NULL)
        {
            puts("ERROR! OPENING FILE!");
        }
    else 
    {
		
        struct Book book;
		printf("\n\tEnter Book ID:"); //append data into the login file
		scanf("%d",&book.book_id);
		printf("\n\tEnter Book Title:");
		scanf("%s",book.Title);
		printf("\n\tEnter Book Author:");
		scanf("%s",book.Author);
		printf("\n\tEnter Book rack no:");
		scanf("%d",&book.rack_no);
    printf("\n\tEnter Quantity:");
		scanf("%d",&book.quantity);
		// fseek(fpvvbs;bks);,0,SEEK_END); // moving the file to the end allow appending of the next file
        
        fwrite(&book, sizeof(struct Book),1 , bks);
        fclose(bks);// books file closed


        puts("\n\tBook succesfully added");
        puts("\n\tAdd another book?\t press 1.(Yes) or 2.(No)");
        scanf("%d",&n);
        
        

        if (n == 1)
            {
                addbooks(); 
            }
        if (n == 2) 
            {
                system("cls");
				        Librarian_home();                
             }
    }
} 

// viewing books
void viewbooks(void)
{ 
  system("cls");
  FILE *bks = NULL;	
  bks = fopen("books_info.dat", "rb+");
	
	if (bks == NULL)
	{
		puts("Error opening the file");
	}
	else
	{     
		    system("cls");
        puts("\t\t\t*********************** BOOK LIST **************************************");
        puts("\n\n\t\t\t**********************************************************************");
        puts("\t\t\t**********************************************************************\n");

        printf("\t\t\t%6s %6s %6s %14s %23s\n", "BOOK ID","QUANTITY", "RACK No.","TITLE", "AUTHOR");

        while(!feof(bks))
        {   
            struct Book book;
	        int results=fread(&book,sizeof(struct Book),1,bks);
            if (results!=0 && book.book_id != 0)
            {
                printf("\t\t\t%6d %6d %6d \t%16s \t%16s\n",book.book_id,book.quantity,book.rack_no,book.Title,book.Author);
            }
            
        }
        puts("\n\t\t\t**********************************************************************");
        puts("\t\t\t**********************************************************************");
   
        
    }
   
    fclose(bks);
		
}

//searchbooks
void searchbook(void)
{
    FILE *bks;
    int Book_id,a;
    char Book_title[16];
    system("cls");
    
   
    bks = fopen("books_info.dat", "rb");
    if(bks==NULL)
    puts("Error opening file!");
    else
    {   
        puts("\t\t*************************** Search Book ******************************");
        puts("\tsearch by:---> 1.Book Id \t\t---> 2.Book Title \t\t---> 3.Exit");
        printf("Enter your choice:");
        scanf("%d",&a);
        struct Book book;
        if (a == 1)
        {
                    printf("\t\tEnter book id:");
                    scanf("%d",&Book_id);
                    while(!feof(bks))
                    {
                        int results=fread(&book,sizeof(book),1,bks);
                        if(results!=0 && Book_id==book.book_id && book.book_id!=0)
                        {
                            system("cls");
                            printf("\n\t\tThe Book Exists\n");
                            printf("\t\t\t%6s %6s %6s %10s %10s\n", "Book Id","Quantity", "Rack No.","Title", "Author");
                            printf("\t\t\t%6d %6d %6d \t%13s \t%s\n",book.book_id,book.quantity,book.rack_no,book.Title,book.Author);
                        }
                                        
                    }
                    fclose(bks);
        }
        if (a == 2)
         {

                    printf("\t\tEnter book title:");
                    scanf("%s",Book_title);
                    while(!feof(bks))
                    {
                        int results=fread(&book,sizeof(book),1,bks);
                        if(results!=0 && strcmp(Book_title,book.Title)==0)
                        {
                            printf("\n\t\tThe Book Exists\n");
                            printf("\t\t\t%6s %6s %6s %10s %10s\n", "Book Id","Quantity", "Rack No.","Title", "Author");
                            printf("\t\t\t%6d %6d %6d \t%13s \t%s\n",book.book_id,book.quantity,book.rack_no,book.Title,book.Author);                     
                        }
                        
                    }
										// add part of if the book is not found
                    fclose(bks);
         }
        if (a==3)
        {
          exit(0);   
        }	
            
    }

}

//deleting books
void deletebooks(void)
{
    system("cls");
    FILE *bks;
    //FILE *fd;
    int Book_Id;
    char findbook='n'; int option;
	system("cls");
    bks =fopen("books_infos.dat", "rb+");
	rewind(bks);	// for taking file pointer to the begining of the file
	if (bks == NULL)
        {
        puts("Error opening the file!");
        }
    else
    {  
        printf("\t\t Enter the Book ID to Delete :  ");
	    scanf("%d", &Book_Id);
	    
        struct Book book;
        int count=0;        
		while(!feof(bks) && findbook=='n')
        { 
            int results=fread(&book,sizeof(struct Book),1,bks);
            count += results;
			//finding if the user input matches book id in the system 
			if(results !=0 && book.book_id==Book_Id && findbook=='n')
            {
				printf("\t\t The Books Record is available\n");
				printf("\n\t\t\t%6s %6s %6s %10s %10s\n", "Book Id","Quantity", "Rack No.","Title", "Author");
                printf("\t\t\t%6d %6d %6d \t%13s \t%s\n",book.book_id,book.quantity,book.rack_no,book.Title,book.Author);				
				findbook = 'y';
			}
			
		}
		if(findbook =='n')
        {
			//if no book of such id is found
            printf("\t\t No book of such Id exist");
            deletebooks();
            
		}
        if (findbook =='y')
            {
                puts("\t\t\tAre you true to delete?-->Press 1.[Yes] -->2.[No]");
				printf("\t\t\tEnter your choice:");
                scanf("%d",&option);
                switch (option)
                {
                    case 1:
                        fseek(bks,(count-1)*sizeof(struct Book),SEEK_SET);
                        struct Book blank = {0,"","",0,0};
                        fseek(bks,(count-1)*sizeof(struct Book),SEEK_SET);
                        fwrite(&blank,sizeof(struct Book),1,bks);
						
						Librarian_home();
                        break;
                    case 2:
						puts("Please wait...");
					
                        Librarian_home();
                
                    default:
                        puts("Invalid option try again");
                        deletebooks();
                        break;
                }


            }
            fclose(bks);	
    }
}