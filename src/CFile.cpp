#include "../include/CFile.h"

CFile::CFile(std::string path)
	: mPath(path)
{

}
void CFile::readData(char datatype)
{
	if(datatype == 'b' || datatype == 'B')
	{
		LOG(INFO) << "Getting stats of file at: " << mPath;
		struct stat statistics;
		int returnValue = stat(mPath.c_str(), &statistics);
		// std::cout << (float)statistics.st_size << std::endl;
		float fileSize = (float)statistics.st_size;
		// std::cout << fileSize << std::endl;
		LOG(INFO) << "File size: " << (float)fileSize;
	}
	else if(datatype == 'k' || datatype == 'K')
	{
		LOG(INFO) << "Getting stats of file at: " << mPath;
		struct stat statistics;
		int returnValue = stat(mPath.c_str(), &statistics);
		float fileSize = (float)statistics.st_size;
		// std::cout << (float)statistics.st_size << std::endl;		
		fileSize /= (float)1024.f;
		// std::cout << (float)fileSize << std::endl;
		LOG(INFO) << "File size: " << (float)fileSize;
	}else if (datatype == 'm' || datatype == 'M')
	{
		LOG(INFO) << "Getting stats of file at: " << mPath;
		struct stat statistics;
		int returnValue = stat(mPath.c_str(), &statistics);
		// std::cout << (float)statistics.st_size << std::endl;
		float fileSize = (float)statistics.st_size;
		fileSize /= (float)1048576.f;
		// std::cout << (float)fileSize << std::endl;
		LOG(INFO) << "File size: " << (float)fileSize;
	}else if(datatype == 'G' || datatype == 'g')
	{
		LOG(INFO) << "Getting stats of file at: " << mPath;
		struct stat statistics;
		int returnValue = stat(mPath.c_str(), &statistics);
		// std::cout << (float)statistics.st_size << std::endl;
		float fileSize = (float)statistics.st_size;
		fileSize /= (float)1073741824.f;
		// std::cout << (float)fileSize << std::endl;
		LOG(INFO) << "File size: " << (float)fileSize;
	}

}

CFile::~CFile()
{

}