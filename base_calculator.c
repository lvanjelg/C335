#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack{
    int size;
    int top;
    long int nums[];
} stack;

long int add(long int a, long int b){
    return a + b;
}
long int sub(long int a, long int b){
    return a - b;
}
long int mult(long int a, long int b){
    return a * b;
}
long int divide(long int a, long int b){
    return a / b;
}
long int pop(stack* s){
    int temp = s->nums[s->top];
    s->size = s->size - 1;
    s->top = s->top - 1;
    return temp;
}
void push(stack* s, long int a){
    s->size = s->size + 1;
    s->top = s->top + 1;
    s->nums[s->top] = a;
}
long int convert(char c, int base){

    return 0;
}

int main(int argc, char** argv){
    if(argc<3){
        printf("Argument error.\n");
        return -1;
    }
    long int a = 0, b = 0;
    int base = 0;
    stack* s = (stack*)malloc(sizeof(stack)+ (argc-1)*sizeof(long int));
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
            push(s,strtol(argv[i],base));
        }        
    }
    printf("%li\n",a);
    return 0;
}
