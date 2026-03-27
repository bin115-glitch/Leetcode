char* largestNumber(int* nums, int numsSize) {
    static char s[100][12], *a[100], res[1000] = "";
    for(int i =0; i<numsSize; i++){
        sprintf(s[i], "%d", nums[i]);
        a[i] = s[i];
    }
    int cmp(const void* x,const void* y){
        char ab[30], ba[30];
        sprintf(ab, "%s%s",*(char**)x, *(char**)y);
        sprintf(ba, "%s%s",*(char**)y, *(char**)x);
        return strcmp(ba, ab);
    }
    qsort(a,numsSize,sizeof(char*), cmp);
    if(a[0][0] == '0') return "0";
    res[0] = '\0';
    for(int i=0; i<numsSize; i++) strcat(res, a[i]);
    return res;

}