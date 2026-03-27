
typedef struct {
    char c;
    int count;
} Pair;
char* removeDuplicates(char* s, int k) {
    int n = strlen(s);
    Pair stack[100000];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (top != -1 && stack[top].c == s[i]) {
            stack[top].count++;
            if (stack[top].count == k) {
                top--; 
            }
        } else {
            top++;
            stack[top].c = s[i];
            stack[top].count = 1;
        }
    }

    // build kết quả
    char* res = (char*)malloc(n + 1);
    int idx = 0;

    for (int i = 0; i <= top; i++) {
        for (int j = 0; j < stack[i].count; j++) {
            res[idx++] = stack[i].c;
        }
    }

    res[idx] = '\0';
    return res;
}