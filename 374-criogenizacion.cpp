#include <stdio.h>

int main(){
	unsigned veces;
	unsigned long long N, menor=1, mayor=1, vmenor=1, vmayor=1;
	
	scanf("%d", &veces);
	
	for( ; veces>0; veces--){
		scanf("%llu", &N);
		mayor=menor=N;

		while(scanf("%llu", &N) && N!=0 ){

			if(N==menor)
				vmenor++;
			if(N==mayor)
				vmayor++;
			
			if(N>mayor){
				mayor=N;
				vmayor=1;
			}
			else if(N<menor){
				menor=N;
				vmenor=1;
			}
		}
		
		printf("%llu %llu %llu %llu\n", menor, vmenor, mayor, vmayor);
		vmenor=vmayor=1;
 	}
}
