void rFilter(char* s) {

    int strLen = strlen(s);

    for (char* temp = &s[strLen-1]; temp >= &s[0]; temp--) {
        if (! ((*temp >= 'a' && *temp <= 'z') || (*temp >= 'A' && *temp <= 'Z')) ) {
            *temp = '_';
        }
        else break;
    }
}