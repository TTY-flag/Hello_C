#include<stdio.h>
#include<string.h>
int main(){
	int t,len,i,j,k;
	char a[]="BxDF>VbVa^iiaZgZkZ`zh0\"k";
	len = strlen(a);
	for(i=len-1;i>=6;i--){
		for(j=i;j>=i-2;j--){
			for(k=j;k>=j-2;k--){
				a[k]=a[k]+a[k-2]+1;
				a[k-2]=a[k]-a[k-2];
				a[k]=a[k]-a[k-2]+1;  
			}
			a[j]=a[j]+a[j-4]-1;
			a[j-4]=a[j]-a[j-4];
			a[j]=a[j]-a[j-4]-1;
		}
		a[i]=a[i]+a[i-6]+2;
		a[i-6]=a[i]-a[i-6];
		a[i]=a[i]-a[i-6]+1;
	}
	printf("%s",a);
}

