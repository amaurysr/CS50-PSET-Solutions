#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Checks if the user enter at least a file name
    if(argv[1] == NULL)
    {
        printf("Please enter a file\n");
        return 1;
    }
    // This will open that argv[1] that the user enters
    FILE *file = fopen(argv[1], "r");
    // Checks if the file exists and works for our program
    if(file == NULL)
    {
        printf("Please enter a correct file");
        return 2;
    }
    // This creates our img variable and allocates the memory with size of file
    FILE *img = malloc(sizeof(FILE));
    // This is our block size which is 512 bytes as it loops to append to our jpeg file
    int BLOCK_SIZE = 512;
    // This is our buffer which will indicate the hexadecimal values especially the
    // first four which will define a jpeg file for us
    BYTE buffer[BLOCK_SIZE];
    // This is the count which will be useful for our while loop because it will
    // indicate if it's our first jpeg or not
    int count = 0;
    // This is the string that will define our filename for fwrite
    // As it will change throughout our while loop
    char *filename = malloc(sizeof(char));
    while(fread(buffer, sizeof(BYTE), BLOCK_SIZE, file) == BLOCK_SIZE)
    {
        // Our four parameters here for the if statement will define whether or not if this
        // buffer array is a jpeg or notc
        // The (buffer[3] & 0xf0) == 0xe0 is utilizing bitwise arithmetic since that buffer has multiple hex values
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if(count == 0)
            {
                sprintf(filename,"%03i.jpg", count);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                count++;
                fclose(img);
            }
            else
            {
                sprintf(filename,"%03i.jpg",count);
                img = fopen(filename, "w");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                count++;
                fclose(img);
            }
        }
        else
        {
            if(count > 0)
            {
                img = fopen(filename, "a");
                fwrite(buffer, sizeof(BYTE), BLOCK_SIZE, img);
                fclose(img);
            }
        }
    }
    free(filename);
    fclose(file);
}