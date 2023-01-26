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
        printf("File does not exist\n");
        exit(0);
    }
    fseek(fp, 0, SEEK_END);
    size = ftell(fp) * 1000;
    if (size > 2500000){
        printf("File size is greater than 25 kilobytes, not valid\n");
        exit(0);
    }
    else{
        printf("%ld kilobytes\n", size);
    }
    //counts the number of times that a given byte value occurs in the file 
    int count = 0;
    int byte = atoi(argv[2]);
    char c;
    while (fread(&c, 1, 1, fp) == 1)
    {
        if (c == byte)
        {
            count++;
        }
    }
    printf("The byte value %u occurs %d times in the file\n", byte, count);

    fclose(fp);
    return 0;
}