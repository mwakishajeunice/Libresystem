#include <stdio.h>

void add(void);
void viewBook(void);

// glabal pointer
FILE *bookPtr;

// global structs
typedef struct
{
  int id, rack_no, price, copies;
  char title[40], author[40], category[40];
} BOOK;

int main(int argc, char const *argv[])
{
  add();
  viewBook();
  return 0;
}

void add(void)
{
  bookPtr = fopen("booksinfo.dat", "a+");
  if (bookPtr == NULL) {
    puts("Error opening the fle");
  }
  else
  {
    printf("Enter book id ");
    printf("Enter book id ");printf("Enter book id ");printf("Enter book id ");printf("Enter book id ");printf("Enter book id ");
  }
  
  
}

/// Testers




void deletebooks(void){
	system("cls");
	FILE *bks, *t_bks;

	int BookId;
	char findbook;
	char another ='y';
	while(another=='y'){
		system("cls");
		
		printf("\t\t Enter the Book ID to Delete :  ");
		scanf("%d", &BookId);
		bks = fopen("books_info.dat" , "rb+");

		rewind(bks); // for taking file pointer to the begining of the file
		struct Book book;
		while(fread(&book,sizeof(book),1,bks)==1){
			//finding if the user input matches book id in the system 
			if(book.book_id==BookId){
				printf("\t\t The Books Record is available\n");
				// until u add address it doesn't give books details
				printf("\t The Book Title :%s ",book.Title);
				printf("\t The Book Rack No :%d",book.rack_no);
				
				findbook = 't';
			}
			
		}
		
		
		if(findbook !='t'){
			//if no book of such id is found
		
			printf("\t\t No book of such Id exist");
			
		}
	
		
	  if(findbook == 't'){
			printf("\t\t Delete? (Y/N): ");
			scanf("%c",&another);
			
			if(another== 'y'){
				t_bks =fopen("tests.dat", "wb+"); //temporary file for delete book
				rewind(bks); //file pointer at the beginning of the file
				
				while(fread(&book,sizeof(book),1,bks)==1){
					
					if(book.book_id != BookId){
						fseek(t_bks,0,SEEK_CUR);
						fwrite(&book,sizeof(book),1,t_bks); // write temporary files except those to be deleted
					}
				}
				fclose(t_bks);
				fclose(bks);
				remove("books_info.dat");
				rename("tests.dat","books_info.dat"); // copy books.dat to test.dat except data we want to delete
				//fbbks= fopen("books.dat", "rb+");
				
				if(findbook == 't'){
					printf("\t\t Successful delete\n");
					printf("\t\t Delete Another? (Y/N)  ");
					//another = getch();
					 // improve the delete function to be real time. Deleteing multiple files
					
				}
				//fclose(fbbks); //  can add it anywhere it helps
				
			}
			
			else
			Librarian_home();
			fflush(stdin);
			
			
		}
		
		
	}
	
	Librarian_home();
}