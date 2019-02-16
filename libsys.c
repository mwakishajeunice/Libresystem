#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include <windows.h>
#include <string.h>
#include <conio.h>


 char categories [][17] = {"mathematics","computer","Education","Psychology","Medicine","engineering"};

void mainmenu(void) //displays main menu of this project
void returnfunc(void) //main menu function is called when user presses a key(a user can return back to main menu)
void addbooks(void)
void deletebooks(void)
void editbooks(void)
void searchbooks(void)
void viewbooks(void)
void issuerecord(void) //keeps record of the student to whom book has been issued
void closeapplication(void)
//int getdata() //asks for data input from the user
int checkid(int) //ID entered exists in file or not
void password()
delay(unsigned int mseconds)


void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while(goal>clock());
}



struct Books
{
    int ID;
    char name[20];
    char author[15];
    int quantity;
    int rackno;
};

void mainmenu()
{
    system("cls");
    printf(".................................");
    printf("\t\t\t\n\n 1.Add Books\n");
    printf("\t\t\t\n\n 2.Delete Books\n");
    printf("\t\t\t\n\n 3.Search Books\n");
    printf("\t\t\t\n\n 4.Issue Books\n");
    printf("\t\t\t\n\n 5.View Book List\n");
    printf("\t\t\t\n\n 6.Edit Book's Record\n");
    printf("\t\t\t\n\n 7.Close Application\n");
    printf("..................................");

    printf("Enter your Choice : ");
    switch(getch())
    {
    case '1' :
        addbooks();
        break;
    case '2' :
        deletebooks();
        break;
    case '3' :
        searchbooks();
        break;
    case '4' :
        issuebooks();
        break;
    case '5' :
        viewbooks();
        break;
    case '6' :
        editbooks();
        break;
    case '7' :
        {
            system("cls");
            printf("\t\tThanks for using this program..\n");
        }
        default:
        {
            printf("\t Wrong Entry!!Please re-enter correct option");
            if (getch())
            mainmenu();
        }
    }
    void addbooks(void)  //function that adds books
    {
        system("cls");
        printf("\t\t\n..........Select Categories........");
        printf("\t\t\n 1. Mathematics\n");
        printf("\t\t\n 2. Computer\n");
        printf("\t\t\n 3. Education\n");
        printf("\t\t\n 4. Psychology\n");
        printf("\t\t\n 5. Medicine\n");
        printf("\t\t\n 6. Engineering\n");
        printf("\t\t\n 7. Back to main menu \n");
        printf("..................................");

        printf("Enter your Choice : ");
        scanf("%d",&s);
        
    }
}

