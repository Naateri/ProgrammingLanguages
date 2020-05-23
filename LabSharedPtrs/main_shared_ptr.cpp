#include <iostream>
#include "SharedPointer.h"
using namespace std;

struct C {int data;};

struct test{
	int data;
	float xd;
	char s;
};

int counter_helper = 0;
struct Counter
{
	int value;
	Counter () // al inicializar counter_helper incrementa en 1.
	{
		value = 0;
		++counter_helper;
	}
	~Counter () // al destruirse, counter_helper disminuye en 1.
	{
		--counter_helper;
		std::cout << "Destroying counter " << counter_helper << std::endl;
	}
};

int main(int argc, char *argv[]) {
	
	SharedPointer<C> p (new C);
	p->data = 5;
	std::cout << p->data << std::endl;
	
	SharedPointer<test> p1 (new test);
	p1->data = 5;
	p1->xd = 5.5;
	p1->s = 'c';
	
	std::cout << p1->data << ' ' << p1->xd << ' ' << p1->s << std::endl;
	
	SharedPointer<int> a (new int);
	
	cout << "a: " << a.get() << endl;
	
	*a = 20;
	SharedPointer<int> b(a);
	
	cout << "b: " << b.get() << endl;
	
	cout << *a << endl;
	cout << "use count: " << b.use_count() << endl;
	
	cout << "p1 unique " << p1.unique() << endl;
	
	a.reset(new int(25));
	cout << "a: " << a.get() << endl;
	cout << *a << ' ' << *b << endl;
	cout << "a " << a.use_count() << ", b " << b.use_count() << endl;
	
	a.reset();
	if (a) cout << "Pointer exists\n";
	else cout << "Pointer doesn't exist\n";
	
	SharedPointer<float> c(new float);
	*c = 20.0f; 
	cout << *c << endl;
	
	//RESET
	
	/*
	SharedPointer<int> sp(new int (10));  
	SharedPointer<int> s2 = sp;  
	
	std::cout << sp.use_count() << '\n';
	std::cout << s2.use_count() << '\n';
	
	sp.reset (new int);
	*sp=20;
	std::cout << *sp << '\n';
	std::cout << *s2 << '\n';
	
	std::cout << sp.use_count() << '\n';
	std::cout << s2.use_count() << '\n';
	
	sp.reset();          
	std::cout << sp.get() << '\n';
	std::cout << sp.use_count() << '\n';
	*/
	
	/* //SWAP
	
	SharedPointer<int> foo (new int(10));
	SharedPointer<int> bar (new int(20));
	SharedPointer<int> bar2(bar);
	
	std::cout << "*foo: " << *foo << " count: "<< foo.use_count()<<'\n';
	std::cout << "*bar: " << *bar << " count: "<< bar.use_count()<<'\n';
	std::cout << "*bar2: " << *bar2 << " count: "<< bar2.use_count()<<"\n\n";
	
	foo.swap(bar);
	
	std::cout << "*foo: " << *foo << " count: "<< foo.use_count()<<'\n';
	std::cout << "*bar: " << *bar << " count: "<< bar.use_count()<<'\n';
	std::cout << "*bar2: " << *bar2 << " count: "<< bar2.use_count()<<'\n'; 
	*/
		
	/* //DESTRUCTOR
	
	SharedPointer<Counter> foo (new Counter);
	SharedPointer<Counter> bar (new Counter);
	SharedPointer<Counter> foo2 (new Counter);
	SharedPointer<Counter> p1(foo);
	
	foo->value = 10;
	
	std::cout << counter_helper << std::endl; */
	
	return 0;
}

