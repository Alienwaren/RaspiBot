#include "../include/CTemperature.h"

CTemperature::CTemperature()
: mStringTemp("")
{
    //ctor
}
void CTemperature::getTemperatureData(char dataType)
{
        FILE* pipe = popen(this->mTempPath.c_str(), "r");
        if (!pipe) return;
        char buffer[128]{};
        std::string result = "";
        while(!feof(pipe)) {
            if(fgets(buffer, 128, pipe) != NULL)
                result += buffer;
        }
        pclose(pipe);
        std::string number = "";
        int numbers = 0;
        for(int i = 0; i < result.length(); i++)
        {
            if(numbers == maxDigits)
            {
                break;
            }
            if(isdigit(result[i]))
            {
                number += result[i];
                numbers++;
            }

        }
        number += "C";
        this->mStringTemp = number;
}
CTemperature::~CTemperature()
{
    //dtor
}
