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

Person getInfo() {
	struct Person file;
	cout << "Enter data to fields of the Person structure." << endl;
	
	cout << "First name:" << endl;
	cin >> file.first_name;
	
	cout << "Last name:" << endl;
	cin >> file.last_name;
	
	cout << "Email:" << endl;
	cin >> file.email.nickname;
	
	cout << "Age:" << endl;
	cin >> file.age;
	
	cout << "Phone:" << endl;
	cin >> file.phone;
  return file;
}


int main(int argc, char* argv[]) {
  try {
    string Path = argv[1];
    Person file = getInfo();
    YAML::Node node;
    node["person"]["First name"] = file.first_name;
    node["person"]["Last name"] = file.last_name;
    node["person"]["Email"] = file.email.nickname;
    node["person"]["Age"] = file.age;
    node["person"]["Phone"] = file.phone;
    ofstream fout(Path);
    fout << node;
    return 0;
  }
  catch(const exception& e) {
    cout << e.what() << endl;
  }
}
