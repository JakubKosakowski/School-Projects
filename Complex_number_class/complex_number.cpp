#define PI 3.14159265

Complex_number::Complex_number(){
	this->re = 0;
	this->im = 0;
	this->modulus = 0;
	this->cosine = 1;
	this->sine = 0;
	this->angle = 0;
	this->complex_conjugate();
}

Complex_number::Complex_number(double x){
	this->re = x;
	this->im = 0;
	this->modulus = x;
	this->cosine = 1;
	this->sine = 0;
	this->angle = 0;
	this->complex_conjugate();
}

Complex_number::Complex_number(double x, double y){
	this->re = x;
	this->im = y;
	this->modulus = Complex_number::count_modulus(x,y);
	this->cosine = Complex_number::count_cosine(this->re, this->modulus);
	this->sine = Complex_number::count_sine(this->im, this->modulus);
	this->angle = Complex_number::count_arg(this->cosine);
	this->complex_conjugate();
}

Complex_number::Complex_number(const Complex_number* c1){
	this->re = c1->re;
	this->im = c1->im;
	this->modulus = c1->modulus;
	this->cosine = c1->cosine;
	this->sine = c1->sine;
	this->angle = c1->angle;
	this->complex_conjugate();
}

void Complex_number::print(){
	cout<<"Complex number: ";
	if(this->im < 0){
		cout<<this->re<<" - "<<(this->im)*(-1)<<"i"<<endl;
	}
	else if (this->im > 0){
		cout<<this->re<<" + "<<(this->im)<<"i"<<endl;
	}
	else{
		cout<<this->re<<endl;
	}
	cout<<"Modulus: "<<this->modulus<<endl;
	cout<<"Cosine: "<<this->cosine<<endl;
	cout<<"Sine: "<<this->sine<<endl;
	cout<<"Angle: "<<this->angle<<endl;
	cout<<"Conjugate: ";
	if(this->im_con < 0){
		cout<<this->re_con<<" - "<<(this->im_con)*(-1)<<"i"<<endl;
	}
	else if (this->im_con > 0){
		cout<<this->re_con<<" + "<<(this->im_con)<<"i"<<endl;
	}
	else{
		cout<<this->re_con<<endl;
	}
	cout<<"Trigonometrical form: ";
	if(this->sine < 0){
		cout<<this->modulus<<" * ("<<this->cosine<<" - "<<(this->sine)*(-1)<<"i)"<<endl;
	}
	else if (this->sine > 0){
		cout<<this->modulus<<" * ("<<this->cosine<<" + "<<this->sine<<"i)"<<endl;
	}
	else{
		cout<<this->modulus<<" * ("<<this->cosine<<")"<<endl;
	}

}

double Complex_number::count_modulus(double x, double y){
	return sqrt(x * x + y * y);
}

Complex_number Complex_number::complex_sum(const Complex_number* z, const Complex_number* w){
	this->re = z->re + w->re;
	this->im = z->im + w->im;

	return *this;
}

void Complex_number::complex_sum(const Complex_number* z){
	cout<<"Sum of complex number: (";
	cout<<this->re<<" + "<<this->im<<"i";
	cout<<") + ("<<z->re<<" + "<<z->im<<"i";
	cout<<") = ";
	if(this->im + z->im > 0){
		cout<<this->re + z->re<<" + "<<this->im + z->im<<"i";
	}
	else{
		cout<<this->re + z->re<<" - "<<(this->im + z->im) * (-1)<<"i";	
	}
	cout<<endl;
}

Complex_number Complex_number::complex_multiple(const Complex_number* c1, const Complex_number* c2){
	this->re = (c1->re * c2->re) - (c1->im * c2->im);
	this->im = (c1->re * c2->im) + (c1->im * c2->re);
	return *this;
}

void Complex_number::complex_multiple(const Complex_number* z){
	if(this->im > 0){
		cout<<"Multiple of complex number: ("<<this->re<<" + "<<this->im<<"i) * ";
	}
	else if(this->im < 0){
		cout<<"Multiple of complex number: ("<<this->re<<" - "<<(this->im) * (-1)<<"i) * ";	
	}
	else{
		cout<<"Multiple of complex number: "<<this->re<<" * ";	
	}
	if(z->im > 0){
		cout<<"("<<z->re<<" + "<<z->im<<"i) = ";
	}
	else if(z->im < 0){
		cout<<"("<<z->re<<" - "<<(z->im) * (-1)<<"i) = ";	
	}
	else{
		cout<<z->re<<" = ";
	}	
	if((this->re*z->im + this->im*z->re) > 0){
		cout<<this->re*z->re - this->im*z->im<<" + "<<this->re*z->im + this->im*z->re<<"i";
	}
	else if((this->re*z->im + this->im*z->re) < 0){
		cout<<this->re*z->re - this->im*z->im<<" - "<<(this->re*z->im + this->im*z->re) * (-1)<<"i";	
	}
	else{
		cout<<this->re*z->re - this->im*z->im;	
	}
	cout<<endl;
}

Complex_number Complex_number::complex_divide(const Complex_number* c1, const Complex_number* c2){
	this->re = (c1->modulus / c2->modulus * cos((c1->angle - c2->angle)));
	this->im = (c1->modulus / c2->modulus * sin((c1->angle - c2->angle)));
	return *this;
}

void Complex_number::complex_divide(const Complex_number* z){
	if(this->im > 0){
		cout<<"Divide of complex number: ("<<this->re<<" + "<<this->im<<"i) / ";
	}
	else if(this->im < 0){
		cout<<"Divide of complex number: ("<<this->re<<" - "<<(this->im) * (-1)<<"i) / ";	
	}
	else{
		cout<<"Divide of complex number: "<<this->re<<" / ";	
	}
	if(z->im > 0){
		cout<<"("<<z->re<<" + "<<z->im<<"i) = ";
	}
	else if(z->im < 0){
		cout<<"("<<z->re<<" - "<<(z->im) * (-1)<<"i) = ";	
	}
	else{
		cout<<z->re<<" = ";
	}
	if((this->modulus / z->modulus * sin((this->angle - z->angle))) > 0){
		cout<<this->modulus / z->modulus * cos((this->angle - z->angle))<<" + "<<this->modulus / z->modulus * sin((this->angle - z->angle))<<"i";
	}
	else if((this->modulus / z->modulus * sin((this->angle - z->angle))) < 0){
		cout<<this->modulus / z->modulus * cos((this->angle - z->angle))<<" - "<<(this->modulus / z->modulus * sin((this->angle - z->angle))) * (-1)<<"i";	
	}
	else{
		cout<<this->modulus / z->modulus * cos((this->angle - z->angle));	
	}
	cout<<endl;	
}

void Complex_number::complex_conjugate(){
	this->re_con = this->re;
	this->im_con = (this->im)*(-1);
}

void Complex_number::show_conjugate(){
	if(im_con > 0){
		cout<<"Complex conjugate: "<<endl;
		cout<<"__________"<<endl;
		cout<<this->re<<" - "<<(this->im)*(-1)<<"i = "<<this->re_con<<" + "<<this->im_con<<"i"<<endl;
	}
	else{
		cout<<"Complex conjugate: "<<endl;
		cout<<" ______"<<endl;
		cout<<"("<<this->re<<" + "<<this->im<<"i) = "<<this->re_con<<" - "<<(this->im_con)*(-1)<<"i"<<endl;
	}
}

void Complex_number::distance(const Complex_number* w){
	cout<<"|z - w| = "<<sqrt(pow((this->re - w->re),2) + pow((this->im - w->im),2))<<endl;
}

double Complex_number::distance(const Complex_number* c1, const Complex_number* c2){
	return sqrt(pow((c1->re-c2->re),2) + pow((c1->im-c2->im), 2));
}

double Complex_number::count_cosine(double x, double y){
	return x/y;
}

double Complex_number::count_sine(double x, double y){
	return x/y;
}

double Complex_number::count_arg(double x){
	double a = 0;
	double angle;
	
	while(true){
		if(cos(a*PI/180) > this->cosine){
			++a;
		}
		else{
			break;
		}
	}
	if(cos(a*PI/180)-this->cosine > cos((a-1)*PI/180)-this->cosine){
		angle = a-1;
	}
	else{
		angle = a;
	}
	
	return angle;
	
}

void Complex_number::de_Moivre(int n){
	if(this->im > 0){
		cout<<"("<<this->re<<" + "<<this->im<<"i)^"<<n<<" = ";
	}
	else if(this->im < 0){
		cout<<"("<<this->re<<" - "<<(this->im) * (-1)<<"i)^"<<n<<" = ";
	}
	else{
		cout<<this->re<<"^"<<n<<" = ";	
	}
	cout<<pow(this->modulus,n)<<" * ("<<cos(this->angle*n)<<" + "<<sin(this->angle*n)<<"i)"<<endl;
}
