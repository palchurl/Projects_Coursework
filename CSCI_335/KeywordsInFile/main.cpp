#include "KeywordsInFile.h"
#include <fstream>          //file stream
#include <iostream>
#include <unordered_map>    //Map
//#include <fstream>          //file stream
#include <string>
#include <vector>
using namespace std;
//remember to put std:: 
int main() {
    // Parameterized Constructor
    KeywordsInFile obj("filename_with_keywords.txt", "filename_with_text.txt");
    //KeywordFoun
    cout << obj<<endl;
    cout << obj.KeywordFound("moon")<<endl;     //1
    cout << obj.KeywordFound("system")<<endl;   //1
    cout << obj.KeywordFound("systems")<<endl;  //0
    //KeywordInLine
    cout << obj.KeywordInLine("sun",1 )<<endl;      //9
    cout << obj.KeywordInLine("moon",4 )<<endl;     //4
    cout << endl;
    //cout << obj.KeywordInLine("suns",1 )<<endl;
    //cout << obj.KeywordInLine("sun",2 )<<endl;
    //cout << obj.KeywordInLine("sun",0 )<<endl;
    //cout << obj.KeywordInLine("sun",-1 )<<endl;
    //cout << obj.KeywordInLine("sun",5 )<<endl;

    //TotalOccurrences
    cout << obj.TotalOccurrences("moon")<<endl;       //9
    cout << obj.TotalOccurrences("the")<<endl;       //12

    //cout << obj.TotalOccurrences("system");
    cout << endl;
    cout << obj.TotalOccurrences("The");              //4
    //cout << obj.TotalOccurrences("suns");
    cout <<endl;
    //Operator << overload
    cout << "operator <<"<<endl;
    cout <<endl;
    

    KeywordsInFile obj1("k.txt", "t.txt");

    cout << obj1;
    cout << obj1.KeywordFound("hello")<<endl;     //1
    cout << obj1.KeywordFound("is")<<endl;       //0
    cout << obj1.KeywordFound("systems")<<endl;  //0
    cout << obj1.TotalOccurrences("hello")<<endl;       //1
    cout << obj1.TotalOccurrences("name")<<endl;       //6
    cout << obj1.TotalOccurrences("Name")<<endl;       //1
    cout << obj1.TotalOccurrences("ok")<<endl;       //0
    cout << obj1.KeywordInLine("hello",1 )<<endl;      //1
    cout << obj1.KeywordInLine("name",2 )<<endl;      //2
    cout << obj1.KeywordInLine("name",4)<<endl;      //4

    cout << "A"<<endl;
    return 0;
}
//A