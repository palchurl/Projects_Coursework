#include <iostream>
#include "AudioProcessor.h"
#include <vector>
using namespace std;

int main() {
    std::cout<< "Compress "<<std::endl;
    vector<short> audio = {1, 4, 25, 15, 0, -7, -40, 10};
    vector<short> ayw = {4};
    vector<short> ay = {25};
    vector<short> ayyy = {-5};
    vector<short> aywee = {0};
    vector<short> sais = {-6,-90,2,4,40 };
    vector<short> saise = {0,0,0,0,0};
    AudioProcessor a;
    
    std::cout << "{},4,5 ";
    a.Compress({}, 4,5);
    a.Compress(audio, 10, 1.5); //1  4  20  13  0  -7  -30  10  
    a.Compress(audio, 0, 2);      //1  2  13  8  0  -4  -20  5  
    a.Compress(audio, 2, 1);      //1  4  25  15  0  -7  -40  10  
    a.Compress(audio, 2, 5);      //1  2  7  5  0  -3  -10  4  

    a.Compress(ayw, 10, 1.5 );  //4 *
    a.Compress(ayw, 2, 1);      //4 
    a.Compress(ayw, 2, 5);      //2

    a.Compress(ay, 10, 1.5);    //20
    a.Compress(ay, 2, 1);       //25
    a.Compress(ay, 2, 5);       //7

    a.Compress(ayyy, 10, 1.5);    //-5 *
    a.Compress(ayyy, 2, 1);       //-5
    a.Compress(ayyy, 2, 5);       //-3

    a.Compress(aywee, 10, 1.5 );  //0 *
    a.Compress(aywee, 2, 1);      //0 *

    a.Compress(sais, 10, 1.5);    //-6  -63  2  4  30 
    a.Compress(sais, 2, 1);       //-6  -90  2  4  40  
    a.Compress(sais, 2, 5);       //-3  -20  2  2  10  
    
    a.Compress(saise, 10, 1.5);    //0  0  0  0  0*
    a.Compress(saise, 2, 1);       //0  0  0  0  0*
    a.Compress(saise, 2, 5);       //0  0  0  0  0
    a.Compress(saise, 0, 5);       //0  0  0  0  0
    a.Compress(saise, 0, 2);       //0  0  0  0  0

    //a.Compress(audio, -1, 2);
    //a.Compress(audio, 1, -2);
    //a.Compress(audio, -1, -2);
    //a.Compress(audio, 2, 0);

    std::cout<< "CutOutSilence "<<std::endl;
    vector<short> audi= {1, -3, 10, 25, 56, -1, -2, -16, -20, -8, -1, 1, 7, 12};
    vector<short> audim= { 1, 2, 5, 6, -4, 4, 10, 0, -2, -5, -4};
    vector<short> hae = {1,0,1,0, -1};
    vector<short> haew = {-9,0,9,1,15,19, -5,0,7, 20,-9,0,4,-6,-10,-2,0,2,5};
    vector<short> ghaa = {0,0};
    vector<short> ghaasa = {0,0,0,0};
    vector<short> ghaasaae = {10};
    vector<short> ghaasaaes = {-5};

    AudioProcessor aa;
    aa.CutOutSilence(audi, 10, 3);  //25  56  -1  -2  -16  -20  12  
    aa.CutOutSilence(audim, 5, 3);  //6  -4  4  10  
    std::cout<<std::endl;

    std::cout << "hae,1,5 ";
    aa.CutOutSilence(hae, 1, 5); //empty
    std::cout<<std::endl;
    std::cout << "{}},1,5 ";
    aa.CutOutSilence({}, 1,5);//empty
    std::cout<<std::endl;
    aa.CutOutSilence(haew, 9, 4); //15  19  -5  0  7  20  -10 
    aa.CutOutSilence(hae, 1, 6);  //1  0  1  0  -1  (silLen > audio.size())
    aa.CutOutSilence(hae, 0, 2);  //1  0  1  0  -1
    aa.CutOutSilence(audi, 0, 1);   //1  -3  10  25  56  -1  -2  -16  -20  -8  -1  1  7  12  
    aa.CutOutSilence(audi, 16, 1);  //25  56  -20  
    aa.CutOutSilence(ghaa, 10, 3);   //0 0 
    aa.CutOutSilence(ghaasa, 10, 3);   //
    aa.CutOutSilence(ghaasa, 10, 5);   //0 0 0 0
    aa.CutOutSilence(ghaasaae, 15, 1);//
    aa.CutOutSilence(ghaasaae, 15, 2);//10
    aa.CutOutSilence(ghaasaae, 5, 2);//10
    aa.CutOutSilence(ghaasaae, 15, 1);//

     aa.CutOutSilence(ghaasaaes, 5, 1);//
     aa.CutOutSilence(ghaasaaes, 2, 2);//-5
     aa.CutOutSilence(ghaasaaes, 6, 2);//-5

    //aa.CutOutSilence(audi, -1, 2);
    //aa.CutOutSilence(audi, 1, 0);
    //aa.CutOutSilence(audi, 1, -2);

    std::cout<< "Stretch Twice "<<std::endl;
    vector<short> au = { 1, 2, 6, -5, -10, 1 };
    vector<short> aumixx = {0,0,0,0,0};
    vector<short> aujs = { 1, 4};
    vector<short> aujss = { 100};
    vector<short> aujsse = { -9};
    vector<short> aujssea = {-9,1,2,-10,7,-6,0,1};
    AudioProcessor aaaa;
    cout << "stretchtwice {}:";
    aaaa.StretchTwice({});
    std::cout<<std::endl;
    aaaa.StretchTwice(au);  //1  2  2  4  6  1  -5  -8  -10  -5  1  
    aaaa.StretchTwice(aumixx);   //0  0  0  0  0  0  0  0  0  
    aaaa.StretchTwice(aujs);    // 1 3 4
    aaaa.StretchTwice(aujss);   //100
    aaaa.StretchTwice(aujsse);  //-9
    aaaa.StretchTwice(aujssea); //-9  -4  1  2  2  -4  -10  -2  7  1  -6  -3  0  1  1  

    std::cout<<std::endl;

    std::cout<< "Normalize "<<std::endl;
    vector<short> aus = {1, 3, -2, 5, -4, 0};
    vector<short> ausss = {-1, -30, 3, 15, 16, -7};
    vector<short> aumi = {0,0,0,0,0,0,0,0,0,0};
    vector<short> aumiwq = {0,0};
    vector<short> aumjsa = {19};
    AudioProcessor ap;
    ap.Normalize({}, 1);
    ap.Normalize(aus, 10);      //2  6  -4  10  -8  0  
    ap.Normalize(ausss, 20);    //-1  -20  2  10  11  -5  
    ap.Normalize(aumi, 5);     //0  0  0  0  0  0  0  0  0  0  
    ap.Normalize(aumiwq,1);     //0  0
    ap.Normalize(aumjsa, 10);   //10
    cout << "A"<<endl;
    //ap.Normalize(aus, 0);
    //ap.Normalize(aus, -1);
    return 0;
}

//g++ -std=c++11 -fsanitize=address AudioProcessor.cpp test.cpp -o pi 
//g++ -std=c++11 -fsanitize=address AudioProcessor.cpp main.cpp -o pi