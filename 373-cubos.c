#include <stdio.h>

long long potencia(int n, int pot){
	if(pot==0)
		return 1;
	if(pot==1)
		return n;
	
	long long res=n;
	
	for(int i=1; i<pot; i++)
		res*=n;
		
	return res;
}

int main(){
	int veces;
	long long N, aux;
	
	scanf("%d", &veces);
	
	for( ; veces>0; veces--){
		scanf("%lli", &N);
		aux=(N-2)*4*(N-1);
		N=2*potencia(N,2)+aux;
		printf("%lli\n", N);
 	}
}
