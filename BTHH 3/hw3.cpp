#include<stdio.h>
#include<math.h>

int main(){
	int i;
	int n;
	for(i = 2; i <= 9; i++){
		printf("The multiplication of %d is:\n", i);
		for(n = 1; n <= 10; n++){
			printf("%d x %d = %d\n",i ,n ,i * n);
		}
		printf("\n");
	}
	return 0;
}
