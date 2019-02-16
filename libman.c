#include<stdio.h>
#include<windows.h>
#include<string.h>


int option;
char lname[10], fname[10] ,username[20] , Password[15];

 void user(void)
{
	system("cls");
	printf("Enter First Name : \n");
	scanf("%s",fname);
	printf("Enter Last Name : \n");
	scanf("%s",lname);
	printf("Enter User_name : \n");
	scanf("%s",username);
	
}
void password(void)
{
	system("cls");
	char admin[30] = "Password Protected";
	char userpass, pass[10];
	int i,j;
	for(j=0;j<20;j++)
    {
    printf("*");
    }
    for(j=0;j<20;j++)
   {
   printf("%c",admin[j]);
   }
   for(j=0;j<20;j++)
   {
   printf("*");
   }
	printf("Enter Your Password : \n");
	scanf("%s",Password);
	while(userpass!=13)
   {
 	userpass=getc(stdin);

 if(userpass!=13 && userpass!=8){
 puts("*");
 pass[i] = userpass;
 i++;
 }
   }
   pass[i] = '\0';
   if(strcmp(pass,Password)==0)
   {

 printf("Password match");
 printf("Press any key to continue.....");
 getc(stdin);
 //mainmenu();
   }
   else
   {
  printf("\aWarning!! Incorrect Password");
  getc(stdin);
  password();
   
	
}

void login(void)
{
	printf("@@@@@@@@@@@@@@@@@@@@@@@Two Sections Available in This Library System@@@@@@@@@@@@@@@@@\n\t");
	printf("1.USER SECTION\n\t\t\n");
	printf("2.ADMIN SECTION\n\t\t\n");
	printf("Enter Your Choice : ");
	switch (getc(stdin))
	{
		case '1':
		{
			system("cls");
			user();
			break;
		}
		case '2':
		{
			system("cls");
			password();
			break;
		}
	}
}
    
int main()
{
	FILE *fpointer;
	fpointer = fopen("Books_categories.txt","w");
	fprintf(fpointer ,"1.COMPUTER\n2.MATHEMATICS\n3.MEDICINE\n4.EDUCATION\n5.PSYCHOLOGY\n7.PHYSICS\n\n\t\t\t");
	fclose(fpointer);
	return 0;
}