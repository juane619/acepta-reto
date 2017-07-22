#include <iostream>

using namespace std;

void resolver(){
	int a=0, b=0;
	char c;
	
	do{
		cin >> a >> c >> b;
	}while((a <= 0 || a >= 1000000) || (b <= 0 || b >= 1000000));
	 
	 if((b==a+1 || a==b+1)){
	 	if(a<b && a%2==0)
		 cout << "SI";
		else if(b<a && b%2==0)
			cout << "SI";
		else
			cout << "NO";
}
else
			cout << "NO";
		cout << "\n";
}

int main() {
	int n_casos, i=0;
	
	cin >> n_casos;

	for (int i=0; i<n_casos; i++)
		resolver();
	
	return 0;
}