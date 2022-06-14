// m = (x>10)?x:10
#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
    int m = 0;
    while(true){
        int x;
        scanf("%d", &x);
        if(x==0) break;

        m = x>m ? x:m;
    }
    printf("maximum = %d\n", m);
    return 0;
}

