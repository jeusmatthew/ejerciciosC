#include <stdio.h>

int main(int argc, char const* argv[]) {
    unsigned long long num;

    do {
        scanf("%llu", &num);
    } while ((long long int) num < 0);

    return 0;
}
