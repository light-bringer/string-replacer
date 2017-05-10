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
    throw "File does not exist!";
  }
  //myFile.exceptions (ifstream::failbit | ifstream::badbit );
  try {
    for(std::string line; std::getline( myFile, line ); ) {
      myFileContent.push_back(line);
    }
  }
  catch(std::exception const& e) {
    cout << "There was an error: " << e.what() << endl;
  }

  myFile.close();
  
  return myFileContent;

  
}



void writeFile(std::string filename, std::list<std::string> myFileContent) {
    
    /* Function which takes a file name and FileContent as string list a parameter and 
   * writes all its content element per element
   *
   * INPUT - filename , std::std::string
   * OUTPUT - list of filecontent, std::list<std::std::string>
   * throws File not found exception error when file is not present
   */
  
  std::ofstream myFile (filename);
  if(!myFile) {
    throw "File not found";
  }
  for( auto iterator = myFileContent.begin() ; iterator != myFileContent.end() ; ++iterator ) {
    myFile << *iterator << '\n' ;
  }
  myFile.close();

}


bool StringMatcher(std::string stringOne, std::string stringTwo) {
    
    /* Matches two strings by trimming the forward and trailing spaces
     * and returns true if matched else returns false
     */
  
  std::string regexString = "(\\s*)("+ trimmed(stringOne) + ")(\\s*)";
  std::regex e (regexString);
  //std::regex e (stringOne);
  if (regex_match(stringTwo, e))
    return true;
  else 
    return false;
        
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
  return myNewList;
}


int main(int argc, char* argv[]) {
  if (argc < 5) { // Check the value of argc. If not enough parameters have been passed, inform user and exit.
    std::cout << "Usage is -ref <referencefile> -patch <patchinfofile>\n"; // Inform the user of how to use the program
    std::cin.get();
    exit(0);
  }
  else { // if we got enough parameters...
    std::string refFile, patchPath;
    std::cout << argv[0] << endl;
    std::cout << argv[1] << endl;
    std::cout << argv[2] << endl;
    std::cout << argv[3] << endl;
    std::cout << argv[4] << endl;
    for (int i = 1; i < argc; i++) {
      if (i + 1 != argc) {// Check that we haven't finished parsing already
        if (std::string(argv[i]) == "-r") {
          refFile = argv[i + 1];
          ++i;
        }
        else if (std::string(argv[i]) == "-p") {
          patchPath = argv[i + 1];
          ++i;
        }
        else {
          std::cout << "Not enough or invalid arguments, please try again.\n"; 
          exit(0);
        }
        cout<<argv[i];
      }
    }
  
    std::list<std::string> referenceList, targetList;
    std::string targetFileName = patchPath, referenceFileName = refFile;
    
    try {
        referenceList = readFile(referenceFileName);
        targetList = readFile(targetFileName);
        targetList = deleteMatching(referenceList, targetList);
        writeFile(targetFileName, targetList);
    }
    catch (std::exception const& errr) {
        std::cerr << errr.what()<<endl;
        
    }
    catch(const char *e) {
        std::cerr << e;
        
    }
    
    return 0;

  }
  
}



