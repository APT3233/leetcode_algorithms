bool isPalindrome(char* s){
    int  i, j;
    for(i = 0; j = strlen(s) - 1; i < j;){
        if(!isalnum(s[i])){
            ++i;
            continue;
        }
        if(!isalnum(s[j])){
            --j;
            continue;
        }
        if(tolower(s[i++]) != tolower(s[j--])) return false;
    } 
    return true;
}