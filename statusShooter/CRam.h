#ifndef CRAM_H
#define CRAM_H
#include <string>
#include <glog/logging.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
#include <errno.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <stdio.h>
#include <algorithm>
class CRam
{
    public:
        CRam();
        virtual ~CRam();
        std::string getRamDataCapacity()
        {
            return this->mRamDataCapacity;
        }
        void getData(char dataType);
        std::string getSpecificLine(int line, std::string stringCheked);
    protected:
    private:
        std::string mRamDataCapacity;
        const std::string mPathRamData = "cat /proc/meminfo | sed -n 2p";
        const std::string mPostMbPostfix = " MB";
        const std::string mPostGbPostfix = " GB";
};

#endif // CRAM_H
