#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//flag{1_am_7he_f1ag}
//password: pythonisgood

void upencode(char *p)  //encode the up half
{
	int i=0;
	for(i=0;i<strlen(p)/2;i++)
	{
		p[i]=(p[i]+3)%26+'a';
	}
}

void downencode(char *p)  //encode the down half
{
	int i=0;
	for(i=0;i<6;i++)
	{
		p[i]=(p[i]+5)%26+'a';
	}
}

void generate()          // generate the flag
{
    char v3;
    long v5;
    char s[] = "2^bl`6id`e2`h";         
    char t[] = "flag{?????????????}";   

    v5 = 0;
    while (v5 < strlen(s)) {
        if (v5 & 1)
            v3 = 1;
        else
            v3 = -1;
        *(t + v5 + 5) = s[v5] + v3;
        v5++;
    }
    printf("Here is the flag:  %s\n\n", t);

}



int main()
{
	printf("     Welcome To JNCTF  \n");
	printf("--------------------------\n");
	printf("----------Log In----------\n");
	printf("Username:Sun Xiaochuan\n");
	printf("Password:");
	char input[20]={'0'};
	scanf("%s",input);
	
	void upencode(char *p);    //encode the input 
	void downencode(char *p);
	upencode(input);
	downencode(input+6);
	//printf("%s",input);
	
	int check=1;                        //check
	check=strcmp(input,"lupdkjgqemmb");
	
	if(strlen(input)==12 && check==0 )
	{
		printf("\nLog in successfully!\n");
		generate();
		
	}
	else 
	{
		printf("\nWrong Password,try IDA or OD?\n");
	}
	
	system("pause");
	return 0;
 } 
