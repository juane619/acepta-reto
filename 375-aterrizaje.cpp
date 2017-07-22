#include <cstdio>

using namespace std;

int main(){
	char c;
	int d;
	
	while(scanf("%d%c",&d, &c)>0){
		bool car=false;
		
		if(c!='\n'){
			car=true;
		}
		
		d=(d+18)%36;
		
		if(d==0)
			d=36;
	
		printf("%02d", d);
		
		if(car){
			if(c=='L' || c=='l')
				c='R';
			else if(c=='R' || c== 'r')
				c='L';
			else
				c='C';
			
			printf("%c",c);
		}
		
		printf("\n");
		
		
	}
	return 0;
}
