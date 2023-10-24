#include<stdio.h>
#include<math.h>

int main(){
	float score;
	printf("Input a mark: ");
	scanf("%f", &score);
	
	if(score >= 9 && score < 10){
		printf("Xuat sac");
	} else if(score >= 8 && score <9){
		printf("Gioi");
	}else if(score >= 6.5 && score <8){
		printf("Kha");
	}else if(score >= 5 && score <6.5){
		printf("Trung binh");
	}else{
		printf("Yeu");
	}
	
	return 0;
	
}
