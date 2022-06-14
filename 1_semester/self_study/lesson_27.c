#include <stdio.h>
#define N 4

void printarr(int arr[]){
	for(int i=0;i<N;++i) printf("%d ", arr[i]);
	printf("\n");
}


int main(int argc, char* argv[]){
	int m = 0;
	int A[N] = {2, 6, 13, 39};

	for(int i=0;i<N;i++)
		for(int k=i+1;k<N;k++)
			if (A[i]*A[k]%26 == 0)
				m++;
	printf("%d\n", m);
	

	return 0;
}


