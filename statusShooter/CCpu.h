#ifndef CCPU_H
#define CCPU_H
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
#include <yaml-cpp/yaml.h>
class CCpu
{
    public:
        CCpu();
        virtual ~CCpu();
        std::string GetCpuFreqString()
        {
            return mCpuFreqString;
        }
        void SetCpuFreqString(int val) { mCpuFreqString = val; }
        void ReadCpuData(char returnType);
        void readCpuDataAsYaml(char returnType);
    protected:
    private:
        std::string mCpuFreqString;
        const std::string mCpuPath = "/sys/devices/system/cpu/cpu0/cpufreq/cpuinfo_cur_freq";
        const std::string mFreqPostfix = " Hz";
        const std::string mMhzFreqPostFix = " Mhz";
        const std::string mGhzFreqPostFix = " Ghz";
        const std::string mCpuYamlKey = "CPU";
        std::string mYamlFreqString;
        
};

#endif // CCPU_H
