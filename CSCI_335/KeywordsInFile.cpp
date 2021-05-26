/*
Assignment: Project 2 -  KeywordsInFile
Date: 10/29/2020

Purpose: This file contains the 
implementation of the KeywordsInFile class. It has 
the classes public member functions. It also and 
has the implementation of the member functions 
in the interface. A
*/

#include "KeywordsInFile.h"
#include <iostream>
#include <unordered_map>  //Unordered Map
#include <stdexcept>      //Std exceptions
#include <string>         //String

/* Parameterized Constructor takes in two parameters. The first parameter is the 
name of the file holding the keywords and the second parameter is the name of 
the file holding the text. The cosntructor processes these files and looks for the
total number of occurances of each keyword. The constructor also stores the number 
of occurances of each keyword on each line of the text file. The occurances are stored
along with their respective keyword in unordered_maps. */
KeywordsInFile::KeywordsInFile(const std::string & filename_with_keywords, const std::string & filename_with_text) {  
    std::ifstream xin(filename_with_keywords);                       //Input stream used to operate on keywords file
    if(xin.fail()){                                                  //If file is not able to be opened 
        std::cerr << "Keywords File Cannot be Opened" << std::endl;       //display an error and exit 
        exit(1);
    }

    std::ifstream fin(filename_with_text);                           //Input stream used to operate on text file
    if(fin.fail()){                                                  //If file is not able to be opened 
        std::cerr << "Text File Cannot be Opened" << std::endl;           //display an error and exit 
        exit(1);
    }

    std::string keywords;                                        //string keywords will hold one line from the txt 
    while (getline (xin, keywords)) {                            //getline will run till there are no more line to acquire
        std::string word = "";                                   //word stores string of alphabetic chars  
        for (int i = 0; i < keywords.length(); i++) {            //traverse through each char of the line  
            if (isalpha(keywords[i])) {                          //if a alphabetic char is encounterd
                word += keywords[i];                             //add it to the string variable word
                
                if(i == keywords.length()-1 && word != "n" && !word.empty()) {  
                    keywordsOccurancesInText.insert({word,0});         //if end of string is reached and word is not n (\n)  
                    word = "";                                         //this means there is a word at the end of the line   
                }                                                      //insert the word and 0 into the unordered map
            }                                                          //reset the word variable for the next word
               
            else {                                                     //if char is not alphabetic (i.e is a separator)
                if(!word.empty()) {                                    //and if the word is not empty 
                    keywordsOccurancesInText.insert({word,0});         //insert the word:0 into the unordered map keeping track
                    word = "";                                         //of the keywords and reset the word variable.
                }
            } 
        }  
    }
    xin.close();               //Processing in this file containing keywords is done so close it

    std::string text;                 //string text contains a line in the text file
    int line_number = 0;              //line_number is a counter to track which line is being processed
    std::unordered_map<std::string, int> copy = keywordsOccurancesInText;   //copying an the unordered map (each keyword has 0 occurances)
    while (getline (fin, text)) {                                           //using getline and putting the strng line into text
        std::string word = "";                                              //word stores string of alphabetic chars  
        std::unordered_map<std::string, int> temp = copy;                   //temp is a copy of copy and can store occurances for a line
        for (int i = 0; i < text.length(); i++) {                   //traverse char by char through the line string
            if (isalpha(text[i]))  {                                //if the char is alphabetic
                word = word + text[i];                              //add it to the word variable eventually forming a str of chars
                if(i == text.length()-1 && (keywordsOccurancesInText.count(word) > 0)) {   //if at the last index and still 
                    temp.at(word)++;                                                       //a word's occurances is not updated
                    keywordsOccurancesInText.at(word)++;                                   //update total occurances 
                }                                                                          //and line occurances
            } 

            else {                                                                         //if char is not alphabetic (is a seperator)
                if(keywordsOccurancesInText.count(word) > 0 && !word.empty()) {            //if word is one of the keywords and isn't empty
                    temp.at(word)++;                                                       //update the total occurances of the keyword
                    keywordsOccurancesInText.at(word)++;                                   //and update the occurances of keyword in this line
                }   
                word = "";                                                                 //reset word so next word can be made
            }
        } 
        line_number++;                                                 //increment the line number counter
        keywordLinesOccurances.insert({line_number, temp});            //and insert the line number and the unordered map with the 
    }                                                                  //occurances of the keywords for that line.
    fin.close();                                                       //now that processing the text file is done close it
}
//When processing the file with the keywords we go through the file line by line and insert each group of unseperated 
//chars into a unordered map along with 0. Now that we have a all the keywords we need to look for them in the text file.
//We process the text file and go line by line and whenever we come across a word we see if the word is one of the keywords
//in the previously made unordered map. If the word is a keyword, we increment the integer element of the unordered map. We do
//this for every line in the file and insert each lines unordered map into an unordered map storing the line number of the 
//map being inserted and the unordered map with specific lines keywords occurances.

/* KeywordFound method is passed a string keyword into the function
@return true if the keyword is found in the keywords file 
and false if it is not found.  */
bool KeywordsInFile::KeywordFound(const std::string & keyword) {
    if(keywordsOccurancesInText.count(keyword) > 0)             //Since the keys in the keywordsOccurancesInText 
    {                                                           //are the keywords using count to see the number of 
        return true;                                            //occurances of the keyword in the unordered map keys
    }                                                           //If number of occurances of the keyword in the umap 
    return false;                                               //is greater 0 return true (keyword exists) else 
}                                                               //return false (keyword doesnt exist)


/* KeywordInLine takes in a string keyword and an integer line number.
@return an integer which is the number of times the passed in keyword 
occurs in the passed in line. 
*/
int KeywordsInFile::KeywordInLine(const std::string & keyword, int line_number) {
    if ( line_number <= 0 || line_number > keywordLinesOccurances.size()) { //If line number is in valid (if it is 0 or higher
        throw std::out_of_range("Invalid line number has been passed");     //then the number of lines in the text throw an 
    }                                                                       //exception that says number is invalid.                                                                     
    if(!KeywordFound(keyword)){                                             //If the keyword passed is not one of the keywords 
        throw std::logic_error("keyword passed not found in keywords.txt"); //(trying to access a keyword that does not exist)     
    }                                                                       //in the keywords file then throw an exception. 
   return keywordLinesOccurances.at(line_number).at(keyword);               //If line number and keyword are valid return 
}                                                                           //the number of occurances
//The method acesses the unordered map that holds the occurances of the keywords at a specific line number by first
//getting the unordered map stored in the line number stored, since the line numbers are the keys the unordered map 
//at(line_number) is used. Then now that the unordered map is accessable at(keyword) is used to acquire the specific 
//keywords occurances number. This number is then returned.


/* TotalOccurrences is passed in a string keyword 
@return the number of times the keyword specified occurs in 
the text file.
*/
int KeywordsInFile::TotalOccurrences(const std::string & keyword) {
    if(!KeywordFound(keyword)){                                             //If the keyword passed is not one of the keywords 
        throw std::logic_error("keyword passed not found in keywords.txt"); //(trying to access a keyword that does not exist)     
    }                                                                       //in the keywords file then throw an exception.  
    return keywordsOccurancesInText.at(keyword);                            //Else return the total number of occurances
}                                                                           //of keyword in the text file.
//keywordsOccurancesInText stores the total number of occurances of each keyword so at is used to 
//access the occurances. since string keywords are the key and int occurances are the elements, 
//the integer storing the number of occurances will accessable using at and is returned.


/* Overload operator<< will allow pass in a KeywordsInFile and displays keywords 
and their respective total number of occurances */
std::ostream& operator<<(std::ostream& os, const KeywordsInFile& obj) {
    for(const auto & x: obj.keywordsOccurancesInText) {      //Overload the operator to recognize an ostream object on 
        std::cout <<  x.first << ": "<< x.second << std::endl;         //the left and a KeywordsInFile on the right. Go through    
    }                                                //the keywords: occurances of each element in the unordered
    return os;                                       //map and display them. Then return the reference to the ostream object
}                                                            
//This method overloads the operator<<. Since the passed object contains the unordered 
//map keywordsOccurancesInText which stores all the keywords and their total occurances a for loop
//is used to go through the unordered map and print the keys and elements (keywords: occurances) 
//with each keyword. 
