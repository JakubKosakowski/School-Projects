Class_RPS::Class_RPS(int sX){
	if(sX > 0){
		this->sX = sX;
		this->pX = new int[sX];
		this->sP = sX;
		this->pP = new float[sX];		
	}
	else{
		this->sX = 0;
		this->pX = NULL;
		this->sP = 0;
		this->pP = NULL;
	}
}
void Class_RPS::FillInt(int x, int i){
	pX[i] = x;
}
void Class_RPS::FillFloat(float x, int i){
	pP[i] = x;
}
void Class_RPS::PrintX(){
	cout<<"Xi |	";
    for(int i = 0; i< sX;++i){
    	cout<<pX[i]<<"	";	
	}
    cout<<endl;    
}
void Class_RPS::PrintP(){
    cout<<"Pi |	";
    for(int i = 0; i< sX;++i){
    	cout<<pP[i]<<"	";	
	}
    cout<<endl;
}
double Class_RPS::WO(){
	double wo = 0;
	for(int i = 0; i < sX; ++i){
		wo += pX[i] * pP[i];
	}
	return wo;
}
float Class_RPS::checkP(){
	float cP = 0;
	for(int i = 0; i < sP; ++i){
		cP += pP[i];
	}
	return cP;
}
double Class_RPS::Var(double x){
	double var = 0;
	for(int i = 0; i < sP; ++i){
		var += pow(pX[i], 2) * pP[i]; 	
	}
	return var - pow(x,2);
}
