#include <iostream>
#include <string>

typedef std::string str;

int main(int argc, char *argv[]) {
	
	str name[4];
	int age[4];
	float GPA[4];
	str grade_level[4];
	
	name[0] = "Renato";
	age[0] = 20;
	GPA[0] = 3.1;
	grade_level[0] = "undergraduate";
	name[1] = "Juan";
	age[1] = 25;
	GPA[1] = -3.2;
	grade_level[1] = "freshmen";
	name[2] = "Manu";
	age[2] = 20;
	GPA[2] = 4.4;
	grade_level[2] = "freshmen";
	
	for(int i = 0; i < 3; i++){
		std::cout << "Name: " << name[i] << std::endl <<
			"Age: " << age[i] << std::endl <<
			"GPA: " << GPA[i] << std::endl <<
			"Grade level: " << grade_level[i] << std::endl << std::endl;
	}
	
	return 0;
}
