#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

	int last_number, i, j, total, n_not_allowed, string_n_not_allowed;

	char str0[150000] , str1[150000];

	while(scanf("%d", &last_number) && last_number){
		total = 0;
		scanf("%d", &n_not_allowed);
		
		for(i = 0; i < n_not_allowed; i++){
			scanf("%d", &string_n_not_allowed);
			sprintf(str0, "%d", string_n_not_allowed);
			for (j = 0; j < last_number; ++j) {
				sprintf(str1, "%d", j);
				if(strstr(str1, str0) != NULL) total++;
			}
		} 
		printf("%d\n", total);
	}

	return EXIT_SUCCESS;
}
