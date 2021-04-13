#include <stdio.h>
void tictac(void){
FILE *tictac;
    char str[100];
    char* filename = "tictac.txt";
    tictac = fopen("tictac.txt", "r");
    if(tictac == NULL)
      printf("Could not open file %s", filename);
    while (fgets(str, 100, tictac) != NULL)
      printf("%s", str);
    fclose(tictac);
return 0;
}



