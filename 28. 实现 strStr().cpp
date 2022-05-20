int strStr(char * haystack, char * needle){   
    if(*haystack == '\0' && *needle == '\0')
        return 0;
    // if(!needle)
    //     return -1; 
    char* s1;
    char* s2;
    char* cp = haystack;
    while(*cp)
    {
        s1 = cp;
        s2 = needle;
        while(*s1 && *s2 && *s1 == *s2)
        {
            s1++;
            s2++;
        }
        if(*s2 == '\0')
        {
            return (cp-haystack);
        }
        cp++;
    }

    return -1;
}
