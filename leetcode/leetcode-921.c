/*
 * Minimum Add to Make Parentheses Valid
*/
int minAddToMakeValid(char* S) {
    int size = strlen(S);
    int i = -1;
    char * stack = (char*) malloc(sizeof(char) * size);
    for(int j = 0; j < size; j++) {
        if(i == -1) {
            stack[++i] = S[j];
        } else {
            if (stack[i] == '(' && S[j]  == ')' ) {
                i--;
            } else {
                stack[++i] = S[j];
            }
        }
    }
    return i + 1;
}
