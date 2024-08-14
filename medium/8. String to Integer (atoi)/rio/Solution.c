#include <limits.h>
#include <stdbool.h>
#include <string.h>

int myAtoi(char* s) {
    int i = 0;
    long long int ans = 0;
    bool nega = false;
    bool posi = false;
    while (s[i] == ' ') {
        i++;
    }

    if (s[i] == '-') {
        nega = true;
        i++;
    } else if (s[i] == '+') {
        posi = true;
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        ans = ans * 10 + (s[i] - '0'); 
        if (ans > INT_MAX) {
            return nega ? INT_MIN : INT_MAX;
        }
        i++;
    }

    if (nega) {
        ans = -ans;
    }

    return (int)ans;
}