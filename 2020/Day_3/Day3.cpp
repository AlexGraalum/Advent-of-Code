#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int checkTrees(vector<string>, int, int);

int main() {
     ifstream treeLog;
     string temp;
     int x = 0, j = 1;
     vector<string> treeMap;
     vector<int> treeCount;
     string str;

     treeLog.open("Trees.txt");
     if (treeLog.is_open()) {
          while (getline(treeLog, temp)) {
               treeMap.push_back(temp);
          }
     }
     else {
          cout << "ERROR: File not found. Aborting!\n\n";
          return -1;
     }
     treeLog.close();

     treeCount.push_back(checkTrees(treeMap, 1, 1));
     treeCount.push_back(checkTrees(treeMap, 3, 1));
     treeCount.push_back(checkTrees(treeMap, 5, 1));
     treeCount.push_back(checkTrees(treeMap, 7, 1));
     treeCount.push_back(checkTrees(treeMap, 1, 2));

     cout << "Right 3, Down 1: " << treeCount[0] << endl;
     cout << "Right 3, Down 1: " << treeCount[1] << endl;
     cout << "Right 5, Down 1: " << treeCount[2] << endl;
     cout << "Right 7, Down 1: " << treeCount[3] << endl;
     cout << "Right 1, Down 2: " << treeCount[4] << endl;

     for (int i = 0; i < treeCount.size(); i++) {
          cout << j << " * " << treeCount[i] << " = ";
          j *= treeCount[i];
          cout << j << endl;
     }

     cout << (unsigned int)j << endl;

     return 0;
}

int checkTrees(vector<string> treeMap, int right, int down) {
     int j = 0, x = 0;
     for (size_t i = 0; i < treeMap.size(); i += down) {
          string temp = treeMap.at(i);

          if (temp.at(j) == '#') {
               x++;
          }
          if (j + right > temp.length()) {
               j = j + right - temp.length();
          }
          else if (j + right == temp.length()) {
               j = 0;
          }
          else {
               j += right;
          }
     }
     return x;
}