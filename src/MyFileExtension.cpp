#include"MyFileExtension.h"
#include<fstream>

MyFileExtension::MyFileExtension()
{
}

//MyFileExtension& MyFileExtension::operator=(const MyFileExtension& obj)
//{
//	// TODO: insert return statement here
//}

MyFileExtension* MyFileExtension::getInstance()
{
	if (NULL == myFileExtensionInstance)
	{
		myFileExtensionInstance = new MyFileExtension();
		return myFileExtensionInstance;
	}
	else
	{
		return myFileExtensionInstance;
	}
}

MyFileExtension::~MyFileExtension()
{
}

bool MyFileExtension::CreateFile(const std::string iPath)
{
	bool toReturn = true;

	if (iPath == "" || (iPath.find(":") == std::string::npos))
		return false;

	std::ofstream newFile(iPath);

	newFile.close();

	return toReturn;
}

std::string MyFileExtension::ReadFile(const std::string iPath)
{
	std::string toReturn = "";

	if (iPath == "" || (iPath.find(":") == std::string::npos))
		return toReturn;

	std::string line = "";
	std::ifstream readFile;
	readFile.open(iPath);

	while (std::getline(readFile, line)) {
		DecodeEncodeLine(line);
		toReturn.append(line);
		toReturn.append("\n");
	}

	readFile.close();

	return toReturn;
}

bool MyFileExtension::SaveFile(const std::string iPath, const std::string iText)
{
	bool toReturn = true;

	if (iPath == "" || (iPath.find(":") == std::string::npos))
		return false;
	
	std::string line = "";
	std::ofstream newFile(iPath);
	int ii = 0;
	char character;
	while (ii < iText.size())
	{
		while (ii < iText.size() && iText[ii] != '\n')
		{
			character = iText[ii];
			if(character != 'l')
				character = character ^ 'f';
			line += character;
			ii++;
		}
		ii++;
		//DecodeEncodeLine(line);

		newFile << line << std::endl;
		line.erase();
	}

	newFile.close();

	return toReturn;
}

void MyFileExtension::DecodeEncodeLine(std::string& ioLine)
{
	int i = 0;
	while (i < ioLine.size())
	{
		if('l' != ioLine[i])
			ioLine[i] = ioLine[i] ^ 'f';
		i++;
	}	
}

//void MyFileExtension::DecodeLine(std::string& ioLine)
//{
//	int i = 0;
//	while (i < ioLine.size())
//	{
//		ioLine[i] = ioLine[i] ^ 'f';
//		i++;
//	}
//}
