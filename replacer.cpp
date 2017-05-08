#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <list>

using namespace std;


class StringList {
  
  public:
   
    StringList(): str(1000000), numberOfStrings(0) {
      ifstream myfile ("replacer.cpp");
      if (myfile.is_open()) {
        for (int i = 0; i < str.size(); i++) {
          getline(myfile, str[i]);
          numberOfStrings++;         
       }
       myfile.close();
        
     }
   }
   
   void getter() {
     cout<<numberOfStrings;
  }
  

  private:
    
    vector<string> str;
    int numberOfStrings;
};


std::list<std::string> readFile(std::string fileName) {
  std::list<string> myFileContent; 
  std::ifstream myFile (fileName);
  if(!myFile) {
    cout<<"File hi nahi hai beta";
  }
  for( std::string line; getline( myFile, line ); ) {
    myFileContent.push_back(line);
    
  }
  myFile.close();
  return myFileContent;
}


std::list<std::string> writeFile(std::string filename, std::list<string> myFileContent) {
  
  std::ofstream myFile (filename);
  if(!myFile) {
    cout<<"File hi nahi hai beta";
  }
  
  for
  myFile.close();
  return myFileList;
}


bool StringMatcher(string stringOne, string stringTwo) {
  regex e (stringOne);
  if (regex_match(stringTwo, e)) {
    cout << " matches" << endl;
    return true;
  }
  
  else {
    cout << " doesn’t match" << endl;
    return false;
 }
        
}


std::list<string> myFun(std::list<string> myList, std::list<string> myNewList) {
  
  std::list<string>::iterator it1,it2;
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
  string hi ("hi");
  string hii ("hi");
  StringList a;
  std::list<string> myList = {"abc", "b", "c"};
  std::list<string> myList1 = {"abcd", "abd", "abc "};
  myFun(myList, myList1);
  readfile("replacer.cpp");
  
}


//function


