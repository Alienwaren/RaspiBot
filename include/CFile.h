#ifndef CFILE_H
#define CFILE_H
#include <string>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <glog/logging.h>
class CFile
{
public:
	CFile(std::string path);
	~CFile();
	double getFileSize() 
	{ 
		return fileSize;
	}
	void readData(char datatype);
private:
	std::string mPath;
	double fileSize;
	/* data */
};
#endif