#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <ctype.h>
#include <dos.h>

#define RETURNTIME 15



/* run this program using the console pauser or add your own getch, system("pause") or input loop */
char Categories[][15] ={"Engineering" , "Education", "Philosophy" , "Medicine",  "Food Science", "Sciences"};

//pointers of global filesg
FILE *fb=NULL,*fd=NULL,*fg=NULL;


//list of function prototypes used in the system



void home(void); 
int getdata();  
int Time(void);
void returnfunc(void);

void Librarian_password(void);  
void Librarian_home(void); 
void addbooks(void);
void searchbooks(void);
void editbooks(void);
void viewbooks(void);
void issued_record();
void issuebooks(void);
void logout(void);
void deletebooks(void);
void returnbooks(void);
int checkbook_id(int);
  
void User(void);
void Registration(void);

//The Global Variables
int choice;
char findbook;
char lib_password[8] = {"chrisgud"};

// This is for delay function
void delay(unsigned int mseconds){
	clock_t goal = mseconds + clock();
	while(goal > clock());
}

// Dealing with Dates
struct DateTime{
	int month,day,year;
};

struct Book{
	int book_id;
	char stud_issued[15];
	char Title[15];
	char Author[15];
	int quantity;
	int rack_no;
	char *Category ;
	struct DateTime issued_date;
	struct DateTime duedate;
};

struct Book sample;

int main(void) {
	
	home();
	
	
	return 0;
}




//function home for the home page to the user
void home(void){
  system("cls");
	system("color 0A");
    
	printf("\t Login into the System as : (Choose One)\n\t" );
	printf("\t 1:Librarian \n\t");
	printf("\t 2:User \n\t");
	printf("\t 3:No user account!Register\n\t");
	printf("\t Enter your choice : ");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			Librarian_password();
			
			break;
			
		case 2:
			
			
			break;
		
		case 3:
			
			break;
			
		default:
			system("cls");
			printf("\t Invalid Choice! Try Again\n");
			home();
	}
}


// Password for the Librarian to Log in

void Librarian_password(){
	system("cls");
	char ch, pass[8];
	int i;
	printf("\t\tEnter Your Password:");

//for hiding the password in Asterik
//Improvise the password code!

	/* code */
		

for(i=0;i<8;i++){
		ch = getch();
		pass[i] =ch;
		ch ='*';
		
		printf("%c",ch);

			}	


	
	pass[i] = '\0';
	
	
	for(i=0;i<8;i++)
	printf("%c",pass[i]);

	
	if(strcmp(pass,lib_password)==0){
		Librarian_home();
	}
	
	else{
		system("cls");
		printf("\n\t Incorrect Password! Try Again");
		delay(3000);
		Librarian_password();
		
	}

	
}
//function Librarian for all  administrative use

void Librarian_home(void){
	
	
	system("cls");
	printf("\t\t 1:Add books\n\t");
	printf("\t 2:Delete books\n\t");
	printf("\t 3:Search books\n\t");
	printf("\t 4:Issue books\n\t");
	printf("\t 5:View Books List\n\t");
	printf("\t 6:Update Books Records\n\t");
	printf("\t 7:Return Books\n\t");
	printf("\t 8:Log out \n");
	Time();
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
			searchbooks();
			break;
			
		case 4:
			issuebooks();
			break;
			
		case 5:
			viewbooks();
			break;
			
		case 6:
			editbooks();
			break;
			
		case 7:
			break;
		case 8:{
			system("color 01");
			system("cls");
			
			
			printf("\t\t Successful Logout");
			delay(3000); //delay for 5 seconds
			exit(0);
			
		}
		
		default:
			system("cls");
			
			system("color 7C");
			printf("\t\t Invalid choice! Try Again");
			Librarian_home();
			
	}
}

//adding books 
void addbooks(void){
	system("cls");
	system("color CF");
	printf("\t\t 1:Engineering\n"); // These list relies heavily on the Categories initialized above
	printf("\t\t 2:Education\n");
	printf("\t\t 3:Philosophy\n");
	printf("\t\t 4:Medicine\n");
	printf("\t\t 5:Food Science\n");
	printf("\t\t 6:Sciences\n");
	printf("\t\t 7:Back\n");
	printf("\t\t 8:Enter your choice: ");
	scanf("%d",&choice);
	
	if(choice==7){
		Librarian_home();
	}
	
	system("cls");
	fb =fopen("books.dat", "a+");
  if (fb==NULL) {
	   printf("\n\t Failed to open books.dat\n");
		 delay(3000);
		 Librarian_home();
	}
	
	if(getdata() ==1){
		sample.Category = Categories[choice -1];
		fseek(fb,0,SEEK_END); // moving the file to the end allow appending of the next file
		fwrite(&sample,sizeof(sample),1,fb);
		fclose(fb);
		
		printf("\n\t The book have been added successfully\n");
		printf("\t\t Add another book? (N/Y) : ");
		
		//the decision to add another book or not
		if(getch()=='N'){
			Librarian_home();
		}
		
		else{
			system("cls");
			addbooks();
		}
	}
}

//function of time: Learn More aboout Time header
int Time(void){
	time_t t;
	time(&t);
	printf("\t\t Date and Time : %s\n",ctime(&t));
	
	return 0;
}

//checking for the existence of the book in the Library
int checkbook_id(int t){
	fb = fopen("books.dat", "rb+");
	if (fb == NULL) {
		puts(	"error: could not open the books file");
		delay(3000);
		Librarian_home();
	}
	else
	{
		
	while(!feof(fb))
	{
		while(fread(&sample,sizeof(sample),1,fb)==1)
			if (sample.book_id==t) {
				return 0;/* code */
			}
			
			
		// struct Book book;
		// int result = fread(&book, sizeof(struct Book), 1, fb);
		// if (result != 0 && book.book_id != 0 && book.book_id == t) 
		// {
		
		//   getdata();
		// }
		
	}
	
	}
	return 1;
	fclose(fb);
	 // for non exixting book
} 

// function for getdata
int getdata(){
	int t;
	
	system("color 6D");
	printf("\t Enter the data for the following\n");
	printf("\t\t Category\tChoice");
 // there is a problem here solve it!
	printf("\n\t\t Section:\t%s",Categories[choice-1]);
	printf("\n\t\t Book ID :\t");
	scanf("%d",&t);
	
	if(checkbook_id(t) ==0 ){
		printf("\t\a The Book ID already exist\a\n ");
		getch();
		Librarian_home();
		return 0;
	}
	
	//  THis function has got strict usage based on declaration in struc Book. Be Keen.
	sample.book_id = t;
	printf("\t\t Book Title :\t ");
	scanf("%s",sample.Title);
	printf("\t\t Author :\t ");
	scanf("%s",sample.Author);
	printf("\t\t Quantity :\t ");
	scanf("%d",&sample.quantity);
	printf("\t\t Rack No :\t ");
	scanf("%d",&sample.rack_no);
	
	return 1;
}

//function for viewing books




void viewbooks(void)
{
  system("clear");
  FILE *vb=NULL;  
  vb = fopen("books.dat", "rb+");
	if (vb == NULL)
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
      
        while(!feof(vb))
        {   
	        int results=fread(&sample,sizeof(sample),1,vb);
            if (results!=0)
            {
                printf("\t\t\t %6d %6d %6d \t%16s \t%16s\n",sample.book_id,sample.quantity,sample.rack_no,sample.Title,sample.Author);
            }
            
        }
        puts("\n\t\t\t************************************************************************");
        puts("\t\t\t**************************************************************************");
        
    }
   
    fclose(vb);
		returnfunc();
}




// void viewbooks(void)
// {
	
// 	system("cls");
// 	system("color A7");
// 	//int i=0;
	
// 	 // improve this part for viewing
	
//  if((fb = fopen("books.dat", "rb"))==NULL)
// 	 {
// 		puts("cannot open file");
// 		/* code */
// 	}
// 	else
// 	{	
		

// 		printf("\n\n\n\t\t\t     Books List         \n ");
// 	  printf( "\t\t CATEGORY\tBOOK ID\t\tTITLE\tAUTHOR\tQUANTITY\tRACK NO \n");
	  
// 		while(fread(&sample,sizeof(sample),1,fb)==1){
		   
// 				printf( "\n\t\t 	%d	  %s	  %s	  %d	   %d\n", sample.book_id,sample.Title,sample.Author, sample.quantity,sample.rack_no);
// 			fclose(fb);
// 		}
// 	}
		

// delay(3000);		
// returnfunc();
	
//	}


//	while(fread(&sample,sizeof(sample),1,fb)==1){
	// if(fb == NULL)
	// {
	// 	puts("Error: Could not open the files");
	// }
	
	
// 	else{

	

// 		while(!feof(fb))
// 	{
// 		//struct Book book;
		
// 			while(fread(&sample, sizeof(sample), 1, fb)==1)
// 			{
// 				printf( "\n\t\t %s\t	%d\t\t	  %s\t	  %s	\t  %d	 \t    %d\n", sample.Category, sample.book_id, sample.Title,sample.Author, sample.quantity,sample.rack_no);
// 			}
// 		}
	
// }
  
	// i=i + sample.quantity;
	// printf("\t\t\t\t\t Total Books = %d",i);
	//fclose(fb); 

		// improve this printf code make the view output nice
		// Ensure there is output without the use address ... cooked!! 
		
//		
//	}
	
//	


//function for returning back Librarian_home
void returnfunc(void){
	printf("\n\t Press ENTER to return to the Main Menu  ");
	sample:
		if(getch()==13)
		Librarian_home();
		
		else
		  goto sample;
}

/*This function does not delete values effectively: Work on it : */
/*Key bugs: Deleting as a group, Deleting a non-existing Value after immediate delete of existing value, The 1st output in View cannot be deleted maybe bcoz-- 
use of address in view*/
// function for deleting books from the record 


// void viewbooks(void){
// 	 system("cls");
// 	 system("color A5");

// 	 if((fb =fopen("books.dat", "rb"))==NULL){
// 		 puts("Could not open the file");
// 	 }

// 	 else
// 	 {
// 		 printf("%-6")
// 	 }
	 
// }

void deletebooks(void){
	system("cls");
	system("color 5A");
	
	int BookId;
	char another ='y';
	while(another=='y'){
		system("cls");
		system("color 8E");
		
		printf("\t\t Enter the Book ID to Delete :  ");
		scanf("%d", &BookId);
		fb =fopen("books.dat", "rb+");
		rewind(fb); // for taking file pointer to the begining of the file
		
		while(fread(&sample,sizeof(sample),1,fb)==1){
			//finding if the user input matches book id in the system 
			if(sample.book_id==BookId){
				printf("\t\t The Books Record is available\n");
				// until u add address it doesn't give books details
				printf("\t The Book Title :%s ",sample.Title);
				printf("\t The Book Rack No :%d",sample.rack_no);
				
				findbook = 't';
			}
			
		}
		
		
		if(findbook !='t'){
			//if no book of such id is found
		
			printf("\t\t No book of such Id exist");
			returnfunc();
		}
	
		
	  if(findbook == 't'){
			printf("\t\t Delete? (Y/N): ");
			
			if(getch()== 'y'){
				fd =fopen("test.dat", "wb+"); //temporary file for delete book
				rewind(fb); //file pointer at the beginning of the file
				
				while(fread(&sample,sizeof(sample),1,fb)==1){
					
					if(sample.book_id != BookId){
						fseek(fd,0,SEEK_CUR);
						fwrite(&sample,sizeof(sample),1,fd); // write temporary files except those to be deleted
					}
				}
				fclose(fd);
				fclose(fb);
				remove("books.dat");
				rename("test.dat","books.dat"); // copy books.dat to test.dat except data we want to delete
				//fb= fopen("books.dat", "rb+");
				
				if(findbook == 't'){
					printf("\t\t Successful delete\n");
					printf("\t\t Delete Another? (Y/N)  ");
					//another = getch();
					 // improve the delete function to be real time. Deleteing multiple files
					
				}
				//fclose(fb); //  can add it anywhere it helps
				
			}
			
			else
			Librarian_home();
			fflush(stdin);
			another = getch();
			
		}
		
		
	}
	
	Librarian_home();
}

/*Function  for searching books*/
/*Can Search all others except the 1st output in view--bcoz it is initialized by memory*/
void searchbooks(void){
	system("cls");
	system("color 3F");
	
	int d;
	printf("\t\t Search Books\n");
	printf("\t\t\t 1:By Book Id\n");
	printf("\t\t\t 2:By Title\n");
	printf("\t\t\t Enter Your Choice: ");
	scanf("%d",&d);
	fb = fopen("books.dat", "rb+");
	rewind(fb);
	
	switch(d){
		case 1:{
			system("cls");
			
			printf("\t\t Search Books by Id\n");
			printf("\t\t Enter Book Id: ");
			scanf("%d",&d);
			
			while(fread(&sample,sizeof(sample),1,fb)==1){
				if(sample.book_id==d){
					system("cls");
					printf("\t\t Book Available\n");
					//printf("\t\t Category %s\n", sample.Category);
					printf("\t\t Title: %s\n", sample.Title);
					printf("\t\t ID : %d\n", sample.book_id);
					printf("\t\t Quantity :%d\n",sample.quantity);
					printf("\t\t Rack No. :%d", sample.rack_no);
					
					findbook = 't';
					returnfunc();
				}
				
		
				
		    	/*	else
				{
				printf("\t\t No Record found\n");
				printf("\v\t Retry?(Y/N)");
				
				    if(getch()=='y')
				    searchbooks();
				
				    else
				    Librarian_home();*/
			}
			
			// trying if the record entered is in the loop or not
			if(findbook != 't'){
				printf("\t\t No Record found\n");
				printf("\t\t Retry?(Y/N)");
				
				if(getch()=='y')
				searchbooks();
				
				else
				Librarian_home();
			}
			break;
		}
		
		case 2:{
			system("cls");
			char s[15];
			
			printf("\t\t Search Book by Title\n");
			printf("\t\t Enter Book Title: ");
			scanf("%s",s);
			
			int d=0;
			while(fread(&sample,sizeof(sample),1,fb)==1){
				if(strcmp(sample.Title,(s))==0){ // whether name entered as s is == book's name or not
					printf("\t\t Book Available\n");
				//	printf("\t\t Category :%s\n",sample.Category);
					printf("\t\t Title: %s\n",sample.Title);
					printf("\t\t ID : %d\n", sample.book_id);
					printf("\t\t Author : %s\n", sample.Author);
					printf("\t\t Quantity :%d\n", sample.quantity);
					printf("\t\t Rack No. :%d",sample.rack_no);
					d++;  // why increament inside if??
					returnfunc();
				}
			}
			
			if(d==0){
				printf("\t\t No Book Record\n");
				printf("\t\t Retry?(Y/N)");
				if(getch()== 'y')
				searchbooks();
				else
				Librarian_home();
			}
			break;
		}
		
		default:
		getch();
		searchbooks();	
	}
	
	fclose(fb);
}

// function for editing books
void editbooks(){
	system("cls");
	system("color 6B");
	
	int d;
	
	printf("\t\t Edit Book Section\n");
	char another ='y';
	while(another =='y'){
		system("cls");
		printf("\t\t Enter Book Id To be Edited:");
		scanf("%d",&d);
		
		fb = fopen("books.dat", "rb+"); // try wb+
		if (fb == NULL) {
			puts("Error! Could not open the file.\n");
			delay(3000);
			editbooks();
			/* code */
		}
		else
		{
			/* code */
		
		
		while(fread(&sample,sizeof(sample),1,fb)==1){
			
			if(checkbook_id(d)==0){
				printf("\t\t The Book Exists\n");
				printf("\t\t New Book ID :");
				scanf("%d",&sample.book_id);
				//printf("\t\t New Category: ");
				//scanf("%s",sample.Category);
				printf("\t\t New Title: ");
				scanf("%s",sample.Title);
				printf("\t\t New Author: ");
				scanf("%s",sample.Author);
				printf("\t\t New Quantity: ");
				scanf("%d",&sample.quantity);
				printf("\t\t New Rack No. : ");
				scanf("%d",&sample.rack_no);
				printf("\t\t Record Updated Successfully\n");
				
				fseek(fb,ftell(fb)-sizeof(sample),0);
				fwrite(&sample,sizeof(sample),1,fb);
				fclose(fb);
				
				
			}
			
			else{
				printf("\t\t No Record Found\n");
				delay(3000);
				editbooks();
			}
		}

		}

		printf("\t\t Update another Record?(Y/N): ");
		fflush(stdin);
		another=getch();
	}
	
	returnfunc();
}

/* 8th Feb 2019: There is a problem with the program code. It is running as expectedi.e The View Function: Check on it . It just lost data abrubtly-- was
 good initially*/
 
 // Information about the books issued
 void issued_record(void){
	system("cls");
	printf("\n\n\t\t The Book has been taken by %s\n",sample.stud_issued);
	printf("\t\t Issued Date:%d-%d-%d\n",sample.issued_date.day,sample.issued_date.month,sample.issued_date.year);
	printf("\t\t Returning Date:%d-%d-%d\n",sample.duedate.day,sample.duedate.month,sample.duedate.year);
}

void issuebooks(void){
	system("cls");
	system("color 8F");
	
	int t;
	int d;
	printf("\n\t\t\t Issue Book Section\n");
	printf("\t\t 1. Issue a Book\n");
	printf("\t\t 2. View Issued Book\n");
	printf("\t\t 3. Search Issued Book\n");
	printf("\t\t 4. Remove Issued Book\n");
	printf("\t\t Enter your choice :  ");
	scanf("%d",&d);
	
	switch(d){
		case 1:{// issue book
			system("cls");
			
			
			char another = 'y';
			while(another == 'y'){
				system("cls");
				printf("\n\t\t\t Issue Book Section\n");
				printf("\t\t Enter Book ID: ");
				scanf("%d",&t);
				
				fb = fopen("books.dat", "rb");
				fg = fopen("issue.dat", "ab+");
				
				if(checkbook_id(t)==0){
					printf("\n\t\t The Book Record is Available\n");
					printf("\t\t There are %d unissued books in the library\n", sample.quantity);
					printf("\t\t The Title of book is %s\n", sample.Title);
					printf("\t\t The Student name: ");
					scanf("%s",sample.stud_issued);
					printf("\n\t\t The date Issued:%d-%d-%d \n ", sample.issued_date.day, sample.issued_date.month, sample.issued_date.year);
					printf("\t\t The Book ID: %d", sample.book_id);
					
					// defining when to return the book
					sample.duedate.day = sample.issued_date.day +RETURNTIME;
					sample.duedate.month = sample.issued_date.month;
					sample.duedate.year = sample.issued_date.year;
					
					if(sample.duedate.day>30){
						sample.duedate.month += sample.duedate.day/30;
					    sample.duedate.day -=30;
					}
					
					if(sample.duedate.month > 12){
						sample.duedate.year += sample.duedate.month /12;
						sample.duedate.month -=12;
					}
					
					printf("\n\t\t To be Returned: %d-%d-%d\n",sample.duedate.day, sample.duedate.month, sample.duedate.year);
					fseek(fg, sizeof(sample),SEEK_END);
					fwrite(&sample,sizeof(sample),1,fg);
					fclose(fg);
					
					
				}
				else{
					printf("\n\t\t No Record Found\n");
					delay(3000);
					issuebooks();
				}
				
				printf("\n\t\t Issue More Book?(Y/N)");
				fflush(stdin);
				another = getch();
				fclose(fb);
			}
			break;
		}
		
		case 2:{ // showing issued book
			system("cls");
			
			
		
			puts("\t\t\t**************************ISSUED BOOK LIST **************************************");
      puts("\t\t\t*********************************************************************************");
      puts("\t\t\t**********************************************************************************");

      printf("\t\t\t%6s %10s  %7s %14s  %18s\n", "NAMES","BOOK ID","TITLE","ISSUED DATE", "RETURN DATE");
      
			
			fg = fopen("issue.dat", "rb");
			 
			 
			 while(fread(&sample,sizeof(sample),1,fg)==1){
				printf("\t\t\t %6s  %6d   %6s   %5d-%d-%d   %5d-%d-%d\n", sample.stud_issued, sample.book_id, sample.Title, sample.issued_date.day,sample.issued_date.month,sample.issued_date.year,sample.duedate.day,sample.duedate.month,sample.duedate.year);
				
				
	    
			}
		puts("\t\t\t***********************************************************************************");
    puts("\t\t\t***********************************************************************************");
        
			 
			fclose(fg);
			returnfunc();
			break;
		}
		
		case 3:{  // search issued book by Id
		     system("cls");
		     printf("\n\t\t Enter The Book ID: ");
		     
				 
		     int p, c=0;
		     char another = 'y';
		     while(another=='y'){
		     	scanf("%d",&p);
		     	fg = fopen("issue.dat", "rb");
		     	while(fread(&sample,sizeof(sample),1,fg)==1){
		     		if(sample.book_id==p){
		     			issued_record();
		     			printf("\n\t\tPress any Key To Continue...");
		     			getch();
		     			issued_record();
							c=0; 
		     			
					 }

				 }

				 if (c==1){
			   	   printf("\t\t No record Found \n");
					   delay(3000);
					   issuebooks();
					  
			   }
				 

				 
			   fflush(stdin);
			   fclose(fg);
			   
			   
				 
			   printf("\t\t Search Another Book?(Y/N) ");
			   another = getch();
				 }	 
			
			break;
		}
		
		case 4:{// remove issued book from the record
		    system("cls");
			int b;
			FILE *ft=NULL; // temporary file for deleting
			char another ='y';
			while(another=='y'){
				system("cls");
				printf("\n\t\t Enter the Book ID to remove:");
				scanf("%d",&b);
				fg = fopen("issue.dat", "rb+");
				if(fg==NULL){
					puts("Cannot open the file\n");
					delay(3000);
				}
				else
				{
					/* code */
				
				
				while(!feof(fg) && fread(&sample, sizeof(sample),1,fg)==1){
					if(sample.book_id==b){
						issued_record();
						findbook = 't';
					}
					
					if(findbook =='t'){
						printf("\t\t Do you want to Delete it?(Y/N)");
						if(getch()=='y'){
							ft = fopen("record.dat", "ab+");
							
							if(ft!=NULL  && !feof(ft)){

							rewind(fg);
							while(fread(&sample, sizeof(sample),1,fg)==1){
								if(sample.book_id !=b){
									fseek(fg,0,SEEK_CUR);
									fwrite(&sample, sizeof(sample),1,ft);
								}
							}

							}
							else{
								puts("Cannot open writing file");
								delay(3000);
								issuebooks();
							}

							//plecse
							printf("\n\t\t The Issued Book Is removed from the List\n");
						}
						fclose(fg);
							fclose(ft);
							remove("issue.dat");
							rename("record.dat", "issue.dat");
					}
					
					if(findbook != 't')//else
					{
						
						printf("\n\t\t No record Found\n");
						delay(3000);
						issuebooks();
					}
					
				}
				
			printf("\n\t\t Delete Another?(Y/N)");
			another = getch();
				
			} 

			}
			/*printf("\n\t\t Delete Another?(Y/N)");
			another = getch();*/
			break;
		}
		
		default:{
			printf("\n\t\t Wrong Entry \n");
			getch();
			issuebooks();
			break;
		}
		
	
	}
	
	returnfunc();
} 

/*  Note: Addbooks, and Updatebooks are somehow ok:   Things to Work On:    1. View Function  2. Search Function.*/
