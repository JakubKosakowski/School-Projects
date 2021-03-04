#include <iostream>

using namespace std;

int main(){
	int y;
	
	cin >> y;
	
	cout<<endl;
	
	cout<<((y % 4 == 0) && ((y % 100 == 0)&&(y % 400 == 0)))<<endl;
	
	return 0;
}
