#include <stdio.h>
#include <conio.h>

//int ferror(FILE *fp);
//void clearerr (FILE *fp);

int main()
{
    int status;
    char data[20] = "hello learner";
    FILE *fp;

    fp = fopen("example.txt" , "a");
    if(fp != NULL)
    {
        fprintf(fp, "%s", data);
        status = ferror(fp);
        printf("%d\n",status);
        clearerr(fp);
         status = ferror(fp);
        printf("%d\n",status);
        if(status == 0){
            puts("No read or write errors");
        }else
        {
            puts("read or write errors has occured");
        }
        
    } else
     {
         puts("Unable to open the file");

    }
    getch();
    return 0;
}
