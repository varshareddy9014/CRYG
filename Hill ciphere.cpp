#include<stdio.h>
#include<string.h>
void matmul(int a[2][2],int b[2][1]){
	int mul[2][1];
	for(int i=0;i<2;i++){
		for(int j=0;j<1;j++){
			mul[i][j]=0;
		for(int k=0;k<2;k++){
			mul[i][j]+=a[i][k]*b[k][j];
		}
		}
	}
	
	for(int i=0;i<2;i++){
		for(int j=0;j<1;j++){
			char c=char((mul[i][j]%26)+96);
			printf("%c",c);
		}		
	}
}
int main()
{
	int k[2][2],a[2][1];
	printf("Enter the key : \n");
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			scanf("%d",&k[i][j]);
		}
	}
	char s[1000];
	int l=0;
	printf("Enter the plaintext : ");
	scanf("%s",s);
	int x=strlen(s);
	if(x%2==1){
		s[x]=='x';
	}
	
	for(int i=0;i<strlen(s);i=i+2){
		if(s[i]!='\0'){
		int x=0;
		a[x++][0]=int(s[i])-96;
		a[x++][0]=int(s[i+1])-96;
		matmul(k,a);}
	}
}


