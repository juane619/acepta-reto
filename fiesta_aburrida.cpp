#include <cstdio>


void fastscan(int &number) 
{ 
    
    register int c; 
  
    number = 0; 
  
    // extract current character from buffer 
    c = getchar(); 
    
    // Keep on extracting characters if they are integers 
    // i.e ASCII Value lies from '0'(48) to '9' (57) 
    for (; (c>47 && c<58); c=getchar()) 
        number = number *10 + c - 48; 
  
} 

int main() {
	int n_personas;
	char soy[4];
	char nombre[100];
	
	fastscan(n_personas);

	for( ; n_personas>0; n_personas--){
		scanf("%s", soy);
		scanf("%s", nombre);
		printf("Hola, %s.\n", nombre);
	}
		
	return 0;
}
