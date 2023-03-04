#ifndef MYFILEEXTENSION
#define MYFILEEXTENSION

#include<iostream>
#include<string>
#include<sstream>

class MyFileExtension {
	
public:
	static MyFileExtension* getInstance();

	~MyFileExtension();

	bool CreateFile(const std::string iPath);
	std::string ReadFile(const std::string iPath);
	bool SaveFile(const std::string iPath, const std::string iText);

private:
	MyFileExtension();
	MyFileExtension(const MyFileExtension& obj);
	MyFileExtension& operator=(const MyFileExtension& obj);

	static MyFileExtension* myFileExtensionInstance;

private:
	void DecodeEncodeLine(std::string& ioLine);
	//void DecodeLine(std::string& ioLine);
};

#endif // !MYFILEEXTENSION
