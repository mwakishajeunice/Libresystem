#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h> // use #include <unistd.h> for ubuntu
//where getc(stdin) replace with getch() for window & system("cls") replace with system("clear")
//pointers of global files
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

//The Global Variable
char lib_password[8] = "chrisgud";

//Book structure
struct Book
{
	int book_id;
	char Title[15];
	char Author[15];
	int quantity;
	int rack_no;	
};
struct Book sample;
//E function for Eing pages
void Exit(void)
{
	int i;
	for(i = 3;i>0; i--)
	{
		puts("pleas Wait...");
		//
		printf("%d:-->",i);
		system("cls");
	}
	puts("You have succesfully existed");	
}
int main(void)
	{
		
		home();	
		return 0;
	}
struct login
{
char firstname[12];
char lastname[12];
char username[25];
char password[10];
};
/*Function  for searching books*/
void searchbook()
{
    FILE *fp;
    int Book_id,a;
    char Book_title[16];
    system("cls"); // use system("clear") for ubuntu
    system("color A0");
    
   
    fp = fopen("booksinfoss.dat", "r");
    if(fp==NULL)
    puts("Error opening file!");
    else
    {   
        puts("\t\t*************************** Search Book ******************************");
        puts("\tsearch by:---> 1.Book Id \t\t---> 2.Book Title \t\t---> 3.Exit");
        printf("Enter your choice :");
        scanf("%d",&a);
        struct Book sample;
        if (a == 1)
        {
                    printf("\t\tEnter book id :");
                    scanf("%d",&Book_id);
                    while(!feof(fp))
                    {
                        int results=fread(&sample,sizeof(sample),1,fp);
                        if(results!=0 && Book_id==sample.book_id && sample.book_id!=0)
                        {
                            printf("\n\t\tThe Book Exists\n");
                             
                            printf("\t\t\t%6s %6s %6s %10s %10s\n", "Book Id","Quantity", "Rack No.","Title", "Author");
                            printf("\t\t\t%6d %6d %6d \t%13s \t%s\n",sample.book_id,sample.quantity,sample.rack_no,sample.Title,sample.Author);
                        }
                                        
                    }
                    fclose(fp);
        }
        if (a == 2)
         {

                    printf("\t\tEnter book title:");
                    scanf("%s",Book_title);
                    while(!feof(fp))
                    {
                        int results=fread(&sample,sizeof(sample),1,fp);
                        if(results!=0 && strcmp(Book_title,sample.Title)==0)
                        {
                            printf("\n\t\tThe Book Exists\n");
                            
                            printf("\t\t\t%6s %6s %6s %10s %10s\n", "Book Id","Quantity", "Rack No.","Title", "Author");
                            printf("\t\t\t%6d %6d %6d \t%13s \t%s\n",sample.book_id,sample.quantity,sample.rack_no,sample.Title,sample.Author);                     
                        }
                        
                    }
                    fclose(fp);
         }
        if (a==3)
        {
          printf("existed");  
        }	
            
    }

}

//function for viewing books
void viewbooks(void)
{
    system("cls");
    system("color B1");
    FILE *fb;	
    fb = fopen("booksinfoss.dat", "rb+");
	if (fb == NULL)
	{
		puts("Error opening the file");
	}
	else
	{
        puts("\t\t\t*********************** BOOK LIST **************************************");
        puts("\n\n\t\t\t**********************************************************************");
        puts("\t\t\t**********************************************************************\n");

        printf("\t\t\t%6s %6s %6s %14s %23s\n", "BOOK ID","QUANTITY", "RACK No.","TITLE", "AUTHOR");
        struct Book sample;
        while(!feof(fb))
        {   
	        int results=fread(&sample,sizeof(sample),1,fb);
            if (results!=0 && sample.book_id != 0)
            {
                printf("\t\t\t%6d %6d %6d \t%16s \t%16s\n",sample.book_id,sample.quantity,sample.rack_no,sample.Title,sample.Author);
            }
            
        }
        puts("\n\t\t\t**********************************************************************");
        puts("\t\t\t**********************************************************************");
   
        
    }
   
    fclose(fb);
}

void User_home(void)
{
		system("cls");
        system("color 85");
		int n;
		puts("\n\n***************User Section********************\n");
		puts("\n*************************************************\n");
		puts("Select a task to perform from the list below:");
		puts("\t-->1.Search Books\n");
		puts("\t-->2.View Books\n");
		puts("\t-->3.E\n");
		puts("*************************************************");
		printf("\nEnter Your Choice:");
		scanf("%d",&n);
	switch (n)
	{
		case 1:
			searchbook();  //call Search book functin
			break;
		case 2:
			viewbooks();     //call viewbooks function
			break;
		case 3:
			//E(); //call E function to E
			break;	
		default:
			system("cls");
			puts("INVALID CHOICE TRY AGAIN");
			User_home();
			break;
	}
}
void login(void)
{
	system("cls");//reserve for windows
    system("color CF");
	char username[25];
    char password[10];
    FILE *log;
	char correct = 'n';
    log=fopen("loginss.dat","r+");//opening file for reading
    printf("\nEnter your user name and password to login\n");
    printf("\t\nUsername:");
    scanf("%s",username);
    printf("\t\nPassword:");
    scanf("%s",password);
    while(!feof(log) && correct == 'n')
    {

		struct login a;
		int result = fread(&a, sizeof(struct login), 1, log);
        if(result != 0 && strcmp(username,a.username) == 0 && strcmp(password,a.password) == 0)//compares if username and password matches those in login file
        {

            printf("Successful login!");
            printf("\nWelcome! %s",username);
			correct = 'y';
            User_home();//User_home function
        }
    }
    if(correct == 'n')
        {
            printf("Please Enter correct UserName and password");
            login();
        }
    fclose(log);
}
void registration(void)
{
	FILE *log; 
	log=fopen("loginss.dat","a+"); //open a login file for reading and updating
	struct login a;

	if (log == NULL) {
		puts("ERROR! OPENING FILE!");
	}
	else
	{
		
		puts("\n\tEnter your firstname:"); //append data into the login file
		scanf("%s",a.firstname);
		puts("\n\tEnter your lastname:");
		scanf("%s",a.lastname);
		puts("\n\tEnter your username:");
		scanf("%s",a.username);
		puts("\n\tEnter your password not exceeding 10 characters:");
		scanf("%s",a.password);
		fseek(log,0,SEEK_END); // moving the file to the end allow appending of the next file
		fwrite(&a,sizeof(struct login),1,log);
		printf("Your username is:%s\n",a.username);
	
	
	
	}
	fclose(log);
 	login();    //call login function
}
int Users()
{
	system("cls");
    system("color BD");
	puts("\t############################## LIBRARY SYSTEM #################################");
    printf("\n\n\t\t\t-->Press 1. to REGISTER  \n\t\t\t-->Press 2. to LOGIN\n");
	puts("\t\t\t-->Press 3. to E");
    int num;
	printf("\n\n\t\tPlease enter what you wish to do:");
    scanf("%d",&num);
	if (num==1)
	{
		system("cls");
		printf("Welcome to registration page");
		registration();//call registration function
	}
	else if (num==2)
	{
	system("cls");
	printf("\nEnter your details below for verification");
	login();//call login function
	}
	else if (num==3)
	{
		system("cls");
		main();
	}
	else
	{
		system("cls");
		puts("Invalid option");
		Users();
	}
	
 return 0;
}

//function home for the home page to the user
void home(void)
{
	system("cls");
    system("color 0A");
	// system("color 0A"); //for windows
	puts("\t############################## LIBRARY SYSTEM #################################");
	puts("\n\t\t\t\tPlease select your Category\n"); //prompts user to enter his/her Category i.e User or Admin
	puts("\t\t\t........................................................."); 
	puts("\t\t\t\t--->1.LIbrarian \t\t --->2.Users");
	puts("\n\t\t\t\t--->3.Exit");
	puts("\t\t\t........................................................."); 
	printf("\t\t\tSelect your choice:");
	int n;
	scanf("%d",&n);
		switch(n)
		{
			case 1:
				Librarian_password();
				break;
				
			case 2:
				Users();
				break;
			case 3:
				Exit();
				break;				
			default:
				system("cls");
				printf("\t Invalid Choice! Try Again\n");
				home();
		}
}
// Password for the Librarian to Log in

void Librarian_password()
{
	system("cls");
	char pass[8];
	// char ch, 
	// int i;
	printf("\t\tEnter Your Password:");
    scanf("%s",pass);
//for hiding the password in Asterics
	// for(i=0;i<8;i++){
	// 	ch = getc(stdin);
	// 	pass[i] =ch;
	// 	ch ='*';
		
	// 	printf("%c",ch);
		
	// }
	
	// pass[i] = '\0';
	
	
	// for(i=0;i<8;i++)
	// printf("%c",pass[i]);

	
	if(strcmp(pass,lib_password)==0){
		system("cls");
		Librarian_home();
	}
	
	else{
		system("cls");
		printf("\n\t Incorrect Password! Try Again");
		
		Librarian_password();
		
	}

	
}
//function Librarian for all  administrative use

void Librarian_home(void)
{
	int choice;
	system("cls");
	printf("\n\n\t\t*************** LIBRARIAN SECTION *************************\n");
    printf("\n\n\t\t***********************************************************\n");
	puts("\t\t***********************************************************");
	puts("\n\t\t\tSelect a task to perform from the list below");
    printf("\n\t\t\t1.Add books\t\t2.Delete books\n");
    printf("\n\t\t\t3.Search books\t\t4.View books\n");
    printf("\n\t\t\t5.Issue books\t\t6.Edit book records\n");
    printf("\n\t\t\t7.Return Books\t\t8.E Window\n");
    puts("\n\t\t***********************************************************");
	puts("\t\t***********************************************************");
    printf("\t\t\tSelect your Choice:");
	scanf("%d",&choice);
	
	switch(choice)
	{
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
		    viewbooks();
			break;

			
		case 5:
			// issuebooks();
			break;
			
		case 6:
			editbooks();
			break;
			
		case 7:
			//returnbooks
			break;
		case 8:
		{
			system("cls");
			
			Exit();	
							
			main();
			
		}
		
		default:
			system("cls");
			
			system("color 7C");
			printf("\t\t Invalid choice! Try Again");
			Librarian_home();
			
	}
}

//adding books
void addbooks(void)
{
    system("cls");
    puts("\t********************** Add Books ********************");
    int n;
    FILE *fp;
    fp=fopen("booksinfoss.dat","a+"); //open sample login file for appending and updating

	if (fp == NULL)
        {
            puts("ERROR! OPENING FILE!");
        }
    else 
    {
		
        struct Book sample;
		printf("\n\tEnter Book ID:"); //append data into the login file
		scanf("%d",&sample.book_id);
		printf("\n\tEnter Book Title:");
		scanf("%s",sample.Title);
		printf("\n\tEnter Book Author:");
		scanf("%s",sample.Author);
		printf("\n\tEnter Book rack no:");
		scanf("%d",&sample.rack_no);
        printf("\n\tEnter Quantity:");
		scanf("%d",&sample.quantity);
		// fseek(fp,0,SEEK_END); // moving the file to the end allow appending of the next file
        
        fwrite(&sample, sizeof(struct Book),1 , fp);
        fclose(fp);
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
//function for returning back to Librarian_home
void returnfunc(void)
{
	printf("\n\t Press ENTER to return to the Main Menu  ");
	sample:
		if(getc(stdin)==13) // replace enter key with its equivalent ASCII value
		Librarian_home();
		
		else
		  goto sample;
}

// function for deleting books from the record
void deletebooks(void)
{
    system("cls");
    FILE *fp;
    
    int Book_Id;
    char findbook='n'; int option;
	system("cls");
    fp =fopen("booksinfoss.dat", "r+");
	rewind(fp);	// for taking file pointer to the begining of the file
	if (fp == NULL)
        {
        puts("Error opening the file!");
        }
    else
    {  
        printf("\t\t Enter the Book ID to Delete :  ");
	    scanf("%d", &Book_Id);
	    
        struct Book sample;
        int count=0;        
		while(!feof(fp) && findbook=='n')
        { 
            int results=fread(&sample,sizeof(struct Book),1,fp);
            count += results;
			//finding if the user input matches book id in the system 
			if(results !=0 && sample.book_id==Book_Id && findbook=='n')
            {
				printf("\t\t The Books Record is available\n");
                
				printf("\n\t\t\t%6s %6s %6s %10s %10s\n", "Book Id","Quantity", "Rack No.","Title", "Author");
                printf("\t\t\t%6d %6d %6d \t%13s \t%s\n",sample.book_id,sample.quantity,sample.rack_no,sample.Title,sample.Author);				
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
                        fseek(fp,(count-1)*sizeof(struct Book),SEEK_SET);
                        struct Book blank = {0,"","",0,0};
                        fseek(fp,(count-1)*sizeof(struct Book),SEEK_SET);
                        fwrite(&blank,sizeof(struct Book),1,fp);
						
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
            fclose(fp);	
    }
}  

// function for editing books
void editbooks(void)
{
    system("cls");
    FILE *fp=NULL;
    int n,Book_id,choice;
    char option='n';
    fp=fopen("booksinfoss.dat","r+");
    rewind(fp);
    if (fp==NULL)
        {
            puts("Error opening File!!");
        }
    else
    {
        int count=0;
        struct Book sample;
        printf("\n\t\tEnter the Book id to edit:");
        scanf("%d",&Book_id);
       while(!feof(fp) && option=='n')
        {
            int results=fread(&sample,sizeof(struct Book),1,fp);
            count+=results;
            if (results!=0 && Book_id==sample.book_id && option=='n')
            {
                printf("\t\t The Books Record is available\n");
                
				printf("\t\t\t%6s %6s %6s %10s %10s\n", "Book Id","Quantity", "Rack No.","Title", "Author");
                printf("\t\t\t%6d %6d %6d \t%13s \t%s\n",sample.book_id,sample.quantity,sample.rack_no,sample.Title,sample.Author);				
				option = 'y';
            }
            
        }
       
        if (option=='n')
            {
                //if no book of such id is found
            printf("\t\t No book of such Id exist");
            editbooks();
              
            }
        if (option=='y')
        {
            puts("\t\t\tAre you true to edit-->Press 1.[Yes] -->2.[No]");
            
            scanf("%d",&choice);
            switch (choice)
            {
                case 1:
                    fseek(fp,(count-1)*sizeof(struct Book),SEEK_SET);
                    printf("\n\tEnter New Book ID:"); //append data into the login file
                    scanf("%d",&sample.book_id);
                    printf("\n\tEnter New Book Title:");
                    scanf("%s",sample.Title);
                    printf("\n\tEnter New Book Author:");
                    scanf("%s",sample.Author);
                    printf("\n\tEnter New  Book rack no:");
                    scanf("%d",&sample.rack_no);
                    printf("\n\tEnter New Quantity:");
                    scanf("%d",&sample.quantity);
                    // fseek(fp,0,SEEK_END); // moving the file to the end allow appending of the next file
                    
                    fseek(fp,(count-1)*sizeof(struct Book),SEEK_SET);
                    fwrite(&sample, sizeof(struct Book),1 , fp);
                    fclose(fp);
                    puts("\n\tBook succesfully eddited");
                    puts("\n\tEdit another book?\t press 1.(Yes) or 2.(No)");
                    scanf("%d",&n);
                    if (n == 1)
                        {
                            editbooks(); 
                        }
                        else 
                        {
                        puts("Invalid option try again");
                        Librarian_home();
                        }
                    break;
                case 2:
                puts("Please wait...");
                
                Librarian_home();
                break; 
				default:
				puts("Invalid entry please try again");
				editbooks();        
            }
                        
                        
                                
        }
    }            
}	

 
