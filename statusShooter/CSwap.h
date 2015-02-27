#ifndef CSWAP_H
#define CSWAP_H
#include <string>
#include <glog/logging.h>
#include <string>
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

class CSwap
{
    public:
        CSwap();
        virtual ~CSwap();
        std::string GetmData() { return mData; }
        void getData(char dataType);
    protected:
    private:
        std::string mData = "";
        const std::string mSwapPath = "cat /proc/meminfo | sed -n 15p";
        const std::string mPostMbPostfix = " MB";
        const std::string mPostGbPostfix = " GB";
};

#endif // CSWAP_H
