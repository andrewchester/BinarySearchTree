#include <iostream>
#include "tree.h"

int main(){
	Tree t = Tree();
	char* input = new char[10];
	while(true){
		std::cout << "Enter command(input, exit, print, output): ";
		std::cin.get(input, 10);
		std::cin.clear();
		std::cin.ignore(100, '\n');

		if(strcmp(input, "input") == 0){
			std::cout << "File or Manual input(file,manual): ";
			std::cin.get(input, 10);
			std::cin.clear();
			std::cin.ignore(100, '\n');

			if(strcmp(input, "file") == 0){
				char* filepath = new char[200];
				std::cout << "Enter path: ";
				std::cin.get(filepath, 200);
				std::cin.clear();
				std::cin.ignore(100, '\n');

				from_file(&t, filepath);
				delete[] filepath;
			}else if(strcmp(input, "manual") == 0){
				char* number = new char[10];
				while(true){
					std::cout << "Enter number(type exit to leave): ";
					std::cin >> number;
					std::cin.clear();
					std::cin.ignore(100, '\n');

					if(strcmp(number, "exit") == 0)
						break;
					t.insert(atoi(number), true);
				}
				delete[] number;
			}
		}else if(strcmp(input, "exit") == 0){
			break;
		}else if(strcmp(input, "print") == 0){
			t.print(true);
		}else if(strcmp(input, "output") == 0){
			t.print(false);
		}else{
			std::cout << "Not sure what that command is..." << std::endl;
		}
	}
	delete[] input;
	return 0;
}