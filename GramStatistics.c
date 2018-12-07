#include<stdio.h>
#include<string.h>

void storeQuad(int quad[26][26][26][26])
{
	FILE *fptr=fopen("english_quadgrams.txt","r");
	char ch;
	while ( (ch = getc(fptr)) != EOF )
		{
			int ctr,i,j,k,l,num;
			ctr=i=j=l=k=num=0;
			while(ch!=' ')
		   {
			   switch(ctr)
			   {
			   	case 0: i= ch-'A';break;
			   	case 1: j= ch-'A';break;
			   	case 2: k= ch-'A';break;
			   	case 3: l= ch-'A';break;
			   }
			   ch = getc(fptr);
			   ctr++;
	       }
	       while((ch=getc(fptr))!='\n')
				num=num*10+(ch-'0');
			
	//	printf("store quad");		
			quad[i][j][k][l]=num;
			
		}
}

void storeTri(int tri[][26][26])
{
	FILE *fptr=fopen("english_trigrams.txt","r");
	char ch;
	while ( (ch = getc(fptr)) != EOF )
		{
			int ctr,i,j,k,num;
			ctr=i=j=k=num=0;
			while(ch!=' ')
		   {
			   switch(ctr)
			   {
			   	case 0: i= ch-'A';break;
			   	case 1: j= ch-'A';break;
			   	case 2: k= ch-'A';break;
			   }
			   ch = getc(fptr);
			   ctr++;
	       }
	       while((ch=getc(fptr))!='\n')
				num=num*10+(ch-'0');
			
	//	printf("store tri");	
			tri[i][j][k]=num;
			
		}
}

void storeBi(int bi[][26])
{
	FILE *fptr=fopen("english_bigrams.txt","r");
	char ch;
	while ( (ch = getc(fptr)) != EOF )
		{
			int ctr,i,j,num;
			ctr=i=j=num=0;
			while(ch!=' ')
		   {
			   switch(ctr)
			   {
			   	case 0: i= ch-'A';break;
			   	case 1: j= ch-'A';break;
				}
			   ch = getc(fptr);
			   ctr++;
	       }
	       while((ch=getc(fptr))!='\n')
				num=num*10+(ch-'0');
			
		//	printf("store bi");
			bi[i][j]=num;
			
		}
}


float calcFitness_Quad(char str[],int quad[][26][26][26])
{
	int i,j,k,ctr;
	float quadFitness=0;
	char quadstr[5];
	i=0;
    j=3;
  	//printf("QUAD\n");
    while(j!=strlen(str))
    {
	int x,qi,qj,qk,ql;
	x=ctr=0;
	for(k=i;k<=j;k++)
	 {
		quadstr[x]=str[k];
		
		switch(ctr)
		{
			case 0: qi= str[k]-'A';break;
			case 1: qj= str[k]-'A';break;
			case 2: qk= str[k]-'A';break;
			case 3: ql= str[k]-'A';break;
		}
		x++;ctr++;	   
	 }

	quadstr[x]='\0';
	//printf("%s %d\n",quadstr,quad[qi][qj][qk][ql]);
	
	if(qi>=0&&qj>=0&&qk>=0&&ql>=0)
		quadFitness+=quad[qi][qj][qk][ql]/1000.0;
	//printf("\n%s:%f",quadstr,quadFitness);
	i++;j++;
	}
	return quadFitness;
}

float calcFitness_Tri(char str[],int tri[][26][26])
{
 	int i,j,k,ctr;
 	float triFitness=0;
 	char tristr[5]; 
 	
	i=0;
    j=2;
    //printf("TRI");

    while(j!=strlen(str))
    {
	int x,qi,qj,qk;
	x=ctr=0;
	for(k=i;k<=j;k++)
	 {
		tristr[x]=str[k];
		
		switch(ctr)
		{
			case 0: qi= str[k]-'A';break;
			case 1: qj= str[k]-'A';break;
			case 2: qk= str[k]-'A';break;
		}
		x++;ctr++;	   
	 }

	tristr[x]='\0';
	//printf("%s %d\n",tristr,tri[qi][qj][qk]);
	
	if(qi>=0&&qj>=0&&qk>=0)
		triFitness+=tri[qi][qj][qk]/1000.0;
	i++;j++;
	}
	return triFitness;
}

float calcFitness_Bi(char str[],int bi[][26])
{
	int i,j,k,ctr;
	float biFitness=0;
	char bistr[5];
    i=0;
    j=1;
	//printf("BI");
    while(j!=strlen(str))
    {
	int x,qi,qj;
	x=ctr=0;
	for(k=i;k<=j;k++)
	 {
		//printf("%c",str[k]);
		bistr[x]=str[k];
		
		switch(ctr)
		{
			case 0: qi= str[k]-'A';break;
			case 1: qj= str[k]-'A';break;
		}
		x++;ctr++;	   
	 }

	bistr[x]='\0';
	//printf("%s %d\n",bistr,bi[qi][qj]);
	
	if(qi>=0&&qj>=0)
		biFitness+=bi[qi][qj]/1000.0;
	
	i++;j++;
	}
	return biFitness;
}

float calcFitness(char str[],int quad[26][26][26][26],int tri[26][26][26],int bi[26][26])
{
	float quadFitness,triFitness,biFitness,fitness;
	quadFitness=triFitness=biFitness=fitness=0.0f;
	
	quadFitness=calcFitness_Quad(str,quad);
	triFitness=calcFitness_Tri(str,tri);
	biFitness=calcFitness_Bi(str,bi);
	
	//printf("QuadFit = %f\nTriFit = %f\nBiFit = %f",quadFitness,triFitness,biFitness);
	
	fitness=(0.6*quadFitness)+(0.3*triFitness)+(0.1*biFitness);
    return fitness;
}	
			
int main()
{
	int quad[26][26][26][26],bi[26][26],tri[26][26][26],i,j;
	char str[1000];//="otooftn eo aavhm eoreuslnnaa rwo a ino ttulim keneiOaeletruir itas hemenleeufa hs d nfas ciakeeidumnshpoea i   s nhoe  etw watcilte rpthlrCid a aehht cotmyhhomme aef no tw ttahy iocnmy  oss  tltuim tgal tt dusoyc a ubeopeci u Sotcexdl tathaemsumswaaeciawrebserwrbhotuircaehedXmi nfhgo rtlnieuo rk n i dmna a tsSm rwoetotutnvesnf r    nlacnus toan t tlgttuy r otttwomit t yahy otce tahrb kottsylusniiioemysntulcay X";
	char msg[1000];
	float fitness=0.0;
	/*j=0;
	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]>=97&&str[i]<=122)
			msg[j++]=str[i]-32;
		else
			msg[j++]=str[i];	   
	}*/
	//printf("Enter a string : ");
    //scanf("%s",&str);
	
	//FILE *fptr1=fopen("GramInput.txt","r");
	//FILE *fptr1=fopen("encrypted text.txt","r");
	FILE *fptr1=fopen("plain text.txt","r");
	fgets(str,1000,fptr1);
	j=0;
	for(i=0;i<=strlen(str);i++)
	{
		if(str[i]>=97&&str[i]<=122)
			msg[j++]=str[i]-32;
		else
			msg[j++]=str[i];	   
	}
	printf("%s",msg);
		
	storeQuad(quad);
	//printf("1");
	storeTri(tri);
	//printf("2");
	storeBi(bi);
	//printf("3");
	fitness=calcFitness(msg,quad,tri,bi);
	
	printf("\n\nFitness = %f",fitness);
	return 0;
}
