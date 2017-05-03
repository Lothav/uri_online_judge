#include <stdio.h>

#define VISITED 1
#define NOT_VISITED 0


int main(){
  
  int x, y, aux_y, aux_x;
  scanf("%d", &x);
  scanf("%d", &y);
  
  char map[y][x+1];
  int map_visited[y][x+1];
  
  for(aux_y = 0; aux_y < y ; aux_y++ ){
    scanf("%s", map[aux_y]);
    for(aux_x = 0; aux_x < x; aux_x++){
      map_visited[aux_y][aux_x] = NOT_VISITED;
    }
  }
  
  aux_x = 0;
  aux_y = 0;
  char last;
  while(1){
    
    if(aux_x >= x || aux_y >= y || map_visited[aux_y][aux_x]){
      printf("!\n");
      return 0;
    }
    
    map_visited[aux_y][aux_x] = 1;
    
    if(map[aux_y][aux_x] == '.'){
      map[aux_y][aux_x] = last;
    }
    
    switch(map[aux_y][aux_x]){
      case('*'):
	printf("*\n");
	return 0;
      case('>'):
	aux_x++;
	last = '>';
	break;
      case('<'):
	aux_x--;
	last = '<';
	break;
      case('^'):
	aux_y--;
	last = '^';
	break;
      case('v'):
	last = 'v';
	aux_y++;
	break;
    }
  }
  return 0;
}
