#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int
main(void)
{
    char *s = malloc(17);
    memcpy(s, "double-free-prog", 16);
    printf("%s", s);
    free(s);
    free(s);
}
