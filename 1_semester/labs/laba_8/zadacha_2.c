#include <stdio.h>
int main(int argc, char const *argv[])
{
    int negative_count=0, moved_elements_count=0, tmp=0, j=0, N;
    printf("Enter N: ");
    scanf("%d", &N);
    if(N<0) return -1;
    int A[N];
    for(int i=0;i<N;i++){
        printf("Enter the number[%d]: ", i);
        scanf("%d", &A[i]);
    }
    for(int i=0;i<N;i++){
        if(A[i]<0) negative_count++;
        if(A[i] == 0){
            j=i;
            while(j!=0 && A[j-1] != 0){
                tmp = A[j-1];
                A[j-1] = 0;
                A[j] = tmp;
                j--;
            }
            moved_elements_count++;
        }
    }
    printf("\n\nNegative count = %d\nMoved elements count = %d\n\n", negative_count, moved_elements_count);
    for(int i=0;i<N;i++) printf("%d ", A[i]);
    printf("\n");
    return 0;
}
