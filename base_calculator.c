#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Defines custom stack structure
typedef struct Stack{
    int size;
    int top;
    unsigned int nums[];
} stack;
// Basic operations for calculator functionality
unsigned int add(unsigned int a, unsigned int b){
    return a + b;
}
unsigned int sub(unsigned int a, unsigned int b){
    return a - b;
}
unsigned int mult(unsigned int a, unsigned int b){
    return a * b;
}
unsigned int divide(unsigned int a, unsigned int b){
    return a / b;
}
// Push and pop functions for stack
unsigned int pop(stack* s){
    unsigned int temp = s->nums[s->top];
    s->size = s->size - 1;
    s->top = s->top - 1;
    return temp;
}
void push(stack* s, unsigned int a){
    s->size = s->size + 1;
    s->top = s->top + 1;
    s->nums[s->top] = a;
}
// Function to convert numbers from char type to int type, and into base 10
unsigned int convert(const char *c, int base){
    unsigned int size = 0, num = 0;
    const char *temp;
    for(temp = c; *temp != '\0'; temp++){
        size++;
    }
    if(base == 2){
        for(int i = 2; i < size; i++){
            num *= 2;
            num += c[i] - '0';
        }
    }else if(base == 16){
        for(int i = 2; i < size; i++){
            num *= 16;
            if(c[i] >= 'a' && c[i] <= 'f'){
                num += c[i] - 'a' + 10;
            }else{
                num += c[i] - '0';
            }
        }
    }else{
        for(int i = 0; i < size; i++){
            num *= 10;
            num += c[i] - '0';
        }
    }
    return num;
}

int main(int argc, char** argv){
    if(argc<3){
        printf("Argument error.\n");
        return -1;
    }
    unsigned int a = 0, b = 0;
    stack* s = (stack*)malloc(sizeof(stack)+ (argc-1)*sizeof(int));
    s->size = 0;
    s->top = -1;
    for(int i = 1; i < argc; i++){
        if(strcmp(argv[i], "add") == 0){
            if(s->size >= 2){
                b = pop(s);
                a = pop(s);
                a = add(a,b);
                push(s,a);
            }
        }else if(strcmp(argv[i], "sub") == 0){
            if(s->size >= 2){
                b = pop(s);
                a = pop(s);
                a = sub(a,b);
                push(s,a);
            }
        }else if(strcmp(argv[i], "mult") == 0){
            if(s->size >= 2){
                b = pop(s);
                a = pop(s);
                a = mult(a,b);
                push(s,a);
            }
        }else if(strcmp(argv[i], "div") == 0){
            if(s->size >= 2){
                b = pop(s);
                a = pop(s);
                a = divide(a,b);
                push(s,a);
            }
        }else{
            if(argv[i][0] == '0' && argv[i][1] == 'b'){
                push(s,convert(argv[i],2));
            }else if(argv[i][0] == '0' && argv[i][1] == 'x'){
                push(s,convert(argv[i],16));
            }else{
                push(s,convert(argv[i],10));
            }
            
        }        
    }
    printf("%u\n",a);
    return 0;
}
