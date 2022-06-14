#include <stdio.h>

int get_number_factors(int x, int A[]){
	int top=0;
	int divisor=2;
	while(x != 1){
		while(x%divisor == 0)
		{
			A[top] = divisor;
			top++;
			x /= divisor;
		}
		divisor++;
	}
	return top;
}

int main(int argc, char* argv[]){
	int x;
	printf("Enter number to factorize:");
	scanf("%d", &x);
	int A[100], N;	
	
	N = get_number_factors(x, A);
	for(int i=0;i<N;++i)
		printf("%d ", A[i]);
	printf("\n");

	return 0;
}


