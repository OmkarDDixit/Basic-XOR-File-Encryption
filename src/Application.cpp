#include "MyFileExtension.h"

void Create();
void Read();
void Edit();

int main()
{
	char i = 1;

	while ('S' != i)
	{
		std::cout << "Press :" << std::endl;
		std::cout << "C : To Create OD File" << std::endl;
		std::cout << "R : To Read OD File" << std::endl;
		std::cout << "E : To Edit OD File" << std::endl;
		std::cout << "S : To Stop the Application" << std::endl;

		std::cin >> i;
		std::cout << std::endl;

		switch (i)
		{
		case 'C':
			Create();
			break;

		case 'R':
			Read();
			break;

		case 'E':
			Edit();
			break;

		case 'S':
			std::cout << "Bye Bye!!" << std::endl;
			break;

		default:
			std::cout << "Wrong Input" << std::endl;
			break;
		}
	}
}

void Read() {
	std::cout << "Type below the path of the file to Read" << std::endl;
	std::string path;
	std::cin >> path;
	std::cout << std::endl;
	MyFileExtension currentFile= MyFileExtension(path);
	currentFile.ReadFile();
}

void Create() {
	std::cout << "Type below the path where you want to create your file" << std::endl;
	std::string path;
	std::cin >> path;
	std::cout << std::endl;
	MyFileExtension currentFile = MyFileExtension(path);
	currentFile.CreateFile();
}

void Edit() {
	std::cout << "Type below the path of the file you want to Edit" << std::endl;
	std::string path;
	std::cin >> path;
	std::cout << std::endl;
	MyFileExtension currentFile = MyFileExtension(path);
	currentFile.EditFile();
}