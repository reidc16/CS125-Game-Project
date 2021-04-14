#include <stdio.h>
void tiegame(void){
FILE *tiegame;
    char str[100];
    char* filename = "tiegame.txt";
    tiegame = fopen("tiegame.txt", "r");
    if(tiegame == NULL)
      printf("Could not open file %s", filename);
    while (fgets(str, 100, tiegame) != NULL)
      printf("%s", str);
    fclose(tiegame);
}
