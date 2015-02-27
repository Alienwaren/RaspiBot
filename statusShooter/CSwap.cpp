#include "CSwap.h"

CSwap::CSwap()
{
    //ctor
}
void CSwap::getData(char dataType)
{
    if(dataType == 'k' || dataType == 'K')
    {
        FILE* pipe = popen(this->mSwapPath.c_str(), "r");
        if (!pipe) return;
        char buffer[128]{};
        std::string result = "";
        while(!feof(pipe)) {
            if(fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
        pclose(pipe);
        std::string resultNumber = result.substr(17,result.length());
        this->mData = resultNumber;
    }else if (dataType == 'm' || dataType == 'M')
    {
        FILE* pipe = popen(this->mSwapPath.c_str(), "r");
        if (!pipe) return;
        char buffer[128]{};
        std::string result = "";
        while(!feof(pipe)) {
            if(fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
        pclose(pipe);
        std::string resultNumber = result.substr(17,result.length());
         std::string onlyNumber = "";
        for (int i = 0; i < resultNumber.length(); i++)
        {
            if(isdigit(resultNumber[i]))
            {
                onlyNumber += resultNumber[i];
            }
        }
        float mbs = atoi(onlyNumber.c_str());
        mbs /= 1000;
        std::ostringstream stream;
        stream << mbs;
        onlyNumber = stream.str();
        onlyNumber += this->mPostMbPostfix;
        this->mData = onlyNumber;
    }else if(dataType == 'g' || dataType == 'G')
    {
        FILE* pipe = popen(this->mSwapPath.c_str(), "r");
        if (!pipe) return;
        char buffer[128]{};
        std::string result = "";
        while(!feof(pipe)) {
            if(fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
        pclose(pipe);
        std::string resultNumber = result.substr(17,result.length());
         std::string onlyNumber = "";
        for (int i = 0; i < resultNumber.length(); i++)
        {
            if(isdigit(resultNumber[i]))
            {
                onlyNumber += resultNumber[i];
            }
        }
        float gbs = atoi(onlyNumber.c_str());
        gbs /= 1000000;
        std::ostringstream stream;
        stream << gbs;
        onlyNumber = stream.str();
        onlyNumber += this->mPostGbPostfix;
        this->mData = onlyNumber;
    }
}
CSwap::~CSwap()
{
    //dtor
}
