char* makeGood(char* s) {
    int top = -1;

    for (int i = 0; s[i]; i++) {
        if (top >= 0 && ((s[top] ^ s[i]) == 32)) {
            top--;
        } else {
            s[++top] = s[i];
        }
    }

    s[top + 1] = '\0';
    return s;
}