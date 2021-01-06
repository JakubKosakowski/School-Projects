void Application::Run(){
	Main01();
}
void Application::Main01(){ //funkcja wyœwietla pocz¹tkowy komunikat
	int w;
	cout<<"Witaj w mojej aplikacji z RPS!"<<endl;
	cout<<"Co mam dla Ciebie policzyc?"<<endl;
	cout<<"1. Wartosci zmiennej losowej"<<endl;
	cout<<"2. Standaryzacja rozkladu normalnego"<<endl;
	cin >> w;
	switch(w){
		case 1:
			Main02();
		break;
		case 2:
			Main06();
		break;
		default:
			cout<<"No tak, ale takiej opcji nie ma."<<endl;
			Main01();
		break;
	}
}
void Application::Main02(){ //funkcja wyœwitla komunikat po wybraniu watroœci oczekowaniej
	system("CLS");
	int w;
	cout<<"Zmienna losowa jest: "<<endl;
	cout<<"1. Dyskretna"<<endl;
	cout<<"2. Ciagla"<<endl;
	cin >> w;
	switch(w){
		case 1:
			Main03();
		break;
		case 2:
			Main05();
		break;
		default:
			cout<<"No tak, ale takiej opcji nie ma."<<endl;
			Main02();
		break;
	}
}
void Application::Main03(){ //funkcja wyœwietla komunikat po wybraniu opcji "Dyskretna"
	system("CLS");
	int n;
	cout<<"Podaj mi ilosc x-ow w tabeli: ";
	cin >> n; //wprowadzamy rozmiar tablicy
	Main04(n);	
}
void Application::Main04(int n){ //
	Class_RPS c01(n);
	cout<<"Podaj wartosci x-ow: ";
	int x;
	for(int i = 0; i < n; ++i){
		cin >> x;
		c01.FillInt(x, i);
	}
	cout<<"Podaj wartosci p: ";
	float p;
	for(int i = 0; i < n; ++i){
		cin >> p;
		c01.FillFloat(p, i);
	}
	float d = c01.checkP();
	std::bitset<sizeof(float)*CHAR_BIT>a(*reinterpret_cast<unsigned long*>(&d));
	if(a.to_string() != "00111111011111111111111111111111" && a.to_string() != "00111111100000000000000000000000"){
		system("CLS");
		cout<<a<<endl;
		cout<<"Suma prawdopodobienstw nie jest rowna 1"<<endl;
		cout<<"Sprobuj ponownie!"<<endl;
		Main04(n);
	}
	else{
		system("CLS");
		c01.PrintX();
		cout<<"-------------------------------------------------------------\n";
		c01.PrintP();
		cout<<endl;
		double wo = c01.WO(), var = c01.Var(wo);
		cout<<"Wartosc oczekiwana: "<<wo<<endl;
		cout<<"Wariacja: "<<var<<endl;
		cout<<"Odchylenie standardowe: "<<sqrt(var)<<endl;
	}
	Main12();
}
void Application::Main05(){	
}
void Application::Main06(){
	int w;
	cout<<"Suma jest: "<<endl;
	cout<<"1. Mniejsza od zadanej liczby"<<endl;
	cout<<"2. Wiekszy od zadanej liczby"<<endl;
	cout<<"3. Okreslony obszarem"<<endl;
	cin >> w;
	switch(w){
		case 1:
			Main07(w);	
		break;
		case 2:
			Main07(w);
		break;
		case 3:
			Main07(w);
		break;
		default:
			system("CLS");
			cout<<"No tak, ale takiej opcji nie ma."<<endl;
			Main06();
		break;
	}
}
void Application::Main07(int x){
	int w;
	cout<<"Jakie jest CTG?"<<endl;
	cout<<"1. Lindberg-Levy"<<endl;
	cout<<"2. Moivre-Laplace"<<endl;
	cin >> w;
	switch(w){
		case 1:
			switch(x){
				case 1:
					Main08(x);
				break;
				case 2:
					Main08(x);
				break;
				case 3:
					Main08(x);
				break;
			}
		break;
		case 2:
			switch(x){
				case 1:
					Main09(x);
				break;
				case 2:
					Main09(x);
				break;
				case 3:
					Main09(x);
				break;
			}
		break;
		default:
			system("CLS");
			cout<<"No tak, ale takiej opcji nie ma."<<endl;
			Main07(x);
	}
}
void Application::Main08(int x){
	system("CLS");
	int w;
	cout<<"Wartosci sa: "<<endl;
	cout<<"1. Podane"<<endl;
	cout<<"2. Trzeba je policzyc"<<endl;
	cin >> w;
	switch(w){
		case 1:
			switch(x){
				case 1:
					Main10(x);	
				break;
				case 2:
					Main10(x);
				break;
				case 3:
					Main10(x);
				break;
			}
		break;
		case 2:
			
		break;
		default:
			cout<<"No tak, ale takiej opcji nie ma."<<endl;
			Main08(x);
		break;
	}
}
void Application::Main09(int x){
	system("CLS");
	int w;
	cout<<"Wartosci sa: "<<endl;
	cout<<"1. Podane"<<endl;
	cout<<"2. Trzeba je policzyc"<<endl;
	cin >> w;
	switch(w){
		case 1:
			switch(x){
				case 1:
					Main11(x);	
				break;
				case 2:
					Main11(x);
				break;
				case 3:
					Main11(x);
				break;
			}
		break;
		case 2:
			
		break;
		default:
			cout<<"No tak, ale takiej opcji nie ma."<<endl;
			Main09(x);
		break;
	}
}
void Application::Main10(int x){
	system("CLS");
	int n;
	double wo, sd, a, b;
	cout<<"Podaj zakres sumy n: ";
	cin >> n;
	cout<<"\nPodaj wartosc oczekiwana(srednia): ";
	cin >> wo;
	cout<<"\n Podaj odchylenie standardowe: ";
	cin >> sd;
	if(x == 1){
		cout<<"Podaj liczbe od ktorej suma jest mniejsza: ";
		cin >> a;
		Class_RPS c01(wo,sd,a,n,x);
		double I = c01.Ia();
		if(I >= 0){
			cout<<"Wynik to I("<<std::setprecision(3)<<I<<")"<<endl;	
		}	
		else{
			cout<<"Wynik to 1 - I("<<std::setprecision(3)<<I*(-1)<<")"<<endl;
		}
	}	
	else if(x == 2){
		cout<<"Podaj liczbe od ktorej suma jest wieksza: ";
		cin >> b;
		Class_RPS c01(wo,sd,b,n,x);
		double I = c01.Ib();
		if(I >= 0){
			cout<<"Wynik to 1 - I("<<std::setprecision(3)<<I<<")"<<endl;	
		}
		else{
			cout<<"Wynik to I("<<std::setprecision(3)<<I*(-1)<<")"<<endl;
		}
	}
	else{
		cout<<"Z zakresu a <= Sn <= b podaj a i b: ";
		cin >> a >> b;
		Class_RPS c01(wo,sd,a,b,n,x);
		double Ia = c01.Ia();
		double Ib = c01.Ib();
		cout<<"Wynik to I("<<std::setprecision(3)<<Ib<<") - I("<<Ia<<")"<<endl;	
	}
	Main12();
}
void Application::Main11(int x){
	system("CLS");
	int n;
	float p, q;
	cout<<"Podaj zakres sumy n: ";
	cin >> n;
	cout<<"Podaj prawdopodobienstwo sukcesu: ";
	cin >>p;
	q = 1-p;
	double a, b;
	if(x == 1){
		cout<<"Podaj liczbe od ktorej suma jest mniejsza: ";
		cin >> a;
		Class_RPS c01(p,q,a,n,x);
		double I = c01.I2a();
		if(I >= 0){
			cout<<"Wynik to I("<<std::setprecision(3)<<I<<")"<<endl;	
		}	
		else{
			cout<<"Wynik to 1 - I("<<std::setprecision(3)<<I*(-1)<<")"<<endl;
		}
	}
	else if(x == 2){
		cout<<"Podaj liczbe od ktorej suma jest wieksza: ";
		cin >> b;
		Class_RPS c01(p,q,b,n,x);
		double I = c01.I2b();
		if(I >= 0){
			cout<<"Wynik to 1 - I("<<std::setprecision(3)<<I<<")"<<endl;	
		}
		else{
			cout<<"Wynik to I("<<std::setprecision(3)<<I*(-1)<<")"<<endl;
		}	
	}
	else{
		cout<<"Z zakresu a <= Sn <= b podaj a i b: ";
		cin >> a >> b;
		Class_RPS c01(p,q,a,b,n,x);
		double Ia = c01.I2a();
		double Ib = c01.I2b();
		cout<<"Wynik to I("<<std::setprecision(3)<<Ib<<") - I("<<Ia<<")"<<endl;	
	}
	Main12();		
}
void Application::Main12(){
	char c;
	cout<<"Czy chcesz kontynuowac dzialanie programu?	Y/N"<<endl;	
	cin >> c;
	if(c == 'Y' || c == 'y'){
		system("CLS");
		Main01();
	}
	else{
		system("CLS");
		cout<<"Dziekuje za skorzystanie z aplikacji! W ramach usprawnienia programu zglos propozycje do tworcy programu.";
		exit(0);
	}
}
