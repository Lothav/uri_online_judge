//
// Created by luizorv on 5/6/17.
//

#include <stdio.h>
#include <malloc.h>

int hasLoop(int **tree_visited, int R, int from, int act, int N2){

	int i, loops = 0;
	for(i = 1; i <= R; i++) {
		if(act == N2){
			loops += 1;
		} else if(act != i && from != i ){
			if(tree_visited[act][i]){
				loops += hasLoop(tree_visited, R, act, i, N2);
			}
		}
	}
	return loops;
}

int main(){

	int R, C, V, W, P;
	int i, j;

	scanf("%d %d", &R, &C);
	int matrix_adj[R+1][R+1];

	int **tree_visited = (int**)calloc((size_t) R+1, sizeof(int*));;

	for(i = 0; i <= R; i++){
		for(j = 1; j <= R; j++){
			matrix_adj[i][j] = 0;
		}
		tree_visited[i] = (int *) calloc((size_t) R+1, sizeof(int));
	}

	for(i = 0; i < C; i++){
		scanf("%d %d %d", &V, &W, &P);
		matrix_adj[V][W] = P;
		matrix_adj[W][V] = P;
	}

	int lower_cost_key[2] = {0}, lower_cost_value;
	int k, m = R-1;

	int total_cost = 0;

	while(m--){
		k = 1, lower_cost_value = -1;
		for(i = 2; i <= R; i++) {
			for(j = 1; j <= k; j++) {
				if(matrix_adj[i][j] && (matrix_adj[i][j] < lower_cost_value || lower_cost_value < 0)){
					if(!hasLoop(tree_visited, R, 0, i, j)){
						lower_cost_key[0] = i;
						lower_cost_key[1] = j;
						lower_cost_value = matrix_adj[i][j];
					}
				}
			}
			k++;
		}
		matrix_adj[lower_cost_key[0]][lower_cost_key[1]] = 0;

		tree_visited[ lower_cost_key[0] ][ lower_cost_key[1] ] = 1;
		tree_visited[ lower_cost_key[1] ][ lower_cost_key[0] ] = 1;

		total_cost += lower_cost_value;
	}
	printf("%d\n", total_cost);

	/*for(i = 1; i <= R; i++)
		printf("\t%c", i + 96);

	printf("\n");
	for(i = 1; i <= R; i++){
		printf("%c", i + 96);
		for(j = 1; j <= R; j++)
			printf("\t%d", tree_visited[i][j]);
		printf("\n");
	}*/

	for(i = 0; i <= R; i++) free(tree_visited[i]);
	free(tree_visited);

	return 0;
}

/*
 Cormen's book test:

9 14
1 2 4
1 8 8
2 8 11
2 3 8
8 9 7
3 9 2
7 8 1
7 9 6
3 4 7
3 6 4
6 7 2
4 6 14
5 6 10
4 5 9

 result: 37
 */
