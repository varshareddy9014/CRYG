#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
 int i,j,k,c,code[50][50];
    char str[50];
    printf("Enter string:\n");
    scanf("%s",str);
    int l=strlen(str);
 printf("Enter key:\n");
 scanf("%d",&k);
 for(i=0;i<k;i++)
 {
  for(j=0;j<l;j++)
  {
   code[i][j]=0;
  }}
c=0;
j=0;
while(j<l)
{
if(c%2==0)
{
 for(i=0;i<k;i++)
 {
  code[i][j]=(int)str[j]; 
  j++;
 }}
else
{
 for(i=k-2;i>0;i--)
 {
  code[i][j]=(int)str[j];
 j++;
 }  } 
c++;
}
for(i=0;i<k;i++)
{
 for(j=0;j<l;j++)
 {
  if(code[i][j]!=0)
  printf("%c",code[i][j]);
 } }
}

