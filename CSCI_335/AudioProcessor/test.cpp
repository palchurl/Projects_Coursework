#include<iostream>
#include<vector>
#include"AudioProcessor.h"

void TestCompress()
{
    AudioProcessor aProc;

    // INPUT 1
    std::vector<short> input{ 1, 2, 5, 6, 10, 0, -2, -5, -6, -8};
    std::vector<short> expected{1, 2, 5, 5, 7, 0, -2, -5, -5, -6};
    auto output{ aProc.Compress(input, 5, 3) };

    if (output != expected)
        std::cout << "bad Compressor! failed on input 1." << std::endl;

    ///////////
    bool exceptonThrown{ false };
    try
    {
        auto util = aProc.Compress({1,2}, -1, 2);
    }
    catch(std::invalid_argument& e)
    {
        exceptonThrown = true;
    }

    if(!exceptonThrown)
        std::cout << "bad Compressor! threshold<0 didn't throw the exception." << std::endl;

    ///////////
    exceptonThrown = false;
    try
    {
        auto util = aProc.Compress({ 1,2 }, 1, 0.5f);
    }
    catch (std::invalid_argument& e)
    {
        exceptonThrown = true;
    }

    if (!exceptonThrown)
        std::cout << "bad Compressor! rate<1 didn't throw the exception." << std::endl;
}

void TestCutOutSilence()
{
    AudioProcessor aProc;

    // INPUT 1
    std::vector<short> input{ 1, 2, 5, 6, 10, 0, -2, -5, -5, -8 };
    std::vector<short> expected{ 1, 2, 5, 6, 10, -8 };
    auto output{ aProc.CutOutSilence(input, 5, 4) };

    if (output != expected)
        std::cout << "bad CutOutSilence! failed on input 1." << std::endl;

    //INPUT 2
    input = { 1, 2, 5, 6, -4, 4, 10, 0, -2, -5, -4};
    expected = { 6, -4, 4, 10 };
    output = aProc.CutOutSilence(input, 5, 3);

    if (output != expected)
        std::cout << "bad CutOutSilence! failed on input 2." << std::endl;

    // INPUT 3
    input = { 1, 2, 5, 6, -4, 4, -2, -5, 10, 0, -4 };
    expected = { 1, 2, 5, 6, 10, 0, -4 };
    output = aProc.CutOutSilence(input, 5, 4);

    if (output != expected)
        std::cout << "bad CutOutSilence! failed on input 3." << std::endl;

    ///////////
    bool exceptonThrown{ false };
    try
    {
        auto util = aProc.CutOutSilence({ 1,2 }, -1, 2);
    }
    catch (std::invalid_argument& e)
    {
        exceptonThrown = true;
    }

    if (!exceptonThrown)
        std::cout << "bad CutOutSilence! silenceLevel<0 didn't throw the exception." << std::endl;

    ///////////
    exceptonThrown = false;
    try
    {
        auto util = aProc.CutOutSilence({ 1,2 }, 1, 0);
    }
    catch (std::invalid_argument& e)
    {
        exceptonThrown = true;
    }

    if (!exceptonThrown)
        std::cout << "bad CutOutSilence! silenceMinLength<1 didn't throw the exception." << std::endl;
}

void TestStretchTwice()
{
    AudioProcessor aProc;

    // INPUT 1
    std::vector<short> input{ 1, 2, 6, -5, -10, 1 };
    std::vector<short> expected{ 1, 2, 2, 4, 6, 1, -5, -8, -10, -5, 1 };
    auto output{ aProc.StretchTwice(input) };

    if (output != expected)
        std::cout << "bad StretchTwice! failed on input 1." << std::endl;

    //////////
    if (aProc.StretchTwice({}) != std::vector<short>{})
        std::cout << "bad StretchTwice! failed on the empty input std::vector." << std::endl;
    
    //////////
    if (aProc.StretchTwice({4}) != std::vector<short>{4})
        std::cout << "bad StretchTwice! failed on the single-element input std::vector." << std::endl;
}

void TestNormalize()
{
    AudioProcessor aProc;

    // INPUT 1
    std::vector<short> input{ 1, 2, -5, 8 };
    std::vector<short> expected{ 2, 3, -8, 12 };
    auto output{ aProc.Normalize(input, 12) };

    if (output != expected)
        std::cout << "bad Normalize! failed on input 1." << std::endl;

    // INPUT 2
    input = { -10, 2, -5, 8 };
    expected = { -20, 4, -10, 16 };
    output = aProc.Normalize(input, 20);

    if (output != expected)
        std::cout << "bad Normalize! failed on input 2." << std::endl;

    ///////////
    bool exceptonThrown{ false };
    try
    {
        auto util = aProc.Normalize({ 1,2 }, 0);
    }
    catch (std::invalid_argument& e)
    {
        exceptonThrown = true;
    }

    if (!exceptonThrown)
        std::cout << "bad Normalize! normalizeTarget<1 didn't throw the exception." << std::endl;
}

int main()
{
    TestCompress();
    std::cout<<std::endl;
    TestCutOutSilence();
    std::cout<<std::endl;
    TestStretchTwice();
    std::cout<<std::endl;
    TestNormalize();
    std::cout<<std::endl;
    
    std::cout<<"COMPRESS "<<std::endl;
    AudioProcessor processor1;
    std::vector<short> audioSamples1{ 1, 4, 30, 32, 0, -7, -40, 10 }; 
    std::vector<short> compressedAudio1;
    compressedAudio1 = processor1.Compress( audioSamples1, 10, 1.5 ); 

    for(int i=0; i<compressedAudio1.size(); i++)
    {
        std::cout<<compressedAudio1[i]<<" "; //1 4 23 25 0 -7 -30 10 
    }

    std::cout<<std::endl;

    AudioProcessor processor2;
    std::vector<short> audioSamples2{ 1, 4, 25, 15, 0, -7, -40, 10 }; 
    std::vector<short> compressedAudio2;
    compressedAudio2 = processor2.Compress( audioSamples2, 10, 1.5 ); 

    for(int i=0; i<compressedAudio2.size(); i++)
    {
        std::cout<<compressedAudio2[i]<<" "; //1 4 20 13 0 -7 -30 10
    }
   
   std::cout<<std::endl;

   AudioProcessor processor2a;
    std::vector<short> audioSamples2a{}; 
    std::vector<short> compressedAudio2a;
    compressedAudio2a = processor2a.Compress( audioSamples2a, 10, 1.5 ); 

    for(int i=0; i<compressedAudio2a.size(); i++)
    {
        std::cout<<compressedAudio2a[i]<<" "; //{}
    }
   
   std::cout<<std::endl;

    AudioProcessor processor2a1;
    std::vector<short> audioSamples2a1{}; 
    std::vector<short> compressedAudio2a1;
    compressedAudio2a1 = processor2a1.Compress( audioSamples2a1, 4, 5 ); 

    for(int i=0; i<compressedAudio2a1.size(); i++)
    {
        std::cout<<compressedAudio2a1[i]<<" "; //{}
    }
   
   std::cout<<std::endl;

    AudioProcessor processor2b;
    std::vector<short> audioSamples2b{0,0,0,0}; 
    std::vector<short> compressedAudio2b;
    compressedAudio2b = processor2b.Compress( audioSamples2a, 10, 1.5 ); //ask lak

    for(int i=0; i<compressedAudio2b.size(); i++)
    {
       std::cout<<compressedAudio2b[i]<<" ";
    }
   
   std::cout<<std::endl;

    AudioProcessor processor2c;
    std::vector<short> audioSamples2c{1, 4, 25, 15, 0, -7, -40, 10}; //<-----------------
    std::vector<short> compressedAudio2c;
    compressedAudio2c = processor2c.Compress( audioSamples2c, 10, 1.5 ); 

    for(int i=0; i<compressedAudio2c.size(); i++)
    {
       std::cout<<compressedAudio2c[i]<<" "; //{1,4,20,13,0,-7,-30,10}
    }
   
   std::cout<<std::endl;

  
    compressedAudio2c = processor2c.Compress( audioSamples2c, 0, 2 ); 

    for(int i=0; i<compressedAudio2c.size(); i++)
    {
       std::cout<<compressedAudio2c[i]<<" "; //{1,2,13,8,0,-4,-20,5}
    }
   
   std::cout<<std::endl;


    compressedAudio2c = processor2c.Compress( audioSamples2c, 2, 1 ); 

    for(int i=0; i<compressedAudio2c.size(); i++)
    {
       std::cout<<compressedAudio2c[i]<<" "; //{1,4,25,15,0,-7,-40,10}
    }
   
   std::cout<<std::endl;

   compressedAudio2c = processor2c.Compress( audioSamples2c, 2, 5 ); 

    for(int i=0; i<compressedAudio2c.size(); i++)
    {
       std::cout<<compressedAudio2c[i]<<" "; //{1,2,7,5,0,-3,-10,4}
    }
   
   std::cout<<std::endl;

   AudioProcessor processor2d;
    std::vector<short> audioSamples2d{4}; //<-------------------------------
    std::vector<short> compressedAudio2d;
    compressedAudio2d = processor2d.Compress( audioSamples2d, 10, 1.5 ); 

    for(int i=0; i<compressedAudio2d.size(); i++)
    {
       std::cout<<compressedAudio2d[i]<<" "; //{4}
    }
   
   std::cout<<std::endl;

   compressedAudio2d = processor2d.Compress( audioSamples2d, 2, 1 ); 

    for(int i=0; i<compressedAudio2d.size(); i++)
    {
       std::cout<<compressedAudio2d[i]<<" "; //4
    }
   
   std::cout<<std::endl;

   compressedAudio2d = processor2d.Compress( audioSamples2d, 2, 5 ); 

    for(int i=0; i<compressedAudio2d.size(); i++)
    {
       std::cout<<compressedAudio2d[i]<<" "; //2
    }
   
   std::cout<<std::endl;

   AudioProcessor processor2e;
    std::vector<short> audioSamples2e{25}; //<----------------------------------
    std::vector<short> compressedAudio2e;
    compressedAudio2e = processor2e.Compress( audioSamples2e, 10, 1.5 ); 

    for(int i=0; i<compressedAudio2e.size(); i++)
    {
       std::cout<<compressedAudio2e[i]<<" "; //20
    }
   
   std::cout<<std::endl;

   compressedAudio2e = processor2e.Compress( audioSamples2e, 2, 1 ); 

    for(int i=0; i<compressedAudio2e.size(); i++)
    {
       std::cout<<compressedAudio2e[i]<<" "; //25
    }
   
   std::cout<<std::endl;

   compressedAudio2e = processor2e.Compress( audioSamples2e, 2, 5 ); 

    for(int i=0; i<compressedAudio2e.size(); i++)
    {
       std::cout<<compressedAudio2e[i]<<" "; //7
    }
   
   std::cout<<std::endl;

    AudioProcessor processor2f;
    std::vector<short> audioSamples2f{-5}; //<------------------------------
    std::vector<short> compressedAudio2f;
    compressedAudio2f = processor2f.Compress( audioSamples2f, 10, 1.5 ); 

    for(int i=0; i<compressedAudio2f.size(); i++)
    {
       std::cout<<compressedAudio2f[i]<<" "; //-5
    }
   
   std::cout<<std::endl;

   compressedAudio2f = processor2f.Compress( audioSamples2f, 2, 1 ); 

    for(int i=0; i<compressedAudio2f.size(); i++)
    {
       std::cout<<compressedAudio2f[i]<<" "; //-5
    }
   
   std::cout<<std::endl;

   compressedAudio2f = processor2f.Compress( audioSamples2f, 2, 5 ); 

    for(int i=0; i<compressedAudio2f.size(); i++)
    {
       std::cout<<compressedAudio2f[i]<<" "; //-3
    }
   
   std::cout<<std::endl;

    AudioProcessor processor2g;
    std::vector<short> audioSamples2g{0}; //<-----------------------
    std::vector<short> compressedAudio2g;
    compressedAudio2g = processor2g.Compress( audioSamples2g, 10, 1.5 ); 

    for(int i=0; i<compressedAudio2g.size(); i++)
    {
       std::cout<<compressedAudio2g[i]<<" "; //0
    }

    std::cout<<std::endl;
    
    compressedAudio2g = processor2g.Compress( audioSamples2g, 2, 1 ); 

    for(int i=0; i<compressedAudio2g.size(); i++)
    {
       std::cout<<compressedAudio2g[i]<<" "; //0
    }
   
   std::cout<<std::endl;
    
    AudioProcessor processor2h;
    std::vector<short> audioSamples2h{-6,-90,2,4,40 }; //<----------------------------
    std::vector<short> compressedAudio2h;
    compressedAudio2h = processor2h.Compress( audioSamples2h, 10, 1.5 ); 

    for(int i=0; i<compressedAudio2h.size(); i++)
    {
       std::cout<<compressedAudio2h[i]<<" "; // -6  -63  2  4  30 
    }

    std::cout<<std::endl;
    compressedAudio2h = processor2h.Compress( audioSamples2h, 2, 1 ); 

    for(int i=0; i<compressedAudio2h.size(); i++)
    {
       std::cout<<compressedAudio2h[i]<<" "; //-6  -90  2  4  40  
    }

    std::cout<<std::endl;

    compressedAudio2h = processor2h.Compress( audioSamples2h, 2, 5 ); 

    for(int i=0; i<compressedAudio2h.size(); i++)
    {
       std::cout<<compressedAudio2h[i]<<" "; //-3  -20  2  2  10  
    }

    std::cout<<std::endl;

    AudioProcessor processor2i;
    std::vector<short> audioSamples2i{0,0,0,0,0}; //<----------------------
    std::vector<short> compressedAudio2i;
    compressedAudio2i = processor2i.Compress( audioSamples2i, 10, 1.5 ); 
    for(int i=0; i<compressedAudio2i.size(); i++)
    {
       std::cout<<compressedAudio2i[i]<<" "; // 0  0  0  0  0*
    }

    std::cout<<std::endl;

    compressedAudio2i = processor2i.Compress( audioSamples2i, 2, 1 ); 
    for(int i=0; i<compressedAudio2i.size(); i++)
    {
       std::cout<<compressedAudio2i[i]<<" "; // 0  0  0  0  0*
    }

    std::cout<<std::endl;

    compressedAudio2i = processor2i.Compress( audioSamples2i, 2, 5 ); 
    for(int i=0; i<compressedAudio2i.size(); i++)
    {
       std::cout<<compressedAudio2i[i]<<" "; // 0  0  0  0  0*
    }

    std::cout<<std::endl;

    compressedAudio2i = processor2i.Compress( audioSamples2i, 0, 5 ); 
    for(int i=0; i<compressedAudio2i.size(); i++)
    {
       std::cout<<compressedAudio2i[i]<<" "; //0  0  0  0  0
    }

    std::cout<<std::endl;

     compressedAudio2i = processor2i.Compress( audioSamples2i, 0, 2 ); 
    for(int i=0; i<compressedAudio2i.size(); i++)
    {
       std::cout<<compressedAudio2i[i]<<" "; //0  0  0  0  0 
    }

    std::cout<<std::endl;


   std::cout<<"CutOutSilence "<<std::endl;
    
    AudioProcessor processor3;
    std::vector<short> audioSamples3{1,-3,10,25,56,-1,-2,-16,-20,-8,-1,1,7,12};
    std::vector<short> compressedAudio3;
    compressedAudio3 = processor3.CutOutSilence(audioSamples3, 10, 3);

    for(int i=0; i<compressedAudio3.size(); i++) // {25,56,-1,-2,-16,-20,12}
    {
        std::cout<<compressedAudio3[i]<<" ";
    }

    std::cout<<std::endl;

    AudioProcessor processor3a;
    std::vector<short> audioSamples3a{};
    std::vector<short> compressedAudio3a;
    compressedAudio3a = processor3a.CutOutSilence(audioSamples3a, 10, 3);

    for(int i=0; i<compressedAudio3a.size(); i++) // {}
    {
        std::cout<<compressedAudio3a[i]<<" ";
    }

    std::cout<<std::endl;
    
    AudioProcessor processor3b;
    std::vector<short> audioSamples3b{0,0,0,0};
    std::vector<short> compressedAudio3b;
    compressedAudio3b = processor3b.CutOutSilence(audioSamples3a, 10, 3); /////----->Lak

    for(int i=0; i<compressedAudio3b.size(); i++)
    {
        std::cout<<compressedAudio3b[i]<<" ";
    }

    std::cout<<std::endl;

    AudioProcessor processor3c;
    std::vector<short> audioSamples3c{ 1, 2, 5, 6, -4, 4, 10, 0, -2, -5, -4};
    std::vector<short> compressedAudio3c;
    compressedAudio3c = processor3c.CutOutSilence(audioSamples3c,5,3);

    for(int i=0; i<compressedAudio3c.size(); i++)//6 -4 4 10
    {
        std::cout<<compressedAudio3c[i]<<" "; 
    }

   std::cout<<std::endl;


    AudioProcessor processor3e;
    std::vector<short> audioSamples3e{1,0,1,0, -1};
    std::vector<short> compressedAudio3e;
    compressedAudio3e = processor3e.CutOutSilence(audioSamples3e,1,5);

    for(int i=0; i<compressedAudio3e.size(); i++)
    {
        std::cout<<compressedAudio3e[i]<<" ";//empty 
    }

   std::cout<<std::endl;

    compressedAudio3e = processor3e.CutOutSilence(audioSamples3e,1,6);

    for(int i=0; i<compressedAudio3e.size(); i++)
    {
        std::cout<<compressedAudio3e[i]<<" ";//1 0 1 0  -1
    }

   std::cout<<std::endl;

    compressedAudio3e = processor3e.CutOutSilence(audioSamples3e,0,2);

    for(int i=0; i<compressedAudio3e.size(); i++)
    {
        std::cout<<compressedAudio3e[i]<<" ";//1 0 1 0  -1
    }

   std::cout<<std::endl;

    AudioProcessor processor3f;
    std::vector<short> audioSamples3f{};
    std::vector<short> compressedAudio3f;
    compressedAudio3f = processor3f.CutOutSilence(audioSamples3f,1,5);
    for(int i=0; i<compressedAudio3f.size(); i++)
    {
        std::cout<<compressedAudio3f[i]<<" ";//empty 
    }

   std::cout<<std::endl;

    AudioProcessor processor3g;
    std::vector<short> audioSamples3g{-9,0,9,1,15,19, -5,0,7, 20,-9,0,4,-6,-10,-2,0,2,5};
    std::vector<short> compressedAudio3g;
    compressedAudio3g = processor3g.CutOutSilence(audioSamples3g,9,4);
    for(int i=0; i<compressedAudio3g.size(); i++)
    {
        std::cout<<compressedAudio3g[i]<<" ";//15  19  -5  0  7  20  -10 
    }

   std::cout<<std::endl;


    compressedAudio3 = processor3.CutOutSilence(audioSamples3, 0, 1);
    for(int i=0; i<compressedAudio3.size(); i++) //1  -3  10  25  56  -1  -2  -16  -20  -8  -1  1  7  12
    {
        std::cout<<compressedAudio3[i]<<" ";
    }

    std::cout<<std::endl;

    compressedAudio3 = processor3.CutOutSilence(audioSamples3, 16, 1);
    for(int i=0; i<compressedAudio3.size(); i++) //25  56  -20 
    {
        std::cout<<compressedAudio3[i]<<" ";
    }

    std::cout<<std::endl;


    AudioProcessor processor3h;
    std::vector<short> audioSamples3h{0,0};
    std::vector<short> compressedAudio3h;
    compressedAudio3h = processor3h.CutOutSilence(audioSamples3h,10,3);
    for(int i=0; i<compressedAudio3h.size(); i++)
    {
        std::cout<<compressedAudio3h[i]<<" ";//0 0
    }

   std::cout<<std::endl;

    AudioProcessor processor3i;
    std::vector<short> audioSamples3i{0,0,0,0};
    std::vector<short> compressedAudio3i;
    compressedAudio3i = processor3i.CutOutSilence(audioSamples3i,10,3);
    for(int i=0; i<compressedAudio3i.size(); i++)
    {
        std::cout<<compressedAudio3i[i]<<" ";//  -------->ask lak
    }

   std::cout<<std::endl;

    compressedAudio3i = processor3i.CutOutSilence(audioSamples3i,10,5);
    for(int i=0; i<compressedAudio3i.size(); i++)
    {
        std::cout<<compressedAudio3i[i]<<" ";//0 0 0 0
    }

   std::cout<<std::endl;
   

   std::cout<<"StretchTwice "<<std::endl;
    
    AudioProcessor processor4;
    std::vector<short> audioSamples4{7,4,2};
    std::vector<short> compressedAudio4;
    compressedAudio4 = processor4.StretchTwice(audioSamples4); 

    for(int i=0; i<compressedAudio4.size(); i++) //7,6,4,3,2
    {
        std::cout<<compressedAudio4[i]<<" ";
    }

    std::cout<<std::endl;

    
    AudioProcessor processor5;
    std::vector<short> audioSamples5{1,4,23,-2,-28,10};
    std::vector<short> compressedAudio5;
    compressedAudio5 = processor5.StretchTwice(audioSamples5);

    for(int i=0; i<compressedAudio5.size(); i++) //{1, 3, 4, 14, 23, 11, - 2, -15, -28, -9, 10}
    {
        std::cout<<compressedAudio5[i]<<" "; 
    }

    std::cout<<std::endl;

    AudioProcessor processor6;
    std::vector<short> audioSamples6{7};
    std::vector<short> compressedAudio6;
    compressedAudio6 = processor6.StretchTwice(audioSamples6);

    for(int i=0; i<compressedAudio6.size(); i++)//7 ask lak 
    {
        std::cout<<compressedAudio6[i]<<" ";
    }
   
   std::cout<<std::endl;

    AudioProcessor processor7;
    std::vector<short> audioSamples7{10};
    std::vector<short> compressedAudio7;
    compressedAudio7 = processor7.StretchTwice(audioSamples7); //10 ask lak

    for(int i=0; i<compressedAudio7.size(); i++)//10
    {
        std::cout<<compressedAudio7[i]<<" ";
    }
   
   std::cout<<std::endl;

    AudioProcessor processor7a;
    std::vector<short> audioSamples7a{};
    std::vector<short> compressedAudio7a;
    compressedAudio7a = processor7a.StretchTwice(audioSamples7a);

    for(int i=0; i<compressedAudio7a.size(); i++)//{}  ask lak
    {
        std::cout<<compressedAudio7a[i]<<" ";
    }
   
   std::cout<<std::endl;


    AudioProcessor processor7c;
    std::vector<short> audioSamples7c{ 1, 2, 6, -5, -10, 1 };
    std::vector<short> compressedAudio7c;
    compressedAudio7c = processor7c.StretchTwice(audioSamples7c);

    for(int i=0; i<compressedAudio7c.size(); i++)
    {
        std::cout<<compressedAudio7c[i]<<" ";//1  2  2  4  6  1  -5  -8  -10  -5  1  
    }
    
    std::cout<<std::endl;

    AudioProcessor processor7d;
    std::vector<short> audioSamples7d{0,0,0,0,0};
    std::vector<short> compressedAudio7d;
    compressedAudio7d = processor7d.StretchTwice(audioSamples7d);
    for(int i=0; i<compressedAudio7d.size(); i++)
    {
        std::cout<<compressedAudio7d[i]<<" ";//0 0 0 0 0 0 0 0 0
    }

    std::cout<<std::endl;
    
    AudioProcessor processor7e;
    std::vector<short> audioSamples7e{ 1, 4};
    std::vector<short> compressedAudio7e;
    compressedAudio7e = processor7e.StretchTwice(audioSamples7e);
    for(int i=0; i<compressedAudio7e.size(); i++)
    {
        std::cout<<compressedAudio7e[i]<<" ";//1 3 4
    }

    std::cout<<std::endl;

    AudioProcessor processor7f;
    std::vector<short> audioSamples7f{100};
    std::vector<short> compressedAudio7f;
    compressedAudio7f = processor7f.StretchTwice(audioSamples7f);
    for(int i=0; i<compressedAudio7f.size(); i++)
    {
        std::cout<<compressedAudio7f[i]<<" ";//100
    }

    std::cout<<std::endl;

    AudioProcessor processor7g;
    std::vector<short> audioSamples7g{-9};
    std::vector<short> compressedAudio7g;
    compressedAudio7g = processor7g.StretchTwice(audioSamples7g);
    for(int i=0; i<compressedAudio7g.size(); i++)
    {
        std::cout<<compressedAudio7g[i]<<" ";//-9
    }
   
   std::cout<<std::endl;
    
    AudioProcessor processor7h;
    std::vector<short> audioSamples7h{-9,1,2,-10,7,-6,0,1};
    std::vector<short> compressedAudio7h;
    compressedAudio7h = processor7h.StretchTwice(audioSamples7h);
    for(int i=0; i<compressedAudio7h.size(); i++)
    {
        std::cout<<compressedAudio7h[i]<<" ";//-9  -4  1  2  2  -4  -10  -2  7  1  -6  -3  0  1  1 
    }

    std::cout<<std::endl;
   
    std::cout<<"Normalize"<<std::endl;
    
    AudioProcessor processor9;
    std::vector<short> audioSamples9{0,0,0,0,0,0};
    std::vector<short> compressedAudio9;
    compressedAudio9 = processor9.Normalize(audioSamples9,10);

    for(int i=0; i<compressedAudio9.size(); i++)//{0,0,0,0,0,0}
    {
        std::cout<<compressedAudio9[i]<<" ";
    }

    std::cout<<std::endl;

    AudioProcessor processor9a;
    std::vector<short> audioSamples9a{0,0,0,0,0,0,0,0};
    std::vector<short> compressedAudio9a;
    compressedAudio9a = processor9a.Normalize(audioSamples9a,8);

    for(int i=0; i<compressedAudio9a.size(); i++)//{0,0,0,0,0,0,0}
    {
        std::cout<<compressedAudio9a[i]<<" ";
    }

    std::cout<<std::endl;

    AudioProcessor processor9b;
    std::vector<short> audioSamples9b{1,3,-2,5,-4,0};
    std::vector<short> compressedAudio9b;
    compressedAudio9b = processor9b.Normalize(audioSamples9b,2);

    for(int i=0; i<compressedAudio9b.size(); i++) //{0,1,-1,2,-2,0}---ask lak
    {
        std::cout<<compressedAudio9b[i]<<" ";
    }

    std::cout<<std::endl;

    
    AudioProcessor processor10;
    std::vector<short> audioSamples10{1,3,-2,5,-4,0};
    std::vector<short> compressedAudio10;
    compressedAudio10 = processor10.Normalize(audioSamples10,10);

    for(int i=0; i<compressedAudio10.size(); i++) //{2, 6, -4, 10, -8, 0}
    {
        std::cout<<compressedAudio10[i]<<" ";
    }

    std::cout<<std::endl;

    AudioProcessor processor11;
    std::vector<short> audioSamples11{};
    std::vector<short> compressedAudio11;
    compressedAudio11 = processor11.Normalize(audioSamples11,10);

    for(int i=0; i<compressedAudio11.size(); i++) //{}
    {
        std::cout<<compressedAudio11[i]<<" ";
    }

    std::cout<<std::endl;

    AudioProcessor processor12;
    std::vector<short> audioSamples12{-1, -30, 3, 15, 16, -7};
    std::vector<short> compressedAudio12;
    compressedAudio12 = processor12.Normalize(audioSamples12,20);

    for(int i=0; i<compressedAudio12.size(); i++) //-1  -20  2  10  11  -5  
    {
        std::cout<<compressedAudio12[i]<<" ";
    }

    std::cout<<std::endl;

    AudioProcessor processor13;
    std::vector<short> audioSamples13{0,0,0,0,0,0,0,0,0,0};
    std::vector<short> compressedAudio13;
    compressedAudio13 = processor13.Normalize(audioSamples13,5);

    for(int i=0; i<compressedAudio13.size(); i++)  //0  0  0  0  0  0  0  0  0  0 
    {
        std::cout<<compressedAudio13[i]<<" ";
    }

    std::cout<<std::endl;

    AudioProcessor processor14;
    std::vector<short> audioSamples14{0,0};
    std::vector<short> compressedAudio14;
    compressedAudio14 = processor14.Normalize(audioSamples14,1);

    for(int i=0; i<compressedAudio14.size(); i++)  //0  0  
    {
        std::cout<<compressedAudio14[i]<<" ";
    }

    std::cout<<std::endl;

    AudioProcessor processor15;
    std::vector<short> audioSamples15{19};
    std::vector<short> compressedAudio15;
    compressedAudio15 = processor15.Normalize(audioSamples15,10);

    for(int i=0; i<compressedAudio15.size(); i++)   
    {
        std::cout<<compressedAudio15[i]<<" ";//10
    }
    std::cout<<std::endl;
    std::cout<< "A"<<std::endl;



   
    return 0;
}