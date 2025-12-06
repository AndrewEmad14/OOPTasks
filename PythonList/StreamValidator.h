#ifndef STREAM_VALIDATOR_H
#define STREAM_VALIDATOR_H
#include <string>
#define DEFAULTVAL 0
class StreamValidator{

    public:
    static bool isEmpty(std::string stream);
    static bool CastToIntger(std::string stream,int &number);
    static bool CastToDouble(std::string stream,double &number);
    static bool CastToChar(std::string stream,char &character);
    static int  getNumberOfInput(std::string stream);
};




#endif // VALIDATOR
