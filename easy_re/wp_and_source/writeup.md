# writeup
本题目实际上是把一个整型数组分为三部分，第一部分进行冒泡排序，第二部分进行选择排序，第三部分进行快速排序，脚本代码实际上就是源代码修改，如下：
```c
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
		for(i=0;i<18;i++)
			printf("%c",a1[i]);
}

```
最后题目对flag的格式有要求，为JNCTF{...}的格式，所以flag为JNCTF{6x59f8JNHUBWa7ej1n}