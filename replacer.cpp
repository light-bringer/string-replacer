#include <iostream>
#include <fstream>
#include <string>
#include <regex>


using namespace std;

bool StringMatcher(string stringOne, string stringTwo) {
  regex e (stringOne);
  cout<<"Here"<<stringOne;
  if (regex_match(stringOne, e)) {
    cout << " matches" << endl;
    return true;
  }
  
  else {
    cout << " doesn’t match" << endl;
    return false;
 }
        
}

int main() {
  string hi ("hi");
  string hii ("hii");
  cout<<hi<<StringMatcher(hi, hii);
    
    
}