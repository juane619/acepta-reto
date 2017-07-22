#include <stdio.h>

int main(){
	unsigned fact, veces;
	
	scanf("%u", &veces);
	
	for( ; veces>0; veces--){
		scanf("%u", &fact);
		if( fact >4 ) printf("%u\n", 0);
		else if( fact ==2 || fact ==4  || fact == 1) printf("%u\n", fact);
		else if( fact == 0) printf("%u\n", 1);
		else if( fact ==3 ) printf("%u\n", 6);
 	}
}
