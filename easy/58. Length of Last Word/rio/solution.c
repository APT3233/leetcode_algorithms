int lengthOfLastWord(char* s) {
    int count = 0;
    int i = strlen(s) - 1;
    while(i >= 0 && s[i] == ' ') {
        i--;
    }

    while( i >= 0 && s[i] != ' '){
    count++; 
    i--;
    } 
    return count;
}
