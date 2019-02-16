#include <stdio.h>
#include <windows.h>

void Librarian_home(void);
void getdata(void);
void delay(void);
FILE *fb;
int choice;


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
