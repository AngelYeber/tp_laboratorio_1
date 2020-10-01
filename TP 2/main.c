#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#define T 1000

int main()
{
    sEmployee list[T];

    initEmployees(list, T);

    mainFunctionality(list, T);

    return 0;
}
