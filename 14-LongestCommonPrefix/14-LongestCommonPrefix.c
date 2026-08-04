// Last updated: 8/4/2026, 12:25:58 PM
char* longestCommonPrefix(char** strs, int strsSize) {
    if(strsSize == 0){
        return "";
    }
    int i=0;
    while(strs[0][i] != '\0'){
        char c=strs[0][i];
        for(int j=1;j<strsSize;j++){
            if(strs[j][i] == '\0' || strs[j][i] != c){
                char* res = (char*)malloc(i+1);
                strncpy(res, strs[0], i);
                res[i] = '\0';
                return res;
            }
        }
        i++;
    }
    char* res = (char*)malloc(i+1);
    strncpy(res, strs[0], i);
    res[i]='\0';
    return res;
}