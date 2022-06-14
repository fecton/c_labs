#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int abs(int number){
    if(number <= 0) return number*-1;
    return number;
}

int main(int argc, char const *argv[])
{
    int n=1,m=1,choice=0, negative=0, min_by_absolute;
    printf("Enter n,m: ");
    scanf("%d%d", &m, &n);
    int matrix[n][m]; // matrix NxM
    printf("Would you line to random it or enter? (0/1): ");
    scanf("%d", &choice);
    printf("\n");
    // user choice RANDOM/INPUT
    if(choice == 1){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                printf("You're entering matrix[%d][%d]: ", i,j);
                scanf("%d", &matrix[i][j]);
            }
            printf("\n");
        }
    } else{
        srand((unsigned) time(NULL));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                negative = rand()%2;
                matrix[i][j] = rand()%100+1;
                if(negative == 1) matrix[i][j] *= -1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    min_by_absolute=abs(matrix[0][0]);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(abs(matrix[i][j]) < min_by_absolute) min_by_absolute = abs(matrix[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            matrix[i][j] -= min_by_absolute;
        }
    }
    printf("\n");
    printf("Min by absolute: %d\n", min_by_absolute);
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}
