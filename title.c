#include <stdio.h>
void title(void){
FILE *title;
  char str[100];
  char* filename = "title.txt";
  title = fopen("title.txt" , "r");
  if(title == NULL)
     printf("Could not open file %s", filename);
  while (fgets(str, 100, title) != NULL)
     printf("%s", str);
  fclose(title);
return 0;
}

