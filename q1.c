#include<stdio.h>
#include<string.h>
int main(int argc,char* argv[])
{
    char ch;
    FILE* fp;
    int count = 0;
    fp = (fopen(argv[1], "r+"));

    if (!fopen(argv[1], "r+"))
        printf("Error!! File Not Opened.");

    else {

        ch = fgetc(fp);
        while (ch != EOF)
        {
            ch = fgetc(fp);
            if (ch >= 48 && ch <= 57)
                count++;
        }

        printf("count of digit : %d", count);

        fclose(fp);
    }

    return 0;

}
