#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    int n=0,m=0,K=0, multiply_result=1, sum_result=0, negative=0, choice=0;
    printf("Enter n,m, K: ");
    scanf("%d%d%d", &n, &m, &K);
    K -= 1;
    if(n<1 || m<1 || K>m) return -1;
    int matrix[n][m];
    printf("Would you line to random it or enter? (0/1): ");
    scanf("%d", &choice);
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
    printf("\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    for(int i=0;i<n;i++){
        sum_result += matrix[i][K];
        multiply_result *= matrix[i][K];
    }
    printf("\n");
    printf("Muliply result: %d\n", multiply_result);
    printf("Sum result: %d\n", sum_result);
    return 0;
}


