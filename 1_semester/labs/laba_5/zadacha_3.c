#include <stdio.h>

int main(int argc, char* argv[]){
    int x,y;
    printf("Enter (x,y): ");
    scanf("%d%d", &x, &y);

    if(
        ((x>=-6 && x<=7) && (y>=5 && y<=6)) || 
        ((x>=-5 && x<=-2) && (y>=3 && y<=5))
      )  printf("Yes\n");
    else printf("NO\n");


    return 0;
}
