/*
 * DI String Match
*/

int* diStringMatch(char* S, int* returnSize) {
    if(S == NULL) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = strlen(S) + 1;
    int i;
    int max = *returnSize - 1;
    int min = 0;
    int last_value = -1;
    int * A = (int *) malloc (*returnSize * sizeof(int));
    for(i = 0; i < (*returnSize - 1); i++) {
        if(S[i] == 'I') {
            A[i] = min;
            min += 1;
            last_value = min;
        } else {
            A[i] = max;
            max -= 1;
            last_value = max;
        }
    }
    
    if (i < *returnSize)
        A[i] = last_value;
    return A;
}
