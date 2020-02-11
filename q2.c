#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>
int count=0;
#define MAXCHAR 1000
void addStudents(int n)
{
	 FILE* fp;
    fp = fopen("studentRecord.txt", "w+");

    if (!fopen("studentRecord.txt", "w+"))
        printf("Error!! File Not Opened.");

    else {
		int i;
		char stdArray[50];
		printf("Enter RollNumber Name Email with comma between them: \n"); 
			
		for(i=0;i<n;i++)
		{
			printf("For Student %d",count);	
			printf(" : ");		
			
			scanf("%s", stdArray);
			
			fputs(stdArray,fp);
			fputs("\n",fp);
			count++;
		}
	}
	fclose(fp);
}
void deleteStudent(char x[])
{
	int i;
	FILE* fp;
	bool check;
	fp = fopen("studentRecord.txt", "r+");
	char ch;
    if (!fopen("studentRecord.txt", "r+"))
        printf("Error!! File Not Opened.");

    else {
		int size = strlen(x);
		printf("%s",x);
		char checkArray[50];
		while(fgets(checkArray,MAXCHAR,fp)!=NULL)
		{	
			for(i=0;i<=size-1;i++)
			{
				if(checkArray[i]==x[i])
				{
					check =true;
				}
				else{
				
					check= false;
					break;
				}
			}
			if(check ==true)
			{
				printf("Roll number Found and deleted \n");
				int strsize = strlen(checkArray);
				fseek( fp, strsize, SEEK_SET );
				fputs(" ",fp);

			}
		}	
	}
	fclose(fp);
}
void readRecord(){
	FILE* fp;
    fp = fopen("studentRecord.txt", "r+");
	char ch;
    if (!fopen("studentRecord.txt", "r+"))
        printf("Error!! File Not Opened.");

    else {
		ch = fgetc(fp);
        while (ch != EOF)
        {
            printf("%c", ch);
			ch = fgetc(fp);
        }

        fclose(fp);
	}
}
int main()
{
    char ch;
   
	int n,check,choose;
	char x[10];
	printf("Welcome to Student Record : \n");
	printf("1)- Add Students: \n");
	printf("2)- Delete Students: \n");
	printf("3)- Read Record: \n");
	printf("Enter 1,2 or 3 to do the above operations: \n");
	scanf("%d",&choose);

	switch(choose)
	{
		case 1 : 
			printf("Enter How many students you want to add: ");
			scanf("%d",&n);		
			addStudents(n);
			break;
		case 2 : 
			printf("Enter Roll Number of student you want to delete(i.e, 164108): ");
			scanf("%s",x);
			deleteStudent(x);
			break;
		case 3 : 
			printf("Student RECORD: ");
			readRecord();
			break;
		default : printf("Error! Wrong input..Pleasw try again later. \n");
			
	}

    return 0;

}
