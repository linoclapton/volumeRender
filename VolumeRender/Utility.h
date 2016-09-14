#pragma once

#include <windows.h>
#include <iostream>

//取高位低位
#define byte unsigned char
#define word short
#define WORD_HI(xxx) ((byte) ((word)(xxx)>>8))
#define WORD_LO(xxx) ((byte) ((word)(xxx)&255))

//返回array大小
#define ARR_SIZE(a) (sizeof((a))/sizeof((a[0])))

namespace Utility{
using namespace std;

class Clock{
private:
    static const int N = 50;
    int index;
    LARGE_INTEGER startCounter[N],frequency,stopCounter[N];
    string text;
public:
    Clock(){
        QueryPerformanceFrequency(&frequency);
        text = "";
        index = 0;
    }
    Clock(string text):text(text){
        QueryPerformanceFrequency(&frequency);
        index = 0;
    }
    void start(){
        QueryPerformanceCounter(&startCounter[++index]);
    }
    void end(string text){
        QueryPerformanceCounter(&stopCounter[index]);
        printf("%s %f\n",text.c_str(),(double)(stopCounter[index].QuadPart - startCounter[index].QuadPart)/frequency.QuadPart);
        index--;
    }
    void end(){
        QueryPerformanceCounter(&stopCounter[index]);
        printf("%s %f\n",text.c_str(),(double)(stopCounter[index].QuadPart - startCounter[index].QuadPart)/frequency.QuadPart);
        index--;
    }
};
}