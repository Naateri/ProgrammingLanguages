#include <iostream>
using namespace std;

void by_value(int c, int d){
	c++;
	c = d+1;
	cout << c << ' ' << d << endl;
}

void by_reference(int& c, int& d){
	c++;
	c = d+1;
	cout << c << ' ' << d << endl;
}

int main(int argc, char *argv[]) {	
	int a = 2, b = 5;
	cout << "Original values, a: " << a << ", b: " << b << endl;
	cout << "By value:\n";
	by_value(a,b);
	cout << "Current values, a: " << a << ", b: " << b << endl; 
	by_reference(a,b);
	cout << "Current values, a: " << a << ", b: " << b << endl; 
	///do something with new updated values
	///...
	cout << "Do something with new updated values\n";
	return 0;
}

