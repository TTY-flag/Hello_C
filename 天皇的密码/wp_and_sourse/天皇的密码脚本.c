#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void updecode(char *a1)
{
  size_t result; // rax
  int i; // [rsp+2Ch] [rbp-54h]
  //char *Str; // [rsp+50h] [rbp-30h]

  //Str = a1;                        Str即a1，直接改掉 
  for ( i = 0; ; ++i )
  {
    result = strlen(a1) >> 1;
    if ( i >= result )
      break;
    a1[i] = ((a1[i] - 97)>=(97%26))?(a1[i] - 97-97%26+'a'):(a1[i] - 97+'h');
    a1[i]-=3;
    if(a1[i]-'a'<0) a1[i]+=26 ;
    else if(a1[i]-'z'>0) a1[i]-=26;
  }
}

void downdecode(char *a1)
{
  int v1; // ecx
  //__int64 result; // rax
  signed int i; // [rsp+Ch] [rbp-4h]
  //__int64 v4; // [rsp+20h] [rbp+10h]           v4即a1，直接改掉 

  //v4 = a1;
  for ( i = 0; i <= 5; ++i )
  {
  	a1[i] = ((a1[i] - 97)>=(97%26))?(a1[i] - 97-97%26+'a'):(a1[i] - 97+'h');
    a1[i]-=5;
    if(a1[i]-'a'<0) a1[i]+=26 ;
    else if(a1[i]-'z'>0) a1[i]-=26;
    //result = (unsigned int)(v1 + 97);
    
  }
}

void generate()
{
  size_t v0; // rbx
  __int64 v2; // [rsp+20h] [rbp-60h]
  __int64 v3; // [rsp+28h] [rbp-58h]
  int v4; // [rsp+30h] [rbp-50h]
  char Str[8]; // [rsp+40h] [rbp-40h]
  int i; // [rsp+58h] [rbp-28h]
  char v7; // [rsp+5Fh] [rbp-21h]

  strcpy(Str, "2^bl`6id`e2`h");
  char v[]="flag{?????????????}";
  for ( i = 0; ; ++i )
  {
    v0 = i;
    if ( v0 >= strlen(Str) )
      break;
    if ( i & 1 )
      v7 = 1;
    else
      v7 = -1;
    *(v + i + 5) = Str[i] + v7;
  }
    printf("\nHere is the flag:  %s\n\n", v);
}


int main()
{
	char Str1[]="lupdkjgqemmb";
	updecode(Str1);
	downdecode(Str1+6);
	printf(Str1);
	generate(); 
	return 0;
	
}
