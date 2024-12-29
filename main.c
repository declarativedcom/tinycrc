/* crc-32 main.c
	crc.c generated using:
		pycrc --model crc-32 --algorithm table-driven --generate c -o crc.c
   This is inspired at:
	https://pycrc.org/tutorial.html
*/

#include <stdio.h>
#include <string.h>
#include "crc.h"

typedef unsigned char uint8;
typedef unsigned int uint32;

int calc_crc32(FILE* fin, unsigned* res)
{
 crc_t crc = crc_init();
 size_t i = 0;
 uint8 u;
 while (1) {
     if (fscanf(fin, "%c", &u) == -1) break;
     crc = crc_update(crc, &u, 1);
     i++;
 }
 crc = crc_finalize(crc);
 *res = crc;
 return 0;
}

uint32 byte_crc32(const char* str)
{
 crc_t crc = crc_init();
 if (str == NULL) {
     return 0;
 }
 crc = crc_update(crc, str, strlen(str));
 return crc_finalize(crc);
}

int main(int argc, char* argv[])
{
 int i, istart = 1, code = 0;
 uint32 u_crc = 0;
 const char* str;
 FILE* fin;
 argc--;
 if (argc <= 0) {
     code = calc_crc32(stdin, &u_crc);
     printf("0x%08x\n", u_crc);
     return code;
 }
 if (strcmp(argv[istart], "--") == 0) {
     /* Assume it's a string next */
     istart++;
     for (i=istart; i<=argc + (istart==argc+1); i++) {
	 str = argv[i] ? argv[i] : "123456789";
	 u_crc = byte_crc32(str);
	 printf("0x%08x\n", u_crc);
     }
     return 0;
 }
 for (i=istart; i<=argc; i++) {
     const char* fname = argv[i];
     u_crc = 0;
     fin = fopen(fname, "rb");
     if (fin == NULL) {
	 printf("%08x %s -- Failed to read\n", u_crc, fname);
     }
     else {
	 calc_crc32(fin, &u_crc);
	 fclose(fin);
	 printf("%08x %s\n", u_crc, fname);
     }
 }
 return 0;
}
