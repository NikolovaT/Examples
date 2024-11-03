#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "reverse.h"

int main()
{

    // testing void rev(char *str);
    char *str = malloc(sizeof(char)*100);
    if (!str) {
        perror("Unable to allocate memory. ");
        return 1;
    }

    printf("Enter a string to reverse it: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = '\0';

    rev(str);
    printf("%s\n", str);

    free(str);
    str=NULL;

    return 0;
}
