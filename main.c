#include <stdio.h>
#include <string.h>
#include "crc.h"

int main(void)
{
    static char str[] = "123456789";
    crc_t crc;
    int i;

    crc = crc_init();
    for (i = 0; i < (int)strlen(str); i++) {
        crc = crc_update(crc, (unsigned char *)&str[i], 1);
    }
    crc = crc_finalize(crc);

    printf("0x%lx\n", (unsigned long)crc);
    return 0;
}
