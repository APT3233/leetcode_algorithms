
char* longestCommonPrefix(char** strs, int strsSize) {

    if (strsSize == 0) return ""; 

    int minLength = strlen(strs[0]);

    for(int i = 1; i < strsSize; i++){
        if(strlen(strs[i]) < minLength){
            minLength = strlen(strs[i]);
        }
    }
   char* result = (char*)malloc((minLength + 1) * sizeof(char));

    int index = 0;

    for(int i = 0; i < minLength; i++){
        char letter = strs[0][i];
        for(int j = 0; j < strsSize; j++){
            if(letter != strs[j][i]){
                result[index] = '\0';
                return result;
            }
        }
        result[index++] = letter;
    }
    result[index] ='\0';
    return result;
}