#ifndef CTEMPERATURE_H
#define CTEMPERATURE_H
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
class CTemperature
{
    public:
        CTemperature();
        virtual ~CTemperature();
        std::string  GetmStringTemp() { return mStringTemp; }
        void getTemperatureData(char dataType);
    protected:
    private:
        std::string mStringTemp;
        const std::string mTempPath = "/opt/vc/bin/vcgencmd measure_temp";
        const int maxDigits = 2;
};

#endif // CTEMPERATURE_H
