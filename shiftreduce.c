#include <stdio.h>
#include <string.h>

int k = 0, z = 0, i = 0, j = 0, c = 0;
char a[50], ac[20], stk[50], act[20];

void check();

void main()
{
    puts("GRAMMAR IS E->E+E \n E->E*E \n E->(E) \n E->id");

    puts("Enter input string:");
    scanf("%s", a);

    c = strlen(a);
    strcpy(act, "SHIFT->");

    puts("stack \t input \t action");

    for (k = 0, i = 0, j = 0; j < c; k++, i++, j++)
    {
        if (a[j] == 'i' && a[j + 1] == 'd')
        {
            stk[i] = 'i';
            stk[i + 1] = 'd';
            stk[i + 2] = '\0';

            a[j] = ' ';
            a[j + 1] = ' ';

            printf("\n$%s\t$%s$\t%s id", stk, a, act);

            i++;
            j++;

            check();
        }
        else
        {
            stk[i] = a[j];
            stk[i + 1] = '\0';

            a[j] = ' ';

            printf("\n$%s\t$%s$\t%s symbol", stk, a, act);

            check();
        }
    }

    check();
}

void check()
{
    strcpy(ac, "REDUCE TO E");
    int flag = 1;

    while (flag)
    {
        flag = 0;

        for (z = 0; z < strlen(stk); z++)
        {
            if (stk[z] == 'i' && stk[z + 1] == 'd')
            {
                stk[z] = 'E';

                for (int x = z + 1; x < strlen(stk); x++)
                    stk[x] = stk[x + 1];

                printf("\n$%s\t$%s$\t%s id", stk, a, ac);

                flag = 1;
                break;
            }
        }

        for (z = 0; z < strlen(stk); z++)
        {
            if (stk[z] == 'E' && stk[z + 1] == '+' && stk[z + 2] == 'E')
            {
                stk[z] = 'E';

                for (int x = z + 1; x < strlen(stk); x++)
                    stk[x] = stk[x + 2];

                printf("\n$%s\t$%s$\t%s E+E", stk, a, ac);

                flag = 1;
                break;
            }
        }

        for (z = 0; z < strlen(stk); z++)
        {
            if (stk[z] == 'E' && stk[z + 1] == '*' && stk[z + 2] == 'E')
            {
                stk[z] = 'E';

                for (int x = z + 1; x < strlen(stk); x++)
                    stk[x] = stk[x + 2];

                printf("\n$%s\t$%s$\t%s E*E", stk, a, ac);

                flag = 1;
                break;
            }
        }

        for (z = 0; z < strlen(stk); z++)
        {
            if (stk[z] == '(' && stk[z + 1] == 'E' && stk[z + 2] == ')')
            {
                stk[z] = 'E';

                for (int x = z + 1; x < strlen(stk); x++)
                    stk[x] = stk[x + 2];

                printf("\n$%s\t$%s$\t%s (E)", stk, a, ac);

                flag = 1;
                break;
            }
        }
    }

    if (stk[0] == 'E' && stk[1] == '\0')
        printf("\n$%s\t$%s$\tString is accepted\n", stk, a);
    else
        printf("\n$%s\t$%s$\tString is not accepted\n", stk, a);
}



dx@pop-os:~/Desktop/first 5$ ./a.out
GRAMMAR IS E->E+E 
 E->E*E 
 E->(E) 
 E->id
Enter input string:
id+id*id
stack 	 input 	 action

$id	$  +id*id$	SHIFT-> id
$E	$  +id*id$	REDUCE TO E id
$E	$  +id*id$	String is accepted

$E	$   id*id$	SHIFT-> symbol
$E	$   id*id$	String is accepted

$E	$     *id$	SHIFT-> id
$E	$     *id$	String is accepted

$E	$      id$	SHIFT-> symbol
$E	$      id$	String is accepted

$E	$        $	SHIFT-> id
$E	$        $	String is accepted

$E	$        $	String is accepted

