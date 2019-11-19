#include <stdio.h>

long absdiff(long x, long y){
    long result;
    if (x > y){
        result = x-y;
    }
    else{
        result = y-x;
    }
    return result;
}

// int main(){
//     long a = 10, b = 13;
//     printf("%ld\n", absdiff(a,b));
// }