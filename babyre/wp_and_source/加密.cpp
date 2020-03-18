#include<stdio.h>
#include<stdlib.h>
main(){
	char a[17]="we1c0me_t0_JNCTF";
	int v[16]={35,45,88,16,111,92,22,0,45,9,42,56,40,114,53,33};
	char c[17];
	int i;
	scanf("%s",c);
	for(i=0;i<16;i++)
	{
		if(   (  ~(c[i] & v[i])  &   (c[i] | v[i]) )   !=a[i]    )
		{
		printf("sorry\n");
		break;
	    }
	}
	if(i==16)printf("you are right!");
	system("pause"); 
} 
