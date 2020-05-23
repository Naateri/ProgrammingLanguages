#include <vector>
#include <iostream>

class shared_ptr_base{
public:
	int count;
	void* value; //pointer of multiple types, casted as needed
	int id;
};

std::vector<shared_ptr_base*> shared_pointers; //stores pointers
int cur_id = 0;
	
template <class T>
class SharedPointer: public shared_ptr_base{
	
private:
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
	
	void update_counts(){ //when resetting a pointer
		//or deleting it
		for(int i = 0; i < shared_pointers.size(); i++){
			if ((T*)shared_pointers[i]->value == (T*)this->value && shared_pointers[i] != this){
				shared_pointers[i]->count = shared_pointers[i]->count-1;
			}
		}
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
        
	SharedPointer() {
		this->value = 0;
		this->count = 0;
		this->id = cur_id++;
	}
	SharedPointer(T * new_object) {
		this->value = new_object;
		this->id = cur_id++;
		int index;
		if (find_pointer(index)){
			this->count = shared_pointers[index]->count;
		} else {
			this->count = 1;
		}
		shared_pointers.push_back(this);
	}
	SharedPointer(const SharedPointer & other) {
		this->id = cur_id++;
		this->value = (T*)other.value;
		int index;
		if (find_pointer(index)){
			this->count = shared_pointers[index]->count;
		} else {
			this->count = 1;
		}
		shared_pointers.push_back(this);
	}
	
	~SharedPointer(){
		int index;
		index = find_by_id(); //to erase the correct
		//shared pointer instance from the vector
		if (index == -1){
			//Pointer not found
			return;
		}
		if (this->count == 0){ //not used by anyone, we simply erase
			shared_pointers.erase(shared_pointers.begin() + index);
		}
		else if (this->count == 1){ //calling object destructor
			shared_pointers.erase(shared_pointers.begin() + index);
			delete (T*)this->value;
		} else {
			shared_pointers.erase(shared_pointers.begin() + index);
			update_counts();
			this->count--;
		}
	}
	
	SharedPointer &operator=(const SharedPointer &other) {
		return *this;
	}

	T& operator*() const {
		T* cur_val = (T*)value;
		return *cur_val;
	}
	  
	T* operator->() const {
		return (T*)value;
	}
	  
	operator bool() const {
		if (this->value == 0) return false;
		else return true;
	}
	  
	int use_count() const{
		return this->count;
	}
	  
	void swap(SharedPointer& A){
		T* temp;
		int temp_count;
		
		temp = (T*)this->value;
		this->value = A.value;
		A.value = (T*)temp;
		
		temp_count = this->count;
		this->count = A.count;
		A.count = temp_count;
	}
	void reset(){
		/* Object becomes empty.*/
		update_counts();
		this->value = 0;
		this->count = 0;
	}
	void reset (T* object){
		/* the shared_ptr acquires ownership of object with a use count of 1. */
		update_counts();
		
	    this->value = object;
		this->count = 1;
	}
	T* get() const{
		/* The stored pointer points to the object the shared_ptr object dereferences t.*/
		return (T*)value;
	}
	  
	bool unique() const{
	    /* Returns whether the shared_ptr object does not share ownership
	    over its pointer with other shared_ptr objects (i.e., it is unique).
	    Empty pointers are never unique (as they do not own any pointers.*/ 
		if (this->count == 1) return true;
		else return false;
	}
	    
};
