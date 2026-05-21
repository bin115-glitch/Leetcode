char* longestPalindrome(char* s) {

    int start = 0;
    int maxLen = 1;

    int len = strlen(s);

    for (int i = 0; i < len; i++) {

        // odd
        int l = i;
        int r = i;

        while (l >= 0 && r < len && s[l] == s[r]) {

            int curr = r - l + 1;

            if (curr > maxLen) {
                start = l;
                maxLen = curr;
            }

            l--;
            r++;
        }

        // even
        l = i;
        r = i + 1;

        while (l >= 0 && r < len && s[l] == s[r]) {

            int curr = r - l + 1;

            if (curr > maxLen) {
                start = l;
                maxLen = curr;
            }

            l--;
            r++;
        }
    }

    char* ans = (char*)malloc(maxLen + 1);

    strncpy(ans, s + start, maxLen);

    ans[maxLen] = '\0';

    return ans;
}