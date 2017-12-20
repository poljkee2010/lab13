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

      cout << "[Person]" << endl;
      cout << "First name: " << file.first_name << endl;
      cout << "Last name:  " << file.last_name << endl;
      cout << "Email:      " << file.email.nickname << endl;
      cout << "Age:        " << file.age << endl;
      cout << "Phone:      " << file.phone << endl;
  }
  catch(const exception& e) {
    cout << e.what() << endl;
  }
}
