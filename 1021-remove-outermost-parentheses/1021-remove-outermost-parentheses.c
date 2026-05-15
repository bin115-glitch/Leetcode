char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    char* res = (char*)malloc((n + 1) * sizeof(char));

    int depth = 0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            if (depth > 0) {
                res[idx++] = s[i];
            }
            depth++;
        } else {
            depth--;
            if (depth > 0) {
                res[idx++] = s[i];
            }
        }
    }

    res[idx] = '\0';
    return res;
}