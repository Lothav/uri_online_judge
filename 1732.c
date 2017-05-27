#include <stdio.h>

int abs(int i){
	return i >= 0 ? i : -1*i;
}

int main(){

	int path_willi;
	while (scanf("%d", &path_willi) != -1){

		if(path_willi == 1){
			printf("0 0\n");
			continue;
		}

		int shift = 0, last = 2;
		while(((path_willi) / (last+=(6*++shift)))  >= 1);
		last -= 6*shift;

		int references[2] = {((1)*shift) + last-1, ((4)*shift) + last-1};
		if(references[0] == path_willi) {
			printf("0 %d\n", shift);
			continue;
		}
		if(references[1] == path_willi) {
			printf("0 %d\n", -1*shift);
			continue;
		}

		int dist_0 = abs(path_willi - references[0]);
		int dist_1 = abs(path_willi - references[1]);

		int col = 0;
		int row = 0;

		int ref_pos = 0;
		if(2*dist_0 >= dist_1 ){
			ref_pos = path_willi - references[1];
			if(ref_pos > 0){
				col = dist_1 > shift ? shift : dist_1;
				if(dist_1 == col){
					row = -1*shift;
				} else if(col == shift){
					row = (-1*shift) + dist_1-shift;
				}
			} else {
				col = dist_1 > shift ? -1*shift : -1*dist_1;
				if(dist_1 == abs(col)){
					row = -1*shift -col;
				} else if(abs(col) == shift){
					row = dist_1 - shift;
				}
			}
		} else {
			ref_pos = path_willi - references[0];
			if(ref_pos > 0){
				row = shift;
				col = -1*dist_0;
			} else {
				row = shift - dist_0;
				col = dist_0;
			}
		}
		printf("%d %d\n", col, row);
	}

	return 0;
}

/*
1
2
3
4
5

 */
