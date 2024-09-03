char* convert(char* s, int numRows) {
    if (numRows == 1) {
        return s;
    }

    int len = strlen(s);
    int numCols = len;
    char table[numRows][numCols];

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            table[i][j] = '\0';
        }
    }

    int index = 0;
    int i = 0, j = 0;
    int direction = 1;

    while (s[index] != '\0') {
        table[i][j] = s[index];
        index++;

        if (i == numRows - 1) {
            direction = -1;
        } else if (i == 0) {
            direction = 1;
        }

        i += direction;

        if (direction == -1) {
            j++;
        }
    }

    
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int resultIndex = 0;

 
    for (int a = 0; a < numRows; a++) {
        for (int b = 0; b < numCols; b++) {
            if (table[a][b] != '\0') {
                result[resultIndex++] = table[a][b];
            }
        }
    }

    result[resultIndex] = '\0';

    return result;
}