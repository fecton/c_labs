#include <stdio.h>
#include <stdbool.h>
#include <iso646.h>
#define N 6


int inputarr(int A[], int max_size){
	int top;

	while(true){
		int x;
		scanf("%d", &x);
		if (x == 0 or top == max_size) break;
		A[top] = x;
		top++;
	}

	return top;
}


void printarr(int A[]){
	for(int i;i<N;i++) printf("%d "); 
	printf("\n");
}


void insert_sort(int A[], int N){
	for(int i=1;i<N;++i){
		int k = i;
		while(k > 0 and A[k-1] > A[k]){
			int tmp;
			tmp = A[k-1];
			A[k-1] = A[k];
			A[k] = tmp;
			k -= 1;
		}
	}
}


int main(int argc, char* argv){
	int A[N] = {5,3,1,2,6,4};

	printarr(A);
	insert_sort(A, N);
	printarr(A);

	return 0;
}















