
#include "StreamValidator.h"
using namespace std;
bool StreamValidator:: isEmpty(string stream){
      return stream.empty();
}


bool StreamValidator:: CastToIntger(string stream,int &number){
        int startIndex = DEFAULTVAL;
        if (stream[0] == '-') {
            if (stream.length() == 1) {
                return false;
            }
            startIndex = 1;
        }

        for (int i = startIndex; i < stream.length(); i++) {
            if (stream[i] < '0' || stream[i] > '9') {
                return false;
            }
        }
        number = stoi(stream);
        return true;

}
bool StreamValidator::CastToDouble(std::string stream,double &number){
        int startIndex = DEFAULTVAL;
        int decimalPointFlag=DEFAULTVAL;
        int digitCount=DEFAULTVAL;
        if (stream[0] == '-') {
            if (stream.length() == 1) {
                return false;
            }
            startIndex = 1;
        }
        for (int i = startIndex; i < stream.length(); i++) {
            if(stream[i]=='.'){
                if(decimalPointFlag==1){
                    return false;
                }else{
                    decimalPointFlag=1;
                }
            }else if (stream[i] < '0' || stream[i] > '9'){
                return false;
            }else{
                digitCount++;
            }

        }
        if(digitCount==0)return false;
        number = stod(stream);
        return true;


}
