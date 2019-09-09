#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char* int_to_binary(int num){
    char *binary = (char*)malloc(sizeof(char)*41);
    for (int i = 0; i < 40; i++){
        binary[i] = 0;
    }
    char tmp[41] = {0};
    int i = 0;
    while (num > 0){
        if (num % 2 == 1){
            tmp[i++] = '1';
        }
        else {
            tmp[i++] = '0';
        }
        num /= 2;
    }
    tmp[i++] = '0';
    // printf("! %s \n", tmp);
    int j;
    for (j = 0; j < i; j++){
        binary[j] = tmp[i-j-1];
    }
    binary[j] = 0;
    return binary;
}

char* exp_to_binary(double num){
    char *whole = int_to_binary((int) num);
    char *fraction = (char*)malloc(sizeof(char)*13);
    int limit = 10;
    double fc = num - (double)(int) num;    
    fraction[0] = '.';
    int i = 1;
    while (fc > 0 && limit > 0){
        fc *= 2;
        if (fc >= 1){
            fraction[i++] = '1';
            fc--;
        }
        else {
            fraction[i++] = '0';
        }
        limit--;
    }
    char *number = (char*)malloc(sizeof(char)*(strlen(whole) + strlen(fraction) + 2));
    strcat(number, whole);
    strcat(number, fraction);
    return number;
}

char* float_to_binary(float num){
    char *whole = int_to_binary((int) num);
    char *fraction = (char*)malloc(sizeof(char)*13);
    int limit = 10;
    float fc = num - (float)(int) num;    
    fraction[0] = '.';
    int i = 1;
    while (fc > 0 && limit > 0){
        fc *= 2;
        if (fc >= 1){
            fraction[i++] = '1';
            fc--;
        }
        else {
            fraction[i++] = '0';
        }
        limit--;
    }
    char *number = (char*)malloc(sizeof(char)*(strlen(whole) + strlen(fraction) + 2));
    strcat(number, whole);
    strcat(number, fraction);
    return number;
}

int main(int argc, char const *argv[])
{
    if (argc > 2) {
        if (strcmp(argv[1], "-i") == 0){
            for (int i = 1; i < argc - 1; i++){
                printf("%s\n", int_to_binary(atoi(argv[i+1])));
            }
        }
        else if (strcmp(argv[1], "-f") == 0){
            for (int i = 1; i < argc - 1; i++){
                printf("%s\n", float_to_binary(atof(argv[i+1])));
            }
        }
        else if (strcmp(argv[1], "-e") == 0){
            double num;
            for (int i = 1; i < argc - 1; i++){
                sscanf(argv[i+1], "%lf", &num);
                printf("%s\n", exp_to_binary(num));
            }
        }
    }
    else {
        printf("No Command Line inputs found!\n");
        printf("Help:\n");
        printf("Use \'num2bin -i 223\' to convert int to binary\n");
        printf("Use \'num2bin -f 223\' to convert float to binary\n");
        printf("Use \'num2bin -e 223\' to convert exp notation to binary\n");
        printf("You can also pass multiple arguments:\n");
        printf("Example: \'num2bin -i 342 545 121\'\n");


    }
    
    return 0;
}

