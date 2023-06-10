#include <stdio.h>

static char *margin = "   .   .   .   .   .   .   .   .   .   .   .   .   .   .   .";

long long unsigned int factorial(int x){
    long long unsigned int result = 1;

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


int main(int argc, char *argv[]){
    int scale = 3;
    int offset = 0;

    if (argc > 1 && *argv[1] == 's') {
        scale = 2;
	offset = 20;
    }

    for(int i = 1; i <= 20; i++){
        printf("%02d%s", i, margin+(scale*i)+offset);

        for(int j = 1; j <= i; j++)
            printf("% 6d", (int)pascal_triangle_nth(i, j));

        printf("\n");
    }
}

