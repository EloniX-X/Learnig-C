#include <stdio.h>

int main() {
    int num1, num2, res;
    char oper;
    printf("what operator: ");
    scanf(" %c", &oper);
    printf("ok what num1: ");
    scanf("%d", &num1);
    printf("ok what num2: ");
    scanf("%d", &num2);
   // scanf("%d", &num1);
   // printf("its %d\n", num1);
    switch (oper) {
        case '+':
            printf("cool \n");
            res = num1 + num2;
            break;
        case '-':
            printf("sucks \n");
            res = num1 - num2;
            break;
        default: 
            printf("bad \n");
    }
    printf("%d \n", res);
    return 0;
}


//%d <-- int
//%lf <-- double
//%c <-- char, character
//%s <-- string 
//& <-- get addr of var for modification in scanf or pointers
//The segmentation fault (signal 11) indicates an attempt to write to memory that has not been allocated to the process for writing. A common reason for this is when array bounds are exceeded.Mar 10, 2020
