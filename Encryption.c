#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define keySize 8

void encrypt(int key[])
{
	FILE *fptr1=fopen("plain text.txt","r");
	FILE *fptr2=fopen("encrypted text.txt","w");
	char str[1000],encrypted[1000];
	int k,j,i,exit;
	
	fgets(str,1000,fptr1);
	
	exit=(strlen(str)/keySize+1)*keySize;
	
	i=0;
	for(k=0;k<keySize;k++)
	{
		for(j=key[k]-1;j<exit;j+=keySize)
		{ 
			if(j<strlen(str))
				encrypted[i++]=str[j];
			else
				encrypted[i++]='X';
		}
	}
	encrypted[i]='\0';
	printf("%s",encrypted);
	fputs(encrypted,fptr2);
}

int main()
{
	int key[]={5,1,8,2,6,4,3,7};
	encrypt(key);
	return 0;
}
