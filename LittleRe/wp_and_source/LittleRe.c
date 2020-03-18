#include<stdio.h>
#include<string.h>
int main(){
	char a[100];
	char b[]="BxDF>VbVa^iiaZgZkZ`zh0\"k";
	int i,j,k,len,num=0;
	while(scanf("%s",a)!=EOF){
    	len = strlen(a);
		for(i=0;i<=len-7;i++){
			a[i]=a[i]+a[i+6]-2;
			a[i+6]=a[i]-a[i+6];
			a[i]=a[i]-a[i+6]-1;
			for(j=i;j<=i+2;j++){
				a[j]=a[j]+a[j+4]+1;
				a[j+4]=a[j]-a[j+4];
				a[j]=a[j]-a[j+4]+1;
				for(k=j;k<=j+2;k++){
					a[k]=a[k]+a[k+2]-1;
					a[k+2]=a[k]-a[k+2];
					a[k]=a[k]-a[k+2]-1; 
				}
			}
		}
	if(strcmp(a,b)==0){printf("right!\n");break;}
	else printf("Wrong!Maybe you can try again?\n");
	}
	return 0;
}

