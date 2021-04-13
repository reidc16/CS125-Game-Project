#include <stdio.h>
void player(void){
FILE *player;
    char str[100];
    char* filename = "player.txt";
    player = fopen("player.txt", "r");
    if(player == NULL)
      printf("Could not open file %s", filename);
    while (fgets(str, 100, player) != NULL)
      printf("%s", str);
    fclose(player);
return 0;
}






