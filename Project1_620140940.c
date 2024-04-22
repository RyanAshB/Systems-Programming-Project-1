/*Ryan Badaloo - 620140940*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char kbinput[25];
    FILE *fptr;

    fptr = fopen("keylogfile.txt", "w");

    printf("root@DESKTOP-K42UQV8:~# ");

    while (1) {
        if (fgets(kbinput, sizeof(kbinput), stdin) == NULL) {
            fclose(fptr);
            exit(0);
        }

        kbinput[strcspn(kbinput, "\n")] = '\0';

        if (strcmp(kbinput, "~") == 0) {
            fclose(fptr);
            exit(0);
        }

        system(kbinput);
        fprintf(fptr, "%s\n", kbinput);
        printf("root@DESKTOP-K42UQV8:~# ");
    }

    fclose(fptr);
}