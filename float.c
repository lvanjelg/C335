#include <stdlib.h>
#include <stdio.h>

typedef union{
    float f;
    int b;
} convert;

int main(int argc, char** argv){
    if(argv[1][1] == 'f'){
        float input = strtof(argv[2],NULL);
        convert c;
        c.f = input;
        printf("Binary: ");
        for(int i = 31; i >= 0; i--){
            printf("%d", (c.b >> i) & 1);
        }
        printf("\n");
        printf("Sign: %d\n", (c.b >> 30) & 1);
        printf("Exponent: %d\n",((c.b >> 23) & 0xFF) - 127);
        printf("Mantissa: %g\n", 1 + (c.b & 0x7FFFFF) / (float)(1 << 23));
        printf("Value %g\n", input);
    }else if(argv[1][1] == 'b'){
        unsigned int input = 0;
        for(int i = 0; i < 32; i++){
            input = input << 1;
            input = input | argv[2][i] - '0';
        }
        convert c;
        c.b = input;
        printf("Binary: ");
        for(int i = 31; i >= 0; i--){
            printf("%d", (c.b >> i) & 1);
        }
        printf("\n");
        printf("Sign: %d\n", (c.b >> 30) & 1);
        printf("Exponent: %d\n",((c.b >> 23) & 0xFF) - 127);
        printf("Mantissa: %g\n", 1 + (c.b & 0x7FFFFF) / (float)(1 << 23));
        printf("Value %g\n", c.f);
    }
    return 0;
}
