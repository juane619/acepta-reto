#include <cstdio>
#include <cstring>
#include <ctype.h>

using namespace std;

int main(){
	unsigned veces;
	int tam, i;
	char palabra[40];
	
	scanf("%u", &veces);
	
	for( ; veces>0; veces--){
		scanf("%s", &palabra);
		tam= strlen(palabra);
		i=tam-1;
		for(; i>=0; i--){
			if((palabra[0] < 'A' | palabra[0]>'Z' | i!=tam-1)==0)
				printf("%c", (char)toupper(palabra[i]));
			else
				printf("%c", (char)tolower(palabra[i]));
		}
	printf("\n");
 	}
}
