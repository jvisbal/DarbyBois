//Milestone 1
//By Kevin Olvera and Jorge Visbal

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    long int size;
    fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        printf("Error: File does not exist\n");
        exit(0);
    }

    //find size of file see if
    fseek(fp, 0, SEEK_END);
    size = ftell(fp) * 1000; //ftell gives you size in bytes we want to compare to kb
    if (size > 25000){
        printf("File size is greater than 25 kb (file size was %ld))\n", size);
        exit(0);
    }
    //fclose(fp);

    //not sure why I needed to close the file 
    //and reopen it but was getting errors by not doing this
    //fp = fopen(argv[1], "r");
    fseek(fp, 0, SEEK_SET);

    //counts the number of times that a given byte value occurs in the file 
    int count = 0;
    int byte = (int)strtol(argv[2], NULL, 16);
    char c;
    while (fread(&c, sizeof(char), 1, fp))
    {
        if ((int)c == byte)
        {
            count++;
        }
    }
    //printf("The byte value 0x%x occurs %d times in the file\n", byte, count);
    printf("%d\n", count);

    fclose(fp);
    return 0;
}