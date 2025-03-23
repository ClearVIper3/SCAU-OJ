#include <stdio.h>
#include <stdint.h>

const int SIZE = 512;
int main(int argc, char *argv[])
{
     // Accept a single command-line argument
    if(argc<=1)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }
    // Open the memory card
    FILE *input=fopen(argv[1], "r");
    FILE *pic=NULL;
    // While there's still data left to read from the memory card
    uint8_t buffer[SIZE];
    int i=0;
    while (fread(&buffer, 1 , 512 , input) == 512)
    {
        // Create JPEGs from the data
        if(buffer[0]==0xff&&buffer[1]==0xd8&&buffer[2]==0xff)
        {
            if(pic!=NULL)
            {
                fclose(pic);
            }
            char filename[8];
            sprintf(filename,"%03d.jpg",i++);
            pic=fopen(filename,"w");
        }

        if(pic!=NULL)
        {
            fwrite(&buffer, 1 , 512 ,pic);
        }
    }

    fclose(pic);
    fclose(input);
}
