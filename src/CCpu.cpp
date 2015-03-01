#include "../include/CCpu.h"

CCpu::CCpu()
    : mCpuFreqString(""), mYamlFreqString("")
{
    //ctor
}
void CCpu::ReadCpuData(char returnType)
{
    if(returnType == 'k' || returnType == 'K')
    {
        LOG(INFO) << "Reading data as Hz";
        int fd = open(mCpuPath.c_str(), O_RDONLY);
        ssize_t readBytes;
        LOG(INFO) << "Opening cpu file...";
        if(fd != -1)
        {
            LOG(INFO) << "Opening successfull";
            char buffer[10]{};
            readBytes = read(fd, &buffer, sizeof(buffer));
            if(readBytes > -1)
            {
                std::string frequency(buffer);
                frequency.erase(std::remove(frequency.begin(), frequency.end(), '\n'), frequency.end());
                frequency += mFreqPostfix;
                this->mCpuFreqString = frequency;
                close(fd);
                LOG(INFO) << "Closing file";
            }
        }else
        {
            LOG(WARNING) << "Invalid file descriptor, cannot open file";

        }

    }else if(returnType == 'm' || returnType == 'M')
    {
        LOG(INFO) << "Reading data as MHz";
        int fd = open(mCpuPath.c_str(), O_RDONLY);
        ssize_t readBytes;
        LOG(INFO) << "Opening cpu file...";
        if(fd != -1)
        {
            LOG(INFO) << "Opening successfull";
            char buffer[10]{};
            readBytes = read(fd, &buffer, sizeof(buffer));
            if(readBytes > -1)
            {
                std::string frequency(buffer);
                frequency.erase(std::remove(frequency.begin(), frequency.end(), '\n'), frequency.end());
                int temp = atoi(frequency.c_str());
                int mhz = temp/1000;
                std::ostringstream stream;
                stream << mhz;
                std::string mhzString = stream.str();
                this->mCpuFreqString = mhzString + this->mMhzFreqPostFix;
                close(fd);
                LOG(INFO) << "Closing file";
            }
        }else
        {
            LOG(WARNING) << "Invalid file descriptor, cannot open file";

        }
    }else if(returnType == 'G' || returnType == 'g')
    {
        LOG(INFO) << "Reading data as MHz";
        int fd = open(mCpuPath.c_str(), O_RDONLY);
        ssize_t readBytes;
        LOG(INFO) << "Opening cpu file...";
        if(fd != -1)
        {
            LOG(INFO) << "Opening successfull";
            char buffer[10]{};
            readBytes = read(fd, &buffer, sizeof(buffer));
            if(readBytes > -1)
            {
                std::string frequency(buffer);
                frequency.erase(std::remove(frequency.begin(), frequency.end(), '\n'), frequency.end());
                float temp = atoi(frequency.c_str());
                float ghz = temp/1000000;
                std::ostringstream stream;
                stream << ghz;
                std::string ghzString = stream.str();
                this->mCpuFreqString = ghzString + this->mGhzFreqPostFix;
                close(fd);
                LOG(INFO) << "Closing file";
            }
        }else
        {
            LOG(WARNING) << "Invalid file descriptor, cannot open file";

        }
    }else if(returnType == 'n' || returnType == 'N')
    {
        LOG(INFO) << "Reading data as MHz without suffix";
        int fd = open(mCpuPath.c_str(), O_RDONLY);
        ssize_t readBytes;
        LOG(INFO) << "Opening cpu file...";
        if(fd != -1)
        {
            LOG(INFO) << "Opening successfull";
            char buffer[10]{};
            readBytes = read(fd, &buffer, sizeof(buffer));
            if(readBytes > -1)
            {
                std::string frequency(buffer);
                frequency.erase(std::remove(frequency.begin(), frequency.end(), '\n'), frequency.end());
                int temp = atoi(frequency.c_str());
                int mhz = temp/1000;
                std::ostringstream stream;
                stream << mhz;
                std::string mhzString = stream.str();
                this->mCpuFreqString = mhzString;
                close(fd);
                LOG(INFO) << "Closing file";
            }
        }else
        {
            LOG(WARNING) << "Invalid file descriptor, cannot open file";

        }
    }
}
void CCpu::readCpuDataAsYaml(char returnType)
{
    this->ReadCpuData(returnType);
    YAML::Node mYamlCreator("conf/test.yml");
    mYamlCreator[this->mCpuYamlKey] = mCpuFreqString;
    std::cout << mYamlCreator[mCpuYamlKey].as<std::string>() << std::endl;
}
CCpu::~CCpu()
{
    //dtor
}
