#include <iostream>
#include <string>

typedef std::string str;
 
struct student{
	str name;
	int age;
	float GPA;
	str grade_level;
	void print(){
		std::cout << "Name: " << this->name << std::endl;
		std::cout << "Age: " << this->age << std::endl;
		std::cout << "GPA: " << this->GPA << std::endl;
		std::cout << "Grade level: " << this->grade_level << std::endl;
	}
};

int main(int argc, char *argv[]) {
	struct student my_students[4];
	my_students[0].name = "Renato";
	my_students[0].age = 20;
	my_students[0].GPA = 3.1;
	my_students[0].grade_level = "undergraduate";
	my_students[1].name = "Juan";
	my_students[1].age = 25;
	my_students[1].GPA = -3.2;
	my_students[1].grade_level = "freshmen";
	my_students[2].name = "Manu";
	my_students[2].age = 20;
	my_students[2].GPA = 4.4;
	my_students[2].grade_level = "freshmen";
	
	for(int i = 0; i < 3; i++){
		my_students[i].print();
		std::cout << '\n';
	}
	
	return 0;
}
