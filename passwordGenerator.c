#include <stdio.h>
#include <string.h>
#define NUMBER_OF_ATTEMPTS 5

int includes(char*, int(*)(char));
int numbers(char);
int lowercase(char);
int uppercase(char);
int special_characters(char);
int has_consecutive_letters(char*);

int main() {
    int attempts = NUMBER_OF_ATTEMPTS, length;
    char password[100];
    printf("\nGenerate password: ");
    while (attempts--) {
        scanf("%s", password);

        length = strlen(password);
        if (length < 8 || length > 12)
            printf("Password length must be greater than 8 and less than 12.\n");
        else if (!includes(password, lowercase))
            printf("The password is missing lowercase letters.\n");
        else if (!includes(password, uppercase))
            printf("The password is missing uppercase letters.\n");
        else if (!includes(password, numbers))
            printf("The password is missing digits.\n");
        else if (!includes(password, special_characters))
            printf("The password is missing special characters.\n");
        else if (has_consecutive_letters(password))
            printf("The password should not contain consecutive letters of same case.\n");
        else
            break;

        if (attempts != 0)
            printf("Try again: ");
    }

    if (attempts == -1)
        printf("\nYou are failed to generate a valid password.\n");
    else
        printf("\nGenerated successful password: %s\n", password);
}

int includes(char str[], int (*in_range)(char)) {
    int i, len;

    len = strlen(str);
    for (i = 0; i < len; i++) {
        if (in_range(str[i]))
            return 1;
    }
    return 0;
}

int numbers(char c) {
    return (c >= '0' && c <='9');
}

int lowercase(char c) {
    return (c >= 'a' && c <='z');
}

int uppercase(char c) {
    return (c >= 'A' && c <='Z');
}

int special_characters(char c) {
    return (c == '*' || c == '#' || c == '@' || c == '$' 
            || c == '&' || c == '_'|| c == '!' || c == '?'
            || c == '^' || c == '*' || c == '%' );
}

int has_consecutive_letters(char* str) {
    int i, len;

    len = strlen(str);
    for (i = 0; i < len-1; i++) {
        if (lowercase(str[i]) && lowercase(str[i+1]))
            return 1;
        if (uppercase(str[i] && uppercase(str[i+1])))
            return 1;
    }
    return 0;
}