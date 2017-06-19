#include <stdio.h>

void cutMiddle(int *arr, float middle, int N, float A, int delta){

	int  i;
	float value = 0;

	delta = delta/2;

	for(i = 0; i < N; i++) {
		value += arr[i] - middle > 0 ? arr[i] - middle : 0;
	}
	if(value == A){
		printf("%.4lf", middle);
	} else {
		if (value > A)
			cutMiddle(arr, middle + (delta/10000), N, A, delta);
		else
			cutMiddle(arr, middle - (delta/10000), N, A, delta);
	}
};

int main(){

	int N, A;
	int H;
	int total;

	while(scanf("%d %d", &N, &A) && N && A) {
		H = 0;
		total = 0;
		int arr[N], i;

		for(i = 0; i < N; i++){
			scanf("%d", &arr[i]);
			H = arr[i] > H ? arr[i] : H;
			total += arr[i];
		}
		if(total == A) {
			printf(":D\n");
		} else if(total < A) {
			printf("-.-\n");
		} else {
			cutMiddle(arr, H/2, N, A, (H*10000)/2);
		}
	}

	return 0;
}


// 50 23
// 5 3 6 2 3 52 33 6 2 3 5 3 6 24 3 5 3 63 2 3 5 34 6 2 3 55 3 6 2 36 5 3 62 2 3 5 3 6 2 3 5 3 6 2 3 5 3 6 2 3
// 0 0
