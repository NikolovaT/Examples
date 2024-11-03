void rev(char *str){
    if(!str) return;

    char *end = str;
    if(*end == '\0') return;
    while(*end != '\0') end++;
    end--;

    char *start = str;
    char temp = *str;

    while(start < end){
        temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

