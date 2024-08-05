int romanCharToInt(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int romanToInt(char *s) {
    int total = 0;
    int prevValue = 0;
    int currentValue;
    
    for (int i = strlen(s) - 1; i >= 0; i--) {
        currentValue = romanCharToInt(s[i]);
        if (currentValue < prevValue) {
            total -= currentValue;
        } else {
            total += currentValue;
        }
        prevValue = currentValue;
    }
    
    return total;
}