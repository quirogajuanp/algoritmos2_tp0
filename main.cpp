#include <iostream>
#include "main.h"
using namespace std;

int main(void){
	complex a(1,2),b(1,-2),d;
	double z=-10;
	complex c(a);
	c=b;
	cout<<'a'<<'='<<a<<endl;
	cout<<'b'<<'='<<b<<endl;
	cout<<"parte real de c"<<'='<<c.get_real()<<endl;
	cout<<"parte imaginaria de c"<<'='<<c.get_imag()<<endl;
	return 0;
}