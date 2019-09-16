#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

typedef unsigned char *byte_pointer;
void show_bytes(byte_pointer start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++)
        printf(" %.2x", start[i]);  //line:data:show_bytes_printf
    printf("\n");
}

typedef struct{
    short code;
    long start;
    char raw[3];
    double data;
}  OldSenesorData;

typedef struct{
    short code;
    short start;
    char raw[5];
    short sense;
    short ext;
    double data;
}  NewSenesorData;

int main(){
    OldSenesorData *oldData = (OldSenesorData*)malloc(sizeof(OldSenesorData));
    bzero((void*)oldData, sizeof(oldData));

    oldData->code = 0x104f;
    oldData->start = 0x80501ab8;
    oldData->raw[0] = 0xe1;
    oldData->raw[1] = 0xe2;
    oldData->raw[2] = 0x8f;
    oldData->raw[-5] = 0xff;
    oldData->data = 1.5;

    NewSenesorData *newData = (NewSenesorData*)oldData;

    show_bytes((byte_pointer)newData, sizeof(NewSenesorData));

    show_bytes((byte_pointer)&(newData->start), sizeof(short));
    show_bytes((byte_pointer)&(newData->raw[0]), sizeof(char));
    show_bytes((byte_pointer)&(newData->raw[2]), sizeof(char));
    show_bytes((byte_pointer)&(newData->raw[4]), sizeof(char));
    show_bytes((byte_pointer)&(newData->sense), sizeof(short));

}