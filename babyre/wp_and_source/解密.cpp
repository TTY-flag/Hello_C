#include<stdio.h>
#include<stdlib.h>
main(){
	char a[17]="we1c0me_t0_JNCTF";
	int v[16]={35,45,88,16,111,92,22,0,45,9,42,56,40,114,53,33};
	char c[17];
	for(int i=0;i<16;i++)
	{
		c[i]=a[i]^v[i];
		printf("%c",c[i]);
	}
} 
