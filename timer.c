#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <dos.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int i;
	for (i=10;i>0;i--)
	{
		delay(1000);
		printf("%d",i);
		
	}
	return 0;
}
