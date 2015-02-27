#include "CRam.h"

CRam::CRam()
: mRamDataCapacity("no data")
{
    //ctor
}
void CRam::getData(char dataType)
{
    if(dataType == 'k' || dataType == 'K')
    {
        FILE* pipe = popen(this->mPathRamData.c_str(), "r");
        if (!pipe) return;
        char buffer[128]{};
        std::string result = "";
        while(!feof(pipe)) {
            if(fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
        pclose(pipe);
        std::string resultNumber = result.substr(17,result.length());
        this->mRamDataCapacity = resultNumber;
    }else if(dataType == 'm' || dataType == 'M')
    {
         FILE* pipe = popen(this->mPathRamData.c_str(), "r");
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
        onlyNumber += mPostMbPostfix;
        this->mRamDataCapacity = onlyNumber;
    }else if(dataType == 'G' || dataType == 'g')
    {
         FILE* pipe = popen(this->mPathRamData.c_str(), "r");
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
        onlyNumber += mPostGbPostfix;
        this->mRamDataCapacity = onlyNumber;
    }
}
std::string CRam::getSpecificLine(int line, std::string stringCheked)
{
    std::istringstream stream(stringCheked);
    std::string buffer = "";
    std::string searched = "";
    int i = line;
     while (std::getline(stream, buffer)) {
        if(i == line)
        {
        	searched = line;
        	break;
        }
        i++;
    }
    return searched;
}
CRam::~CRam()
{
    //dtor
}
