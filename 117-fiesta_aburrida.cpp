#include <cstdio>

int main() {
	int n_personas;
	char soy[4];
	char nombre[100];
	
	scanf("%d", &n_personas);

	for( ; n_personas>0; n_personas--){
		scanf("%s", soy);
		scanf("%s", nombre);
		printf("Hola, %s.\n", nombre);
	}
		
	return 0;
}
