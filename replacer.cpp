#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <list>
#include <stdexcept>
#include <algorithm>
#include <functional> 
#include <cctype>
#include <locale>


using namespace std;

// trim from start (in place)
static inline void ltrim(std::string &s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(),
            std::not1(std::ptr_fun<int, int>(std::isspace))));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
    s.erase(std::find_if(s.rbegin(), s.rend(),
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
}

// trim from both ends (in place)
static inline void trim(std::string &s) {
    ltrim(s);
    rtrim(s);
}

// trim from start (copying)
static inline std::string ltrimmed(std::string s) {
    ltrim(s);
    return s;
}

// trim from end (copying)
static inline std::string rtrimmed(std::string s) {
    rtrim(s);
    return s;
}

// trim from both ends (copying)
static inline std::string trimmed(std::string s) {
    trim(s);
    return s;
}

std::list<std::string> readFile(std::string fileName) {
  
  /* Function which takes a file name as a parameter and 
   * read all its content line per line
   *
   * INPUT - filename , std::std::string
   * OUTPUT - list of filecontent, std::list<std::std::string>
   * throws File not found exception error when file is not present
   */
  
  std::list<std::string> myFileContent; 
  std::ifstream myFile (fileName);

  if(!myFile) {
    cout<<"File hi nahi hai beta";
    throw "File does not exist!";
  }
  //myFile.exceptions (ifstream::failbit | ifstream::badbit );
  try {
    for(std::string line; std::getline( myFile, line ); ) {
      myFileContent.push_back(line);
      cout<<line<<endl;
    }
  }
  catch(std::exception const& e) {
    cout << "There was an error: " << e.what() << endl;
  }
  
  myFile.close();
  
  return myFileContent;

  
}



void writeFile(std::string filename, std::list<std::string> myFileContent) {
  
  std::ofstream myFile (filename);
  if(!myFile) {
    cout<<"File hi nahi hai beta";
    throw "File not found";
  }
  for( auto iterator = myFileContent.begin() ; iterator != myFileContent.end() ; ++iterator ) {
    myFile << *iterator << '\n' ;
  }
  std::cout<< "Hey, it's done'";
  myFile.close();

}


bool StringMatcher(std::string stringOne, std::string stringTwo) {
  
  cout<<stringOne<<endl;
  cout<<trimmed(stringOne);
  std::string regexString = "(\\s*)("+ trimmed(stringOne) + ")(\\s*)";
  std::regex e (regexString);
  std::cout<<"this - "<<regexString<<endl;
  //std::regex e (stringOne);
  if (regex_match(stringTwo, e)) {
    cout << " matches" << endl;
    return true;
  }
  
  else {
    cout << " doesn’t match" << endl;
    return false;
 }
        
}


std::list<std::string> deleteMatching(std::list<std::string> myList, std::list<std::string> myNewList) {
  
  std::list<std::string>::iterator it1,it2;
  for(it1=myList.begin(); it1!=myList.end(); ++it1) {
    for(it2=myNewList.begin(); it2!=myNewList.end(); ++it2) {
      if(StringMatcher(*it1, *it2)==true) {
        cout<<"Yeh gaya - " <<*it2<<endl;
        it2 = myNewList.erase(it2);
      }
    }
  }
  for(it1=myNewList.begin(); it1!=myNewList.end(); ++it1) {
    cout<<*it1<<endl;
  }
  cout<< "\nKhatam";
  return myNewList;
}


int main() {
  
  std::list<std::string> referenceList, targetList;
  std::string targetFileName = "files/patchinfo", referenceFileName = "files/reference";
  
  try {
    referenceList = readFile(referenceFileName);
    targetList = readFile(targetFileName);
    targetList = deleteMatching(referenceList, targetList);
    writeFile(targetFileName, targetList);
    cout<< StringMatcher("hi", "hi     ");
  }
  catch (std::exception const& errr) {
    std::cerr << errr.what()<<endl;
    
  }
  catch(const char *e) {
    std::cerr << e;
    
  }

  
}



