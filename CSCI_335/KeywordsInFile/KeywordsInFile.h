/*
Assignment: Project 2 -  KeywordsInFile
Date: 10/29/2020

Purpose: This is the header file for KeywordsInfile.cpp, 
it contains the interfaceof the KeywordsInfile class 
and the classes public and private member functions/ data members. A
*/

#ifndef _KEYWORDSINFILE_
#define _KEYWORDSINFILE_
/* Preprocessor directives
#ifndef is used to conditionally include a class definition
#define directive defines the name _KEYWORDSINFILE_  */

#include <unordered_map>    //Unordered Map
#include <fstream>          //File stream to read txt files
#include <string>

class KeywordsInFile {
    private:
        std::unordered_map<std::string, int> keywordsOccurancesInText;
        //keywordsOccurancesInText is an unordered map with a string as the key and integer as an
        //element. This unordered map will store the keywords from keywords txt file as keys and 
        //the keywords total occurances as elements.

        std::unordered_map<int, std::unordered_map<std::string, int>> keywordLinesOccurances;
        //keywordLinesOccurances is an unordered map with integers as keys and an unordered map
        //as elements. This unordered map will store line numbers as keys and unordered maps that store 
        //keywords as keys and their occurances as elements. Each element of keywordLinesOccurances
        //is the number occurances of each keyword in a specific line.
        
    public:

        /* Default constructor is disabled because we do not want user to be able to 
        access class methods without passing in an files to be processed. */
        KeywordsInFile() = delete; 

        /* Parameterized Constructor takes in two files one with keywords and the other
        with text. Files are processed and data is keyword occurances are stored in unorderd maps */
        KeywordsInFile(const std::string & filename_with_keywords, const std::string & filename_with_text); 

        /* KeywordFound is a public member function that returns true if the a 
        passed in keyword was found in the text else returns false */
        bool KeywordFound(const std::string & keyword);

        /* KeywordInLine is a public member function that returns the number of times 
        the passed in keyword was seen in a passed in line number of the text. */
        int KeywordInLine(const std::string & keyword, int line_number);

        /* TotalOccurrences is a public member function that returns the total number of 
        occurrences of the given passed keyword in the text. */
        int TotalOccurrences(const std::string & keyword);

        /* Operator<< overload prints the all the keywords total occurances in the text */
        friend std::ostream& operator<<(std::ostream& os, const KeywordsInFile& obj);
};

#include "KeywordsInFile.cpp"
#endif


