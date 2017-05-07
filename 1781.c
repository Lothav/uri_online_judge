
#include <stdio.h>
#include <string.h>

int main() {

	long long int cases = 0;
	long int operations = 0;

	int op;
	unsigned long long int value;

	char str[ 10001 ], aux[ 10001 ];

	int cm, vm;

	int c = 0, i;
	int printed_case;
	long int vowel_value;
	long int consonants_value;
	int has_last_case;

	int consonants_mask[ 10000 ];
	int vowels_mask[ 10000 ];

	scanf( "%lli", &cases );

	while ( cases-- ){
		c++;

		scanf("%s", str);

		cm = 0, vm = 0, printed_case = 0;

		for(i = 0; i < strlen(str); i++) {
			if(str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u'){
				consonants_mask[cm++] = i;
			} else {
				vowels_mask[vm++] = i;
			}
		}

		scanf("%li", &operations);

		vowel_value = 0;
		consonants_value = 0;
		has_last_case = 0;


		while ( operations-- ) {

			scanf("%d", &op);

			strcpy(aux, str);

			if( op == 0 ){

				scanf("%llu", &value);
				vowel_value += value;
				has_last_case = 1;

			} else if( op == 1 ) {

				scanf("%llu", &value);
				consonants_value += value;
				has_last_case = 1;

			} else {

				if( !(printed_case++) ){
					printf( "Caso #%d:\n", c );
				}

				if(has_last_case && (consonants_value || vowel_value) ){
					for( i = 0; i < (vm > cm ? ( vowel_value ? vm : cm) : ( consonants_value ? cm : vm)); i++ ){

						if(consonants_value && i < cm){
							str[ consonants_mask[(i+consonants_value) % cm] ] = aux[ consonants_mask[ i ] ];
						}

						if(vowel_value && i < vm){
							str[ vowels_mask[(i+vowel_value) % vm] ] = aux[ vowels_mask[ i ] ];
						}
					}
					consonants_value = 0;
					vowel_value = 0;
				}
				has_last_case = 0;
				printf( "%s\n", str );

			}
		}
	}
	return 1;
}
