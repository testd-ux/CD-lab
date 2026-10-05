#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i = 0;

int E(void);
int EP(void);
int T(void);
int TP(void);
int F(void);

int main() {
    printf("RD parser\n");
    printf("Grammar\n");
    printf("E -> TE'\n");
    printf("E' -> +TE' | e\n");
    printf("T -> FT'\n");
    printf("T' -> *FT' | e\n");
    printf("F -> (E) | id\n");
    
    printf("Enter strg to parse: ");
    scanf("%99s", input);

    i = 0;
    
    if (E() && input[i] == '\0') {
        printf("\nString successfully accepted\n");
    } else {
        printf("\nString Rejected\n");
    }
    
    return 0;
}

int E() {
    if (T()) {
        return EP();
    }
    return 0;
}

int EP() {
    if (input[i] == '+') {
        i++;
        if (T()) {
            return EP();
        }
        return 0;
    }
    return 1;
}

int T() {
    if (F()) {
        return TP();
    }
    return 0;
}

int TP() {
    if (input[i] == '*') {
        i++;
        if (F()) {
            return TP();
        }
        return 0;
    }
    return 1;
}

int F() {
    if (input[i] == '(') {
        i++;
        if (E()) {
            if (input[i] == ')') {
                i++;
                return 1;
            }
            return 0;
        }
        return 0;
    } 
    else if (input[i] == 'i' && input[i+1] == 'd') {
        i += 2;
        return 1;
    } 
    else if (isalpha(input[i])) {
        i++;
        return 1;
        
        
        
        
        sdx@pop-os:~/Desktop/first 5$ ./a.out
RD parser
Grammar
E -> TE'
E' -> +TE' | e
T -> FT'
T' -> *FT' | e
F -> (E) | id
Enter strg to parse: a+a

String successfully accepted

    }
    return 0;
}
