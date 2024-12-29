## Tiniest crc-32 (?)
Compile:
1. `gcc -W -Wall -std=c99 crc.c main.c -s -o crc32`
1. `sudo mv crc32 /usr/local/bin`
1. `crc32 --` ---> shows `0xcbf43926`, which is the default string '123456789'

## Making use of simple _crc32_
This tiny `crc32` (CRC-32 calculator, polynomial 0x4c11db7) has _main.c_ with a few options:
1. No arguments: uses stdin
1. Argument starting with `--`
   + Calculates CRC-32 of the several words entered in the arguments
1. Else:
   + It shows the files in the arguments.

## Reference
1. Other kinds of CRC-32 listed:
   * [(here)](https://crccalc.com/?crc=123456789&method=CRC-32/ISO-HDLC&datatype=ascii&outtype=hex) CRC calc.com, example for string `123456789`
