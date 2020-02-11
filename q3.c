#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include <stdlib.h>
int main(int argc,char* argv[])
{
	char word[10];
	bool check;
    char strArr[50];
    char ch;
	int count=0,size;
    FILE* fp;
    int i=0;
    fp = (fopen("q3_a.txt", "r+"));

    if (!fopen("q3_a.txt", "r+"))
        printf("Error!! File Not Opened.");

    else {
		check = false;
        ch = fgetc(fp);
        while (ch != EOF)
        {
            
			while(ch != ' ')
			{
	   			word[i++] = ch;
            	if (ch=='a' || ch=='A' || ch=='e' || 
            	ch=='E' || ch=='i' || ch=='I' || 
            	ch=='o' || ch=='O' || ch=='u' || 
            	ch=='U')
                check = true;
				ch = fgetc(fp);
			}
			word[i]=' ';
			//int size = strlen(word);
			
			int cSize=0;
			while(word[cSize]!=' ')
			size++;
			
			size=size+1;
			char temp[10];
			if(check!=true)
			{
				int j = 0,len,k,l;
 				char RevStr[10];
  				for (k = size - 1; k >= 0; k--)
  				{
	  				RevStr[j++] = word[k];
  				}
  				RevStr[j] = '\0';
				check = false;
				for(l=0;l<size;l++)
				{
					strArr[count++]=RevStr[l];
				}
			}
			else
			{
				int l;
				for(l=0;l<size;l++)
				{
					strArr[count++]=word[l];
				}
			}
			memset(word,0,strlen(word));
			i=0;
			ch = fgetc(fp);
        }
        fputs(strArr,fp);
        printf("String is :%s", strArr);

        fclose(fp);
    }

    return 0;

}
