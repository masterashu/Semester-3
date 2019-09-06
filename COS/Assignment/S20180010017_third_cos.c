#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void get_decimal(const char *binary) {
    int num = 0, is_fraction = 0;
    float fraction = 0, mul = 1;
    for (int i = 0; i < strlen(binary); i++) {
        if(binary[i] == '.'){
            is_fraction = 1;
            continue;
        }
        if (is_fraction == 0){
            num = (num * 2) + ((binary[i] == '1') ? 1 : 0);
        }
        else {
            mul = mul / 2;
            fraction += ((binary[i] == '1')) ? mul : 0;
        }
    }
    if (fraction == 0) {
        printf("%d\n", num);
    }
    else {
        printf("%f\n", fraction + num);
    }
}

int main(int argc, char const *argv[])
{
    if (argc > 1){
        for (int i = 1; i < argc; i++){
            get_decimal(argv[i]);
        }
    }
    else {
        printf("Enter Binary: ");
        char num[100];
        scanf("%s", num);
        get_decimal(num);
    }
    return 0;
}


