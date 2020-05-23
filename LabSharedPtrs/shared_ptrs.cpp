#include <iostream>
#include <vector>
using namespace std;

class shared_ptr_base{
public:
	int count;
	void* value;
	int id;
};

vector<shared_ptr_base*> shared_pointers;
int cur_id = 0;

template <class T>
class my_shared_ptr : public shared_ptr_base{
private:
	bool new_ptr;
	bool find_pointer(int& index){
		bool ret = false;
		for(int i = 0; i < shared_pointers.size(); i++){
			if ((T*)shared_pointers[i]->value == (T*)this->value){
				index = i;
				shared_pointers[i]->count++;
				ret = true;
			}
		}
		return ret;
	}
	
	int find_by_id(){
		for(int i = 0; i < shared_pointers.size(); i++){
			if (this == shared_pointers[i]){
				return i;
			}
		}
		return -1;
	}
	
public:
	
	my_shared_ptr(){
		this->value = NULL;
		this->count = 0;
		this->id = cur_id++;
		this->new_ptr = false;
	}
	
	my_shared_ptr(T* val){
		this->value = val;
		this->id = cur_id++;
		int index;
		if (find_pointer(index)){
			this->count = shared_pointers[index]->count;
			this->new_ptr = false;
		} else {
			this->count = 1;
			new_ptr = true;
		}
		shared_pointers.push_back(this);
	}
	
	my_shared_ptr(const my_shared_ptr& val){
		this->id = cur_id++;
		this->value = (T*)val.value;
		int index;
		if (find_pointer(index)){
			this->count = shared_pointers[index]->count;
			this->new_ptr = false;
		} else {
			this->count = 1;
			new_ptr = true;
		}
		shared_pointers.push_back(this);
	}
	
	~my_shared_ptr(){
		int index;
		if (this->count <= 1){
			index = find_by_id();
			shared_pointers.erase(shared_pointers.begin() + index);
		} else {
			index = find_by_id();
			shared_pointers.erase(shared_pointers.begin() + index);
			this->count--;
		}
	}
	
	int use_count() { return this->count; }
	
	void swap(const my_shared_ptr& A){
		T* my_val = (T*) this->value;
		T* his_val = (T*) A.value;
		T temp;
		
		temp = *my_val;
		*my_val = *his_val;
		*his_val = temp;
	}
	
	T* get(){
		return (T*)value;
	}
	void reset(T* val = 0){
		if (val == 0){
			this->value = NULL;
		} else this->value = val;
	}
	
	operator bool() const{
		if (this->value == NULL) return false;
		else return true;
	}
	
	bool unique(){
		if (this->count == 1) return true;
		else return false;
	}
	
	T& operator*() const{
		T* cur_val = (T*)value;
		return *cur_val;
	}
	
	T* operator->() const{
		//T* cur_val = (T*)value;
		//return *cur_val;
		return (T*)value;
	}
	
	T& operator=(const my_shared_ptr& A){
		return *this;
	}
};

struct C {int data;};

struct test{
	int data;
	float xd;
	char s;
};

int main(int argc, char *argv[]) {
	
	/*int p[7] = {1,2,3,4,5,6,7};
	
	my_shared_ptr<int> p1;
	my_shared_ptr<int> p2 (new int);
	my_shared_ptr<int> p3 (p2);
	
	my_shared_ptr<C> p4 (new C);
	
	my_shared_ptr<int> p5(p);
	my_shared_ptr<int> p6(p+1);
	
	cout << p3.use_count() << endl;	*/
	
	my_shared_ptr<C> p (new C);
	p->data = 5;
	std::cout << p->data << std::endl;
	
	my_shared_ptr<test> p1 (new test);
	p1->data = 5;
	p1->xd = 5.5;
	p1->s = 'c';
	
	std::cout << p1->data << ' ' << p1->xd << ' ' << p1->s << std::endl;
	
	
	/*
	my_shared_ptr<int> a (new int);
	
	cout << "a: " << a.get() << endl;
	
	*a = 20;
	my_shared_ptr<int> b(a);
	
	cout << *a << endl;
	cout << "use count: " << b.use_count() << endl;
	*/
	return 0;
}

