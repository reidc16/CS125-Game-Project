#include <stdio.h>
void gameover(void){
FILE *gameover;
    char str[100];
    char* filename = "gameover.txt";
    gameover = fopen("gameover.txt", "r");
    if(gameover == NULL)
      printf("Could not open file %s", filename);
    while (fgets(str, 100, gameover) != NULL)
      printf("%s", str);
    fclose(gameover);
return 0;
}



