void Application::Run(){
	Main01();
}
void Application::Main01(){ //funkcja wyœwietla pocz¹tkowy komunikat
	int w;
	cout<<"Witaj w mojej aplikacji z RPS!"<<endl;
	cout<<"Co mam dla Ciebie policzyc?"<<endl;
	cout<<"1. Wartosci zmiennej losowej"<<endl;
	cin >> w;
	switch(w){
		case 1:
			Main02();
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
		c01.PrintX();
		cout<<"-------------------------------------------------------------\n";
		c01.PrintP();
		cout<<endl;
		double wo = c01.WO(), var = c01.Var(wo);
		cout<<"Wartosc oczekiwana: "<<wo<<endl;
		cout<<"Wariacja: "<<var<<endl;
		cout<<"Odchylenie standardowe: "<<sqrt(var)<<endl;
	}
}
