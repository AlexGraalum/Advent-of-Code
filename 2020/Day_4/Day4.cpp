#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <regex>

using namespace std;

const string elements[7] = { "byr:", "iyr:", "eyr:", "hgt:", "hcl:", "ecl:", "pid:" };
const vector<string> eye = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };

struct passport {
     int byr, iyr, eyr, hgt;
     string hgtUnit, hcl, ecl, pid;

     passport() {
          byr = 0;
          iyr = 0;
          eyr = 0;
          hgt = 0;
          hgtUnit = " ";
          hcl = " ";
          ecl = " ";
          pid = " ";
     }

     passport(string temp) {
          string str;
          byr = stoi(temp.substr(temp.find(elements[0]) + 4, 4));

          iyr = stoi(temp.substr(temp.find(elements[1]) + 4, 4));

          eyr = stoi(temp.substr(temp.find(elements[2]) + 4, 4));

/*          int pos = temp.find(elements[3]);
          str = temp.substr(pos + 4, temp.find_first_of(pos, ' '));

          cout << "Height: " << str << endl;
          if (str.find("in")) {
               hgtUnit = "in";
               hgt = stoi(str);
          } else if(str.find("cm")){
               hgtUnit = "cm";
               hgt = stoi(str);
          }
          else {
               hgtUnit = "";
               hgt = 0;
          }*/



          str = temp.substr(temp.find(elements[4]) + 5, 6);
          hcl = str;
          /*regex pattern("[a-f0-9]");
          if (regex_match(str, pattern)) {
               hcl = str;
          }*/


          str = temp.substr(temp.find(elements[5]) + 4, 3);
          if (find(eye.begin(), eye.end(), str) != end(eye)) {
               ecl = str;
          }

          str = temp.substr(temp.find(elements[6]) + 4, 9);
          if (str.find_first_of("0123456789") != string::npos) {
               pid = str;
          }
     }
};

int present(string);
int valid(passport *);

int main() {
     ifstream passPorts;
     string str, temp;
     vector<passport *> portList;
     int x = 0;

     passPorts.open("Passports.txt");
     if (passPorts.is_open()) {
          temp = "";
          while (getline(passPorts, str)) {
               if (str == "") {
                    if (present(temp)) {
                         passport *t = new passport(temp);
                         portList.push_back(t);
                    }
                    temp = "";
               }
               else {
                    temp += str + " ";
               }
          }
     }
     else {
          cout << "ERROR: File not found. Aborting!\n\n";
          return -1;
     }

     for (size_t i = 0; i < portList.size(); i++) {
//          x += valid(portList[i]);

          cout << "Passport Information: \n";
          cout << "byr: " << portList[i]->byr << endl;
          cout << "iyr: " << portList[i]->iyr << endl;
          cout << "eyr: " << portList[i]->eyr << endl;
          cout << "hgt: " << portList[i]->hgt << " " << portList[i]->hgtUnit << endl;
          cout << "hcl: " << portList[i]->hcl << endl;
          cout << "ecl: " << portList[i]->ecl << endl;
          cout << "pid: " << portList[i]->pid << endl;
          cout << endl;
     }

     cout << "Passports with present information: " << portList.size() << endl;
     cout << "Passports with valid information: " << x << endl;
     return 0;
}

int present(string temp) {
     for (int i = 0; i < 7; i++) {
          if (temp.find(elements[i]) == string::npos)
               return 0;
     }
     return 1;
}

int valid(passport *pass) {
     if (pass->byr == NULL) {
          return 0;
     }
     else if (pass->byr < 1920 || pass->byr > 2002) {
          return 0;
     }

     if (pass->iyr == NULL) {
          return 0;
     }
     else if (pass->iyr < 2010 || pass->iyr > 2020) {
          return 0;
     }

     if (pass->eyr == NULL) {
          return 0;
     }
     else if (pass->eyr < 2020 || pass->eyr > 2030) {
          return 0;
     }

     if (pass->hgt == NULL) {
          return 0;
     }
     else {
          if (pass->hgtUnit == "cm") {
               if (pass->hgt < 150 || pass->hgt > 193)
                    return 0;
          }
          else if (pass->hgtUnit == "in") {
               if (pass->hgt < 59 || pass->hgt > 76)
                    return 0;
          }
          else {
               return 0;
          }
     }

     return 1;
}