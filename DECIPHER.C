#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define keySize 8

void decrypt(char encryptedText[],int key[],int textSize)
{
	int r=(textSize/keySize);
	int c=keySize;
	
	char col,ch;
	int i,j,k;

	char decrypted[1000];
	
	/*char **matrix=(char**)malloc(r*sizeof(char));
	for(i=0;i<r;i++)
	    matrix[i]=(char*)malloc(c*sizeof(char));
	*/
	char matrix[r][c];
	for(i=0;i<keySize;i++)
	{
	  for(j=0;j<r;j++)
	  {
	    matrix[j][key[i]-1]=encryptedText[k++];
	  }
    }
	
	for(i=0;i<r;i++)	//printing matrix
	{
	    for(j=0;j<c;j++)
	    {
		printf("%c",matrix[i][j]);
	    }
	    printf("\n");
	}

	k=0;
	for(i=0;i<r;i++)	//forming decrypted string
	{
		for(j=0;j<c;j++)
		    decrypted[k++]=matrix[i][j];
	}
	decrypted[k]='\0';
	printf("\nDecrypted Text : %s ",decrypted);
	
	for(i=0;i<r;i++)
	    free(matrix[i]);
    free(matrix);	
}


int main()
{
//char ch[]="AEXVBXHITSMSISX";// 5 4 2 1 3
//char ch[]="IIEAHSLGHYLOOODAODAYTD";// 2 4 3 5 1 6 7 10 9 11 8
//char ch[]="  ORIOHIMVATEN ILITAI UAMAFTZN";// 4 2 3 1 5
//char ch[]="a oyoigddsoat   yadx";//4 2 3 1 5
char ch[]="noltnft srhntokcile auyohct m eakmhsnssneworiugnattdXCioahahrecicy sSm eem oah  et  blti veu  wt o,reuatyei y g htooeihr.oeixfnt  atiaat  nua e s rru ts  lsh Xudncaoutlptu hr t  d aatteen ht -mtwo’eet binlnirc lXoetfege yado a oua niarnoaSshwwoo tkelsOwietm arlsh am oel aua  mftoeitney m  pmarsiteo oyentilaeuliaueto.ms f e b nemouwmncadln twso oiruscynrsifrl hmitttpahrtn tutoh v te’ msktadhwst.muyoacinte b.a itcytcc  edX";//6 1 7 5 2 4 3 8
int i,textSize;
int key[]={6,1,7,5,2,4,3,8};
textSize=strlen(ch);
//printf("%d\n",textSize);

decrypt(ch,key,textSize);

return 0;
}
