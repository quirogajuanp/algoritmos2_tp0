#include <iostream>
using namespace std;

class complex{
	double x,y;
public:
	complex(){x=0;y=0;}
	complex(double m, double n){x=m;y=n;}
	complex(complex const &c){x=c.x;y=c.y;}
	complex(double m){x=m;y=0;}
	~complex(){}

	complex operator +(const complex & c);
	complex operator +(double d);
	friend complex const operator+(const double d, const complex & c);
	complex operator -(const complex & c);
	complex operator -(double d);
	friend complex const operator-(const double d, const complex & c);
	complex operator *(const complex & c);
	complex operator *(double d);
	friend complex const operator*(const double d, const complex &c);
	complex & operator=(complex const &c);

	double get_real() const;
	double get_imag() const;

	friend std::ostream & operator <<(std::ostream &, const complex & );

};

//------------------------
// 		 Operator +
//------------------------
complex complex :: operator +(const complex & c){
	return complex(c.x+x,c.y+y);
}
complex complex :: operator +(double d){
	return complex(x+d,y);
}

complex const operator +(const double d, const complex & c){
	return complex(d+c.get_real(), c.get_imag());
}

//------------------------
// 		 Operator -
//------------------------
complex complex :: operator -(const complex & c){
	return complex(x-c.x,y-c.y);
}
complex complex :: operator -(double d){
	return complex(x-d,y);
}
complex const operator -(const double d, const complex & c){
	return complex(d-c.get_real(), c.get_imag());
}
//------------------------
// 		 Operator *
//------------------------
complex complex :: operator *(const complex & c){
	return complex(x*c.x-y*c.y,x*c.y+y*c.x);
}
complex complex :: operator *(double d){
	return complex(x*d,y*d);
}
complex operator*(double d, complex &c){
	return complex(d*c.get_real(),d*c.get_imag());
}

//------------------------
// 		 Operator =
//------------------------
complex & complex::operator=(complex const &c)
{
	x = c.get_real();
	y = c.get_imag();
	return *this;
}

//------------------------
// 		 Operator <<	
//------------------------
std::ostream & operator <<(std::ostream & os, const complex &c){
	os<<'('<<c.x<<','<<c.y<<')';
	return os;
}

//------------------------
// 		 Getter
//------------------------
double complex :: get_real() const{
	return x;
}

double complex :: get_imag() const{
	return y;
}
	/*
	
	
	
	
	
	void set_real(double d);
	void set_imag(double d);
	void set(double d1, double d2);
	
}





//------------------------
// 		 Setter
//------------------------
void complex :: set_real(double d){
	x=d;
}

void complex :: set_imag(double d){
	y=d;
}

void complex :: set(double d1, double d2){
	x=d1;
	y=d2;
}
*/