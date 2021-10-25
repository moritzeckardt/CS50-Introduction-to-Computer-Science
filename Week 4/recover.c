#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
#include <stdbool.h>

// Task: https://cs50.harvard.edu/x/2021/psets/4/recover/

int main(int argc, char *argv[])
{
    // Properties
    typedef uint8_t BYTE;
    const int BLOCK_SIZE = 512;

    BYTE chunck[BLOCK_SIZE];
    size_t bytes_read;

    FILE *current_image;
    char current_image_name[100];
    int current_image_number = 0;

    bool first_jpg = false;
    bool found_jpg = false;

    // Check command line arguments
    if (argc != 2)
    {
        printf("Usage: ./recover image.\n");
        return 1;
    }

    // Open file
    FILE *source = fopen(argv[1], "r");
    if (source == NULL)
    {
        printf("Can not open file.");
        return 1;
    }

    // Read file
    while (true)
    {
        // Read chunck by chunck
        bytes_read = fread(chunck, sizeof(BYTE), BLOCK_SIZE, source);
        if (bytes_read == 0)
        {
            printf("The end of the file is reached or an error has occurred.\n");
            break;
        }

        // Check for jpg file
        if (chunck[0] == 0xff && chunck[1] == 0xd8 && chunck[2] == 0xff && (chunck[3] & 0xf0) == 0xe0)
        {
            // Handle found and first jpg
            found_jpg = true;

            if (!first_jpg)
            {
                first_jpg = true;
            }
            else
            {
                fclose(current_image);
            }

            // Create new jpg file
            sprintf(current_image_name, "%03i.jpg", current_image_number);
            current_image = fopen(current_image_name, "w");
            fwrite(chunck, sizeof(BYTE), bytes_read, current_image);
            current_image_number++;
        }
        else
        {
            // Write to current jpg file
            if (found_jpg)
            {
                fwrite(chunck, sizeof(BYTE), bytes_read, current_image);
            }
        }
    }

    // Close files
    fclose(source);
    fclose(current_image);
    return 0;
}