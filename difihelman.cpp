#include<stdio.h>
#include<math.h>
int main(){
	int p,g,a,b,x,y,ka,kb;
	printf("Enter public number1 : \n");
	scanf("%d",&p);
	printf("Enter public number2 : \n");
	scanf("%d",&g);
	printf("Enter private number1 : \n");
	scanf("%d",&a);
	printf("Enter private number2 : \n");
	scanf("%d",&b);
	x=fmod(pow(g,a),p);
	y=fmod(pow(g,b),p);
	ka=fmod(pow(y,a),p);
	kb=fmod(pow(x,b),p);
	printf("secret key1 : %d\nsecret key2 : %d",ka,kb);	
}

