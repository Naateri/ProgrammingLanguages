#include <iostream>

using namespace std;

class Integer{
	int n;
public:
	Integer(){
		this->n = 0;
	}
	Integer(int n){
		this-> n = n;
	}
	Integer operator+(Integer A){
		cout << "Doing sum\n";
		cout << "First value: " << this->n << endl;
		cout << "Second value: " << A.n << endl;
		Integer B(this->n + A.n);
		cout << "Result: " << B.n << endl;
		return B;
	}
	Integer operator*(Integer A){
		cout << "Doing multiplication\n";
		cout << "First value: " << this->n << endl;
		cout << "Second value: " << A.n << endl;
		Integer B(this->n * A.n);
		cout << "Result: " << B.n << endl;
		return B;
	}
	friend ostream& operator<<(ostream &out, Integer& c);
};

ostream& operator<<(ostream& out, Integer& c){
	out << c.n << endl;
	return out;
}

int main(int argc, char *argv[]) {
	Integer A(1);
	Integer B(2);
	Integer C(3);
	Integer D(4);
	
	Integer E;
	E = A + B * C + D;
	
	cout << E << endl;
	
	return 0;
}

