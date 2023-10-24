#include<stdio.h>
#include<math.h>

int main() {
	int i;
	printf("Input an integer: ");
	scanf("%d", &i);
	
	if (i % 2 == 0) {
		printf("%d is a even number.", i);
	} else {
		printf("%d is an odd number.", i);
	}
	return 0;
}
