#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <windows.h> // use #include <unistd.h> for ubuntu
//where getc(stdin) replace with getch() for window & system("cls") replace with system("cls")
//pointers of global files
FILE *Vw=NULL,*fb=NULL,*fd=NULL,*fg=NULL;
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

 void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
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
//exit function for Exiting pages
void Exit(void)
{
	int i;
	for(i = 3;i>0; i--)
	{
		puts("pleas Wait...");
		// delay(1000);
		printf("%d:-->",i);
		system("cls");
	}
	puts("You have succesfully exited");	
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
    system("cls"); // use system("cls") for windows
    system("color AF");
   
    fp = fopen("booksinfo.dat", "rb+");
    if(fp==NULL)
    puts("Error opening file!");
    else
    {   
        puts("\t\t*************************** Search Book ******************************");
        puts("\tsearch by:---> 1.Book Id \t\t---> 2.Book Title \t\t");
        printf("Enter your choice:");
        scanf("%d",&a);
        struct Book sample;
        if (a == 1)
        {
                    printf("\t\tEnter book id:");
                    scanf("%d",&Book_id);
                    while(!feof(fp))
                    {
                        int results=fread(&sample,sizeof(sample),1,fp);
                        if(results!=0 && Book_id==sample.book_id && sample.book_id!=0)
                        {
                            printf("\n\t\tThe Book Exists\n");
                            // delay(1);
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
          int r;
            printf("Press 1 to back\t:");
            scanf("%d",&r);

            if (r==1) 
            {
                // goes back to customized view
            }
            else
            {
                searchbook();
            }
    }
}
//function for viewing books
void viewbooks(void)
{
    system("cls");
    system("color 0A");
    FILE *fb;	
    fb = fopen("booksinfo.dat", "rb+");
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
		int n,r;
		puts("\n\n***************User Section********************\n");
		puts("\n*************************************************\n");
		puts("Select a task to perform from the list below:");
		puts("\t-->1.Search Books\n");
		puts("\t-->2.View Books\n");
		puts("\t-->3.Exit\n");
		puts("*************************************************");
		printf("\nEnter Your Choice:");
		scanf("%d",&n);
	switch (n)
	{
		case 1:
			searchbook();  //call Search book functin
            User_home();
            
            
			break;
		case 2:
			viewbooks();     //call viewbooks function
            puts("Press 1 to back");
            scanf("%d",&r);

            if (r==1) 
            {
                // delay(1000);
                User_home();
            }
            else
            {
                viewbooks();
            }

			break;
		case 3:
		home(); //call home function to exit
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
    system("color DE");
	char username[25];
    char password[10];
    FILE *log;
	char correct = 'n';
    log=fopen("login.dat","r+");//opening file for reading
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
	log=fopen("login.dat","a+"); //open a login file for reading and updating
    rewind(log);
	//struct login a;
    char username[20],stop='n';

	if (log == NULL)
        {
            puts("ERROR! OPENING FILE!");
        }
	else
	{
		printf("\n\tEnter your username:");
		scanf("%s",username);
        // strcpy(a.username,username);
        while(!feof(log) && stop=='n')
        {
            struct login a;
            fread(&a,sizeof(struct login),1,log);
            if (strcmp(username,a.username)==0)
                {
                    puts("Username has already been taken");
                    stop='y';  
                    // delay(1000);
                    registration();
                }
        }
        if (stop =='n')
            {
                struct login a;
                strcpy(a.username,username);
                printf("\n\tEnter your firstname:"); //append data into the login file
                scanf("%s",a.firstname);
                printf("\n\tEnter your lastname:");
                scanf("%s",a.lastname);
                printf("\n\tEnter your password not exceeding 10 characters:");
                scanf("%s",a.password);
                fwrite(&a,sizeof(struct login),1,log);
                printf("Your username is:%s\n",a.username);
                // delay(1000);
            }
	}
	fclose(log);
 	login();    //call login function
}	
int Users(void)
{
	system("cls");
    system("color 78");
	puts("\t############################## LIBRARY SYSTEM #################################");
    printf("\n\n\t\t\t-->Press 1. to REGISTER \t\t-->Press 2. to LOGIN\n");
	puts("\n\t\t\t-->Press 3. to Exit");
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
		puts("Invalid stop");
		Users();
	}
	
 return 0;
}

//function home for the home page to the user
void home(void)
{
	system("cls");
	system("color 0A"); //for windows
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
	//char ch; 
	//int i;
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
		// // delay(3000); //works in linux use delay for windows1
		Librarian_password();
		
	}

	
}
void issuebook(void)
{
    FILE *fp,*fissue,*fuser;
    system("cls");
    system("color B0");
    struct ISSUED
    {
        char username[20];
        int bookid;
        char booktitle[20];
    };
    struct ISSUED issued;
    int n,Book_id;
    int y,d;
    char option1='n',option2='n',username[12];
    fp = fopen("booksinfo.dat", "rb+");
    fissue = fopen("issue.dat", "a+");
    fuser=fopen("login.dat","rb+");
    if (fp==NULL && fissue==NULL && fissue==NULL)
        {
            puts("Error opening the file");
        }
    else
    {
        struct Book sample;
        struct login a;
        puts("\n\t************************** ISSUE BOOK SECTION *******************************");
        puts("\n\n\t*****************************************************************************");
        puts("\t*****************************************************************************");
        printf("\n\n\t\t--> 1.Issue a Book \t\t--> 2.View Issued Books\n");
        printf("\n\t\t--> 3.Search Issued Books \t--> 4.Remove Issued book\n");
        printf("\n\t\t--> 5.Exit\n");
        puts("\n\n\t*****************************************************************************");
        puts("\t*****************************************************************************");
        printf("\n\t\t Enter your choice :  ");
        scanf("%d",&n);
        switch (n)
        {
            case 1: //issue a book
            system("cls");
            printf("\n\t\tEnter the Book id to be issued:");
            scanf("%d",&Book_id);
            printf("\n\t\tEnter the username of the user:");
            scanf("%s",username);
            char book_title[20];
            int coun=0;
            while(!feof(fp) && option1=='n' )
                {
                    int results=fread(&sample,sizeof(struct Book),1,fp);
                    coun+=results;
                    if (results!=0 && Book_id==sample.book_id)
                    {
                        fseek(fp,(coun-1)*sizeof(struct Book),SEEK_SET);
                        --sample.quantity;
                        fseek(fp,(coun-1)*sizeof(struct Book),SEEK_SET);
                        fwrite(&sample,sizeof(struct Book),1,fp);
                        strcpy(book_title, sample.Title);
                        printf("\t\t The Books Record is available");
                        // delay(1);
                        printf("\tBeing Issued to:%s",username);
                        printf("\n\t\t\t%6s %6s %6s %10s %10s\n", "Book Id","Quantity", "Rack No.","Title", "Author");
                        printf("\t\t\t%6d %6d %6d \t%13s \t%s\n",sample.book_id,sample.quantity,sample.rack_no,sample.Title,sample.Author);				
                        option1 = 'y';
                    }
                    
                    
                }
            while(!feof(fuser) && option2=='n')
            {
                int results=fread(&a,sizeof(struct login),1,fuser);
                if (results!=0 && strcmp(username,a.username)==0)
                {
                    puts("username available");
                    option2='y';
                }
                
                else 
                {
                    //if user not in the system
                    printf("No such user exists");
                }
            }
                if (option1=='n')
                    {
                        //if no book of such id is found
                        printf("\t\t No book of such Id exist");
                        // delay(1000);  
                        issuebook();
                    }
                if (option1 == 'y' && option2=='y')
                    {
                        struct ISSUED issued;
                        // delay(1000);
                        strcpy(issued.username,username);
                        issued.bookid=Book_id;
                        strcpy(issued.booktitle,book_title);
                        printf("Book issued succesfully");
                        fwrite(&issued,sizeof(struct ISSUED),1,fissue);
                        fclose(fp);
                        fclose(fissue);
                        fclose(fuser);
                        printf("\n\t\t Issue More Book? --> Press 1[yes]\t\t--> Press 2[no]:");
				        scanf("%d",&y);
                        if (y==1)
                        {
                            // delay(1000);
                            issuebook();
                        }
                        else
                        {
                            issuebook();
                        }
                    }
                break;
            case 2://view issued books
                system("cls");
                fissue=fopen("issue.dat","rb+");
                if (fissue==NULL) 
                    {
                       puts("Error opening the file");
                    }
                else
                {
                    puts("\t\t\t***********************ISSUEDBOOK LIST **************************************");
                    puts("\n\n\t\t\t**********************************************************************");
                    puts("\t\t\t**********************************************************************\n");
                    printf("\t\t\t%12s %12s %14s\n", "Username", "Book Id","Book title");
                    struct ISSUED issued;
                    while(!feof(fissue))
                    {   
                        int results=fread(&issued,sizeof(struct ISSUED),1,fissue);
                        if (results!=0 && issued.bookid != 0)
                        {
                            printf("\t\t\t%12s %12d %14s\n",issued.username,issued.bookid,issued.booktitle);
                        }
                    }
                    
                    puts("\n\t\t\t**********************************************************************");
                    puts("\t\t\t**********************************************************************");

                }
                    printf("\t\t\t-->Press 1 to go back :");
                    scanf("%d",&d);
                    if (n==1)
                        {
                            // delay(1000);
                            issuebook();
                        }                    
                    fclose(fissue);
                break;
            case 3://search issued book
                system("cls");
                int stop;
                fissue=fopen("issue.dat","rb+");
                if (fissue==NULL)
                    {
                        puts("Error opening the file");
                    }
                else
                    {
                      printf("Enter the book id: ");
                      scanf("%d",&Book_id); 
                      while(!feof(fissue))
                    {
                        int results=fread(&issued,sizeof(issued),1,fissue);
                        if(results!=0 && Book_id==issued.bookid && issued.bookid!=0)
                        {
                            printf("\n\t\tThe Book Exists\n");
                            // delay(1);
                            printf("\t\t\t%6s %6s %14s\n", "Username", "Book Id","Book title");
                            printf("\t\t\t%6s %6d %14s\n",issued.username,issued.bookid,issued.booktitle);
                           
                        }
                    }
                    fclose(fissue);
                    // delay(2000);
                    issuebook();
                    }
                    break;
                                                  
                case 4:// remove issued book
                    system("cls");
                    int Book_id;
                    char findbook='n';
                    fissue =fopen("issue.dat", "rb+");
                    fp=fopen("booksinfo.dat","rb+");
	                rewind(fissue);	// for taking file pointer to the begining of the file
                        printf("\t\t Enter the Book ID to Delete :  ");
                        scanf("%d",& Book_id);
                        struct Book sample;
                        struct ISSUED issued;
                        int count=0;        
		                while(!feof(fissue) && findbook=='n')
                        { 
                            int results=fread(&issued,sizeof(struct ISSUED),1,fissue);
                            count += results;
                            //finding if the user input matches book id in the system 
			                if(results !=0 && Book_id== issued.bookid )
                            {
                            fseek(fissue,(count-1)*sizeof(struct ISSUED),SEEK_SET);
                            ++sample.quantity;
                            fseek(fissue,(count-1)*sizeof(struct ISSUED),SEEK_SET);
                            printf("\t\t The Books Record is available\n");
                            // delay(1000);
                            printf("\t\t\t%6s %6s %14s\n", "Username", "Book Id","Book title");
                            printf("\t\t\t%6s %6d %14s\n",issued.username,issued.bookid,issued.booktitle);			
                            findbook = 'y';
                            }
		                }
                        if(findbook =='n')
                        {
                            //if no book of such id is found
                            printf("\t\t No book of such Id exist");
                            issuebook();
                            // delay(2000);
                        }
                        if (findbook =='y')
                        {
                            puts("\t\t\tAre you true to remove?-->Press 1.[Yes] -->2.[No]");
                            // delay(1);
                            scanf("%d",&stop);
                            switch (stop)
                            {
                                case 1:
                                    fseek(fissue,(count-1)*sizeof(struct ISSUED),SEEK_SET);
                                    struct ISSUED blank = {"",0,""};
                                    fseek(fissue,(count-1)*sizeof(struct ISSUED),SEEK_SET);
                                    fwrite(&blank,sizeof(struct ISSUED),1,fissue);
                                    fclose(fissue);
                                    // delay(1000);
                                    issuebook();
                                    break;
                                case 2:
                                    issuebook();// call a function to exit this function                        
                                    break;
                                default:
                                    puts("Invalid stop try again");
                                    issuebook();
                                    break;
                            }
                        }
                case 5:
                    system("cls");
                    // delay(1);
                    Librarian_home();//call Librarian Home
                    break;         
                default:
                puts("Invalid stop");
                issuebook();
                break;
        }
    }
    fclose(fp);
    fclose(fuser);
    fclose(fissue);
}
void viewusers(void)
{
    system("cls");
    system("color 90");
    FILE *Vw;
    Vw=fopen("login.dat","rb+");
    if (Vw==NULL)
        {
            puts("Error opening the file!");
        }
    else
    {
        puts("\t\t\t*********************** USERS' LIST **********************************");
        puts("\n\n\t\t\t**********************************************************************");
        puts("\t\t\t**********************************************************************\n");
        printf("\t\t\t%14s %12s %12s\n","USERNAME","FIRSTNAME","LASTNAME");
        struct login a;
        while(!feof(Vw))
        {
        int results=fread(&a,sizeof(struct login),1,Vw);
        if (results !=0)
            {
        
                printf("\t\t\t%12s %12s %12s\n",a.username,a.firstname,a.lastname);
            }
        }
        puts("\n\t\t\t**********************************************************************");
        puts("\t\t\t**********************************************************************");
    }
    fclose(Vw);
    int n;
    printf("\t\t\t --> Press 1. to back:");
    scanf("%d",&n);
    switch (n)
    {
        case 1:
            system("cls");
            Librarian_home(); //call librarian home
            break;
    
        default:
            system("cls");
            puts("\n\t\t\tInvalid stop\n");
            viewusers();
            break;
    }
    
   
}
//function Librarian for all  administrative use

void Librarian_home(void)
{
	int choice,n;
	system("cls");
    system("color 20");
	printf("\n\n\t\t*************** LIBRARIAN SECTION *************************\n");
    printf("\n\n\t\t***********************************************************\n");
	puts("\t\t***********************************************************");
	puts("\n\t\t\tSelect a task to perform from the list below");
    printf("\n\t\t\t--> 1.Add books\t\t--> 2.Delete books\n");
    printf("\n\t\t\t--> 3.Search books\t--> 4.View books\n");
    printf("\n\t\t\t--> 5.Issue books\t--> 6.Edit book records\n");
    printf("\n\t\t\t--> 7.View Users\t--> 8.Exit\n");
    puts("\n\t\t***********************************************************");
	puts("\t\t***********************************************************");
    printf("\t\t\tSelect your Choice:");
	scanf("%d",&choice);
	
	switch(choice)
	{
		case 1:
			addbooks();
            puts("\t\tPress 1 to back");
            scanf("%d",&n);
            if (n==1)
            {
            //    delay(1);
               Librarian_home(); 
            }
            else
            {
                addbooks();
            }
            
			break;
		
		case 2:
			deletebooks();
            puts("\t\tPress 1 to back");
            scanf("%d",&n);
            if (n==1)
            {
            //    delay(1);
               Librarian_home(); 
            }
            else
            {
                deletebooks();
            }
            
			break;
			
		case 3:
			searchbook();
            Librarian_home(); 
            
			break;
			
		case 4:
		    viewbooks();
            puts("\t\tPress 1 to back");
            scanf("%d",&n);
            if (n==1)
            {
            //    delay(1);
               Librarian_home(); 
            }
            else
            {
                viewbooks();
            }
            
			break;

			
		case 5:
			issuebook();
            puts("\t\tPress 1 to back");
            scanf("%d",&n);
            if (n==1)
            {
               delay(1);
               Librarian_home(); 
            }
            else
            {
                issuebook();
            }
            
			break;
			
		case 6:
			editbooks();
            puts("\t\tPress 1 to back");
            scanf("%d",&n);
            if (n==1)
            {
               delay(1000);
               Librarian_home(); 
            }
            else
            {
                editbooks();
            }
            
			break;
			
		case 7:
			viewusers();
			break;
		case 8:
            home();
            break;
		
		default:
			system("cls");
			
			// system("color 7C");
			printf("\t\t Invalid choice! Try Again");
			Librarian_home();
            break;
			
	}
}

//adding books
void addbooks(void)
{
    system("cls");
    system("color  4E");
    puts("\t********************** Add Books ********************");
    int n,Book_id;
    FILE *fp;
    fp=fopen("booksinfo.dat","a+"); //open sample login file for appending and updating

	if (fp == NULL)
        {
            puts("ERROR! OPENING FILE!");
        }
    else 
    {
		
        struct Book sample;
        Book_id=sample.book_id;
		printf("\n\tEnter Book ID:"); //append data into the login file
		scanf("%d",&Book_id);
        while(!feof(fp))
        {
            fread(&sample,sizeof(struct Book),1,fp);
            if (Book_id==sample.book_id)
                {
                    puts("Book with similar Id exists");
                    delay(1000);
                    Book_id=0;
                    addbooks();
                }
        }
        
        if(Book_id!=0)
            { 
                sample.book_id=Book_id;
                printf("\n\tEnter Book Title:");
                scanf("%s",sample.Title);
                printf("\n\tEnter Book Author:");
                scanf("%s",sample.Author);
                printf("\n\tEnter Book rack no:");
                scanf("%d",&sample.rack_no);
                printf("\n\tEnter Quantity:");
                scanf("%d",&sample.quantity);
                // fseek(fp,0,SEEK_END); // moving the file to the end allow appending of the next file
                delay(2);
                fwrite(&sample, sizeof(struct Book),1 , fp);
                fclose(fp);
                puts("\n\tBook succesfully added");
                puts("\n\tAdd another book?\t press 1.(Yes) or 2.(No)");
                scanf("%d",&n);
                
                

                if (n == 1)
                    {
                        addbooks(); 
                    }
                
                else
                {
                   system("cls");
                   Librarian_home();                     
                }
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
    system("color 0D");
    FILE *fp;
    int Book_Id;
    char findbook='n'; int stop;
	system("cls");
    fp =fopen("booksinfo.dat", "rb+");
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
                delay(1000);
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
            delay(2000);
		}
        if (findbook =='y')
            {
                puts("\t\t\tAre you true to delete?-->Press 1.[Yes] -->2.[No]");
				printf("\t\t\tEnter your choice:");
                delay(1000);
                scanf("%d",&stop);
                switch (stop)
                {
                    case 1:
                        fseek(fp,(count-1)*sizeof(struct Book),SEEK_SET);
                        struct Book blank = {0,"","",0,0};
                        fseek(fp,(count-1)*sizeof(struct Book),SEEK_SET);
                        fwrite(&blank,sizeof(struct Book),1,fp);
                        puts("Book Deleted...");
						delay(2000);
                        fclose(fp);
						Librarian_home();
                        break;
                    case 2:
						puts("Please wait...");
						delay(1000);
                        Librarian_home();
                        break;                
                    default:
                        puts("Invalid stop try again");
                        deletebooks();
                        break;
                }


            }
    }
}  

// function for editing books
void editbooks(void)
{
    system("cls");
    system("color 0C");
    FILE *fp=NULL;
    int n,Book_id,choice;
    char stop='n';
    fp=fopen("booksinfo.dat","r+");
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
       while(!feof(fp) && stop=='n')
        {
            int results=fread(&sample,sizeof(struct Book),1,fp);
            count+=results;
            if (results!=0 && Book_id==sample.book_id && stop=='n')
            {
                printf("\t\t The Books Record is available\n");
                delay(1000);
				printf("\t\t\t%6s %6s %6s %10s %10s\n", "Book Id","Quantity", "Rack No.","Title", "Author");
                printf("\t\t\t%6d %6d %6d \t%13s \t%s\n",sample.book_id,sample.quantity,sample.rack_no,sample.Title,sample.Author);				
				stop = 'y';
            }
            
        }
       
        if (stop=='n')
            {
                //if no book of such id is found
            printf("\t\t No book of such Id exist");
            editbooks();
            delay(1000);  
            }
        if (stop=='y')
        {
            puts("\t\t\tAre you true to edit-->Press 1.[Yes] -->2.[No]");
            delay(1000);
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
                        puts("Invalid stop try again");
                        Librarian_home();
                        }
                    break;
                case 2:
                puts("Please wait...");
                delay(2000);
                Librarian_home();
                break; 
				default:
				puts("Invalid entry please try again");
				editbooks();        
            }
        }
    }            
}
