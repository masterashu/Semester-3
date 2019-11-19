#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct {
    short code;
    long start;
    char raw[3];
    double data;
} OldSensorData;

typedef struct {
    short code;
    short start;
    char raw[5];
    short sense;
    short ext;
    double data;
} NewSensorData;

void foo(OldSensorData *oldData) {
    NewSensorData *newData;
    /* this zeros out all the space allocated for oldData */ bzero((void *)oldData, sizeof(oldData));
    oldData->code = 0x104f;
    oldData->start = 0x80501ab8;
    oldData->raw[0] = 0xe1;
    oldData->raw[1] = 0xe2;
    oldData->raw[2] = 0x8f;
    oldData->raw[-5] = 0xff;
    oldData->data = 1.5;
    newData = (NewSensorData *)oldData;

    printf("newData->start = %x\n", newData->start);
    printf("newData->raw[0] = %x\n", newData->raw[0]);
    printf("newData->raw[2] = %x\n", newData->raw[2]);
    printf("newData->raw[4] = %x\n", newData->raw[4]);
    printf("newData->sense = %x\n", newData->sense);
}
int main() {
    OldSensorData a;
    foo(&a);
}