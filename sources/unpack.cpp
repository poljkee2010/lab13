#include <string>
#include <iostream>
#include <fstream>

#include "yaml-cpp/yaml.h"

using namespace std;

struct Email {
  string nickname;
  string server;
};

struct Person {
  string  first_name;
  string  last_name;
  Email   email;
  size_t  age;
  string  phone;
};

int main(int argc, char* argv[])
{
   try {     
    string path = argv[1];
    
    ifstream fin(path);
  
    YAML::Node file = YAML::LoadFile(path);

    cout << "First name: " << file["First name"] << "\n";
    cout << "Last name:  " << file["Last name"] << "\n";
    cout << "Email:" << "\n" << file["Email"] << "\n";
    cout << "Phone:      " << file["Phone"] << "\n";
    cout << "Age:        " << file["Age"] << "\n";
  }
  catch(const exception& e) {
    cout << e.what() << endl;
  }
}
