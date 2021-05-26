/*
Assignment: Project 4 -  Audio Processor
Date: 12/10/2020

Purpose: This file contains implementation of 
the AudioProcessor class. It has the 
implementation of the member functions 
in the interface. A
*/

#include "AudioProcessor.h"
#include <iostream>
#include <vector>       //vector
#include <stack>        //stack
#include <stdexcept>    //exception
#include <algorithm>    //reverse
#include <cmath>        //round

/* Compress will check if audio is empty if it is return an empty vector, and then will make 
sure threshold and rate are valid arguments. Then if an element is outside the threshold 
the formula (element – threshold)/rate + threshold or a variation if element is negative 
is applied to it and that value of the element is altered.
*/
std::vector<short> AudioProcessor::Compress(const std::vector<short> & audio, short threshold, float rate) {

    if(audio.empty()) {     //If audio is empty then an empty vector 
        return {};          //is returned since no computation is needed
    }
    if(threshold < 0 || rate < 1) {                                             //If threshold is less than 0 
        throw std::invalid_argument("threshold or rate is invalid arguemnt");   //or rate less than 1 an exception 
    }                                                                //is thrown since these are invalid arguments.

    std::vector<short> tempAudio;               //A vector of shorts is made 
    tempAudio = audio;                          //tempAudio it is made to be a copy of audio 
    short negThreshold = threshold * -1;        //negThreshold stores the negated threshold to be used later

    for(int i = 0; i < audio.size(); i++) {                                     //Each element of audio is traversed
        if(audio[i] > threshold) {                                              //if the element is greater than threshold 
            tempAudio.at(i) = round(((audio[i] - threshold)/rate) + threshold); //the formula is applied and roundins is 
        }                                                                       //applied and the new value is altered in tempAudio
        if(audio[i] < negThreshold) {                                           //if the element is less than -threshold then
            int t = round(((abs(audio[i]) - threshold)/rate) + threshold);      //modified formula is applied and rounding 
            tempAudio.at(i) = t * -1;                                           //then its negation is stored at index i in 
        }                                                                       //tempAudio.
    }
    
    return tempAudio;           //The altered and compressed audio vector, tempAudio is returned
}
/* Compress takes each element of audio and if it higher than the threshold it subtracts 
the threshold and divides the yield by rate and adds threshold once again. If the element 
is lower than the negated threshold same is done with the absolute value and then the yield 
is rounded and negated. Compress ensures all out of range elements have this procedure applied to them.
*/

/* CutOutSilence will check if audio is empty, and if level and silenceLength are valid 
arguements and then it deletes group(s) of adjacent elements in audio of length of silenceLength 
or higher have all of the groups elements within the range of negative level and level. 
*/
std::vector<short> AudioProcessor::CutOutSilence(const std::vector<short> & audio, short level, int silenceLength) {

    if(audio.empty()) {         //If audio is empty then 
        return {};              //an empty vector is returned 
    }

    if(level < 0 || silenceLength < 1) {                                                //If level is less than 0 or 
        throw std::invalid_argument("level or silenceLength are invalid arguments");    //silenceLength is less than 1
    }                                                                                   //exception is thrown to indicate
    //arguement passed is not valid. This is since if level is negative it would not produce a range like
    //it would it is positive and atleast 1 element has to be in the group to be deleted so silencelength 
    //has to 1 or greater

    std::vector<short> tempAudio;               //A tempAudio vector of shorts is made store the answer

    int counter = 0;                            //counter is set to 0
    for(int i = 0; i < audio.size(); i++) {     //Each element of audio is traversed
        if(abs(audio[i]) <= level) {            //if audio[i] is within [-level,level]
            tempAudio.push_back(audio[i]);      //the element is pushed into tempAudio
            counter++;                          //and counter is incremented
        }
        if(!(abs(audio[i]) <= level)) {         //if audio[i] is not within [-level,level]
            if(counter >= silenceLength) {      //then a possible group has ended so if the 
                while(counter != 0) {           //counter is greater than silenceLength.
                    tempAudio.pop_back();       //then pop of all elements in group out.
                    counter--;                  //decrement counter so loop stops 
                }                               //once reaching 0
            }
            tempAudio.push_back(audio[i]);      //Then the current element is pushed into 
            counter = 0;                        //answer vector and counter is reset
        }
        if(i == audio.size()-1) {               //if index is at the last element we check 
            if(counter >= silenceLength) {      //there counter is greater than or equal 
                while(counter != 0) {           //to silencelength. If it is then those 
                    tempAudio.pop_back();       //elements are taken out of the answer vector.
                    counter--;
                }
            }
        }
    }
    
    return tempAudio;           //tempAudio, vector with silence cut out, is returned
}
/* CutOutSilence takes out groups of adjacent audio elements that are in the range of level 
and -level if and only if the groups size is equal to or greater than silenceLength. So 
each element is traversed through and if the element is in the range of level and negative 
level a counter is incremented and added into the tempAudio vector. Once we reach 
a element that is not in the range then a possible group has been passed so we chack if 
the counter is at least silence length and if it is elements are poped of until counter 
returns to its original value of 0. This cuts out the group and now we just push the current 
element and reset the counter in case a group hasnt been passed. Now if the current element 
is the last one in the vector we repeat the check to catch any last group that is 
within level and then after every element has been traversed and processed the tempAudio is returned.
*/


/* StretchTwice takes in a vector of shorts named audio, and checks if audio is empty if
it is returns an empty vector. Also checks if audio has more than 1 element. With every
two elements the mean of the two elements is inserted between the two elements. */
std::vector<short> AudioProcessor::StretchTwice(const std::vector<short> & audio) {

    if(audio.empty()) {     //If audio is empty then 
        return {};          //an empty vector is returned 
    }
    if(audio.size() < 2) {     //If the size of audio is less than 2 its is 
        return audio;          //returned since atleast 2 elements are needed to 
    }                          //calculate an average

    std::stack<double> ans;    //A stack of doubles is created
    ans.push(audio[0]);        //the first element of audio is pushed into the stack
    for(int i = 1; i < audio.size(); i++) {     //each element of audio is traversed
        double tempi = ans.top() + audio[i];    //the top of the stack and the current 
        double temp = tempi/2;                  //element are added and divided by 2 to 
        ans.push(round(temp));                  //get the mean and this value is rounded
        ans.push(audio[i]);                     //and pushed into the stack along with the 
    }                                           //actual current element
    //double is the type of the stack and the temp variables since the decimals of 
    //the computations need to be preserved before they are rounded and sent into 
    //the stack and then eventually into the vector of shorts
    
    std::vector<short> ansV;            //A vector of shorts to be returned is created
    while (!ans.empty())                //until the stack is empty 
    {                                   //the elements are pushed into ansV and 
        ansV.push_back(ans.top());      //the stack is popped so loop can continue 
        ans.pop();                      //to decrease till stack is empty and top moves
    } 
    std::reverse(ansV.begin(),ansV.end());  //Since stack to vector will give reversed elements 
                                            //reverse function puts elements in correct order
    return ansV;            //ansV which containes elements and averages is returned

}
/* StretchTwice makes a stack and with each 2 elements in tempaudio to be average it should 
represent the previous value which the current value will be added to and then divided by two 
so the average can be calculated and the the current value is pushed in. All of the stack elements 
are trasnferred to a vector by copying the top element of the vector and poping the top until the 
stack is empty. Since the stack is last in first out the elements of the vector to be the answer 
are inverted so reverse method is used and the answer vector is returned.
*/

/* Normalize takes a vector of shorts named audio and a short normalizeTarget. Each 
element of audio is proportionatly adjusted by calculating a ratio so that the greatest 
absolute element in audio is normalizeTarget. */
std::vector<short> AudioProcessor::Normalize(const std::vector<short> & audio, short normalizeTarget) {

    if(audio.empty()) {     //If audio is empty then 
        return {};          //an empty vector is returned 
    }
    if(normalizeTarget < 1) {        //If normalizeTarget is less than 1 and exception is thrown 
        throw std::invalid_argument("normalizeTarget is an invalid arguemnt");  //to indicate invalid
    }                                                                           //arguement was passed

    std::vector<short> z(audio.size(),0);   //Making a vector z of same size of audio 
    if(audio == z) {                        //with all elements being 0, if audio = z than
        return audio;                       //audio is returned since later in the calculations
    }                                       //the min and max of that array which will be 0 
    //will be a denominator so the same passed in vector is returned.
    
    std::vector<short> ans;      //a vector of shorts ans is created
    
    short maxElem = audio[0];    //MaxElem set to first element of audio it will hold max of audio
    short minElem = audio[0];    //MinElem set to first element of audio it will hold min of audio
    for(int i = 1; i < audio.size(); i++) {     //Each element of audio is traversed
        if(audio[i] < minElem) {                //If current element is less than minElem than
            minElem = audio[i];                 //minElem gets its value so it will eventually 
        }                                       //have the smallest element in audio's value.
        if(audio[i] > maxElem) {                //If current element is greater than maxElem than  
            maxElem = audio[i];                 //maxElem gets its value so it will eventually
        }                                       //have the largest element in audio's value.
    }

    double maxOfMinMax = std::max(abs(minElem), abs(maxElem));  //The greater absolute value is stored
    double mul = normalizeTarget/maxOfMinMax;         //mul is the ratio of normalizeTarget and maxOfMinMax

    for(int i = 0; i < audio.size(); i++) {     //Each element of audio is traversed
        ans.push_back(round(audio[i]*mul));     //and the ratio is applied to each element and 
    }                                           //the resulting value is rounded and pushed into ans.

    return ans;   //ans now has the proportionate values of elements of audio and the vector is returned.
}
/* Normalize takes in a variable of normalize target which is used to calculate a rate 
to multiply each element of audio. The max and min of audio are calculate and the 
greatest absolute value of the max and min is taken and normalizetarget divides the 
greatest absolute value to get the proportion. Then each element of audio is traversed 
and its value is multiplied by the ratio and stored in a vector and this vector is returned. A
*/

