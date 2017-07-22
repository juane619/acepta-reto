#include <iostream>
#include <cstring>

using namespace std;

bool resolver(){
	int h, c, vueltas=0;
	
	do{
		cin >> h >> c;
	}
	while(h < 1 && h > 10000 && c < 1 && h > 10000);
	
	if(h == 0 && c==0)
		return false;
	
	for(int i=0; i<h; i+=c)
		vueltas++;
		
		cout << vueltas*10 << "\n";
		
		
	return true;
}

int main() {
	bool seguir=true;
	
	do{
		seguir= resolver();
	}while(seguir);

	
	return 0;
}