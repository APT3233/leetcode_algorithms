#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int reverse = 0;
    while (x > reverse) {
        reverse = reverse * 10 + x % 10;
        x /= 10;
    }

    return x == reverse || x == reverse / 10;
}

int main(){
    int x = 121;
    printf("Case 1: ");
    isPalindrome(x) ? printf("Passed\n") : printf("Failed\n");

    int y = -121;
    printf("Case 2: ");
    isPalindrome(y) ? printf("Passed\n") : printf("Failed\n");

    int z = 10;
    printf("Case 3: ");
    isPalindrome(z) ? printf("Passed\n") : printf("Failed\n");

    return 0;
}