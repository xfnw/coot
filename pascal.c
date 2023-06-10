#include <stdio.h>

const char *margin = "   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .";

long unsigned int factorial(int x){
    long unsigned int result = 1;

    if (x == 0 || x == 1)
        return result;

    for(int i = 2; i <= x; i++)
        result = result * i;

    return result;
}

long unsigned int pascal_triangle_nth(int row, int x){
    row--;
    x--;

    return factorial(row) / ( factorial(row - x) * factorial(x) );
}


int main(){
    for(int i = 1; i <= 20; i++){
        printf("%02d%s", i, margin+(3*i));

        for(int j = 1; j <= i; j++)
            printf("% 6ld", (long)pascal_triangle_nth(i, j));

        printf("\n");
    }
}
