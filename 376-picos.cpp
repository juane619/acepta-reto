#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int alturas[2], veces, alt=-1, i=0, ant=-1, picos=0;
	bool subiendo=false;
	
	while(scanf("%d",&veces)>0 && veces!=0){
		for( ; veces>0; veces--){
			scanf("%d",&alt);
			if(i<2)
				alturas[i]=alt;
			
			if(subiendo && alt<ant){
				picos++;
				subiendo=false;
			}else if(subiendo)
				subiendo=false;
			
			if(i>0 && alt>ant)
				subiendo=true;
			
			ant=alt;
			i++;
		}
		if(subiendo && alt>alturas[0]){
			picos++;
		}
	if(alturas[0]>alt){
			if(alturas[0]>alturas[1])
				picos++;
		}
		
		printf("%d\n",picos);
		picos=i=0;
		ant=alt=-1;
	}
	return 0;
}
