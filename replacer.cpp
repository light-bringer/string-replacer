#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <list>
#include <stdexcept>


using namespace std;

std::string delSpaces(std::string &str) 
{
   str.erase(std::remove(str.begin(), str.end(), ' '), str.end());
   return str;
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
  std::regex e (delSpaces(stringOne));
  if (regex_match(delSpaces(stringTwo), e)) {
    cout << " matches" << endl;
    return true;
  }
  
  else {
    cout << " doesn’t match" << endl;
    return false;
 }
        
}


std::list<std::string> myFun(std::list<std::string> myList, std::list<std::string> myNewList) {
  
  std::list<std::string>::iterator it1,it2;
  it1 = myList.begin();
  for(it1=myList.begin(); it1!=myList.end(); ++it1) {
    cout<<*it1<<endl;
    for(it2=myNewList.begin(); it2!=myNewList.end(); ++it2) {
      if(StringMatcher(*it1, *it2)==true) {
        cout<<"Yeh gaya - " <<*it2<<endl;
        it2=myNewList.erase(it2);
      }
    }
  }
  for(it1=myNewList.begin(); it1!=myNewList.end(); ++it1) {
    cout<<*it1<<endl;
  }
  cout<< "Khatam";
  return myNewList;
}


int main() {
  
  std::list<std::string> referenceList, targetList;
  std::string targetFileName = "files/patchinfo", referenceFileName = "files/reference";
  
  try {
    referenceList = readFile(referenceFileName);
    targetList = readFile(targetFileName);
    targetList = myFun(referenceList, targetList);
    writeFile(targetFileName, targetList);
  }
  catch (std::exception const& errr) {
    std::cerr << errr.what()<<endl;
    
  }
  catch(const char *e) {
    std::cerr << e;
    
  }

  
}



