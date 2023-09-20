#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

   char **args = argv;
    while (*args != NULL)
    {
        printf("Argument: %s\n", *args);
        args++;
    }

    return 0;
}
