#include<stdio.h>
int main()
{
	FILE *fpointer;
	fpointer = fopen("Books_categories.txt","w");
	fprintf(fpointer ,"1.COMPUTER\n2.MATHEMATICS\n3.MEDICINE\n4.EDUCATION\n5.PSYCHOLOGY\n7.PHYSICS\n\n\t\t\t");
	fclose(fpointer);
	return 0;
}