#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int uniqueAnswers(string );

int main() {
     ifstream questionAnswers;
     string str, temp;
     int x = 0;

     questionAnswers.open("Answers.txt");
     if (questionAnswers.is_open()) {
          temp = "";
          while (getline(questionAnswers, str)) {
               if (str == "") {
                    x += uniqueAnswers(temp);
                    temp = "";
               }
               else {
                    temp += str;
               }
          }
     }
     else {
          cout << "ERROR: File not found. Aborting!\n\n";
          return -1;
     }

     cout << "Total answers: " << x << endl;

     return 0;
}

int uniqueAnswers(string str) {
     unordered_map<char, int> m;

     for (size_t i = 0; i < str.length(); i++) {
          m[str[i]]++;
     }

     return m.size();
}