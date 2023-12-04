#include<stdio.h>
#include<math.h>

int main(){
	
	int n;
	int total = 0;
	printf("Input an Integer: ");
	scanf("%d", &n);
	
	for(int i = 1, count = 0; count < n; i += 2, count++ ){
		total += i;
	}
	printf("The sum of %d off number is: %d", n, total);
	return 0;
}
