#include <stdio.h>

int main()
{
    FILE *f = NULL;
    f = fopen("univ/SDA/text.txt", "rt");
    char str[20];
    if (f != NULL)
    {
        while (!feof(f))
        {
            printf("%s", str);
        }
        printf("Hello, Dumi!");
    }
    return 0;
}