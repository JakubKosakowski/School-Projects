#include <iostream>

using namespace std;

int main(){
	int h, m;
	cin >> h;
	cin >> m;
	if ((h < 0) || (m < 0) || (h > 24) || (m > 60)){
		cout<<"error"<<endl;
	}
	else{
		if(h < 10){
			cout<<false<<endl;
		}
		else if ((h == 10) && (m < 30)){
			cout<<false<<endl;
		}
		else if ((h == 18) && (m > 30)){
			cout<<false<<endl;
		}
		else if(h > 18){
			cout<<false<<endl;
		}
		else{
			cout<<true<<endl;
		}
	}
	
	
}
