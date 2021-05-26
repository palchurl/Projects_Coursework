 /*
Assignment: Project 4 -  Audio Processor
Date: 12/10/2020

Purpose: This file contains interface of 
the AudioProcessor class. It has the classes 
public member functions/data members. A
*/

#ifndef _AUDIO_PROCESSOR_
#define _AUDIO_PROCESSOR_

#include <iostream>
#include <algorithm>
#include <stack>        //stack
#include <cmath>        //round
#include <vector>       //vector
#include <stdexcept>    //throw exception

class AudioProcessor {
    public:
        /* Compress takes a vector of shorts, a short threshold, and a float rate. Compress takes
        every element of audio and it is larger than the threshold or smaller than the negated 
        threshold then it is reduced using the compression rate. */
        std::vector<short> Compress(const std::vector<short> & audio, short threshold, float rate);
       
        /* CutOutSilence takes a vector of shorts, a short level, and a int silenceLength. If a 
        group of adjacent elements in audio of length of silenceLength or higher have all of 
        the groups elements within the range of negative level and level than it is cut out of audio. */
        std::vector<short> CutOutSilence(const std::vector<short> & audio, short level, int silenceLength);

        /* StretchTwice takes a vector of shorts and returns a vector of shorts where the 
        arithmetic mean of the every two elements is placed between every two elements. */
        std::vector<short> StretchTwice(const std::vector<short> & audio);

        /* Normalize takes a vector of shorts and a short normalizeTarget. Normalize returns a modified 
        audio where all the elemets are proportially adjusted to ensure that the normalizeTarget value is the 
        largest absolute value of all the elements in audio. */
        std::vector<short> Normalize(const std::vector<short> & audio, short normalizeTarget);
};

#endif