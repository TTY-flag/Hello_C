#include<stdio.h>
#include<stdlib.h>
void Bubble(int *a)
{
	int i,j,temp;
	int n=6;
for(j= 1; j<=n-1; j++)	
    for(i = 0;i<= n-1-j; i++)
            if ( a[i] > a[i+1])
		{
			temp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = temp;
		}

		
}
void Choose(int *a)
{
	int i,j,k,temp;
	int n=6;
	for(i = 0; i<n- 1; i++)
	{
	k = i;  
	for ( j = i+ 1; j<n; j++ )
		if (a[j] > a[k])   k = j;
	if (k != i) 
	{     
		temp = a[i];
		a[i] = a[k];
         a[k] = temp;
	}
}
}
int OnceQc(int a[],int i,int j)
{
        int p=i,q=j;
        int tem;
        while(p<q)
        {
                while(p<q&&a[p]<=a[q])
                {
                        p++;
                }
                tem=a[p];
                a[p]=a[q];
                a[q]=tem;
                while(p<q&&a[q]>=a[p])
                        q--;
                tem=a[p];
                a[p]=a[q];
                a[q]=tem;

        }
        return q;
}
void QcSort(int a[],int n,int i,int j)
{
        int p,k;
        if(i<j)
        {
                p=OnceQc(a,i,j);
                for(k=0;k<n;k++)
                        QcSort(a,n,i,p-1);
                        QcSort(a,n,p+1,j);
        }
}
int main()
{
		int a1[18]={97,120,110,106,102,101,85,66,87,74,78,72,57,55,56,54,49,53};
		int sort[6];
		char input[32];
		int i,j;
		for(i=0;i<3;i++)
		{
			switch(i)
			{
				case 0:
					for(j=0;j<6;j++)
						sort[j]=a1[3*j+i];
					Bubble(sort);
					for(j=0;j<6;j++)
						a1[3*j+i]=sort[j];
					break;
				case 1:
					for(j=0;j<6;j++)
						sort[j]=a1[3*j+i];
					Choose(sort);
					for(j=0;j<6;j++)
						a1[3*j+i]=sort[j];
					break;
				case 2:
					for(j=0;j<6;j++)
						sort[j]=a1[3*j+i];
					QcSort(sort,6,0,5);
					for(j=0;j<6;j++)
						a1[3*j+i]=sort[j];	
					break;
				default:
					exit(0);
			}
		}
        printf("Can you sort the flags?\n");
        printf("Now give me your answer.\n");
        scanf("%s",input);
        if(input[0]=='J'&&input[1]=='N'&&input[2]=='C'&&input[3]=='T'&&input[4]=='F'&&input[5]=='{'&&input[24]=='}')
        {
        	for(i=0;i<18;i++)
        		if(input[i+6]!=a1[i])
        		{
        			printf("Oh!Can you really sort?\n");
        			exit(0);
				}
			printf("Wow!You can really sort!\n");
		}
        else
        	printf("Oh!Can you really sort?\n");
        	return 0;
}
		

