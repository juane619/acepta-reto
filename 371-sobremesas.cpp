#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int calc(int n){
	if(n==1)
		return 3;
	else
		return 3*n+calc(n-1);
}

bool resolver(){
	int n1, res;
	
	do{
		cin >> n1;
	}
	while(n1 < 0 || n1 >= 20000);
	
	if(n1==0)
		return false;
		
	res= calc(n1);
	cout << res << "\n";
	
	return true;
}

int main() {
	bool seguir=true;
	
	do{
		seguir= resolver();
	}while(seguir);

	
	return 0;
}