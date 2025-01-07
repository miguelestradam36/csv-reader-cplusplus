#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

vector <string> split(string line, char delim) {
  vector<string> tokens;
  int end = 0;
  const char* ws = " \t\n\r\f\v";
  int a = line.size();
  while (end < a) {
    int start = end;
    end = line.find(delim,start);
    if (end<0) end = line.size();
    string token = line.substr(start,end++-start);
    token.erase(token.find_last_not_of(ws) + 1);
    tokens.push_back(token);
  }
  return tokens;
}

void writeHTML(vector<vector<string>> &columns, string filename) {  
  ofstream file(filename);
  file << "<html><table><thead><tr>";
  int m = columns.size();
  for (int i=0;i<m;i++)
    file<<"<td>"<<columns[i][0]<<"</td>";
  file << "</tr></thead><tbody>";
  int n = columns[0].size();
  for (int i=1;i<n;i++) {
    file<<"<tr>";
    for (int j=0;j<m;j++) {
      file<<"<td>"<<columns[j][i]<<"</td>";
    }
    file<<"</tr>";
  }  
  file << "</tbody></table></html>";
  file.close();
}

vector<vector<string>> filterCategory(vector<vector<string> > &columns,string category){
  vector<vector<string>> vectorCategories;
  int n = columns[0].size();
  int m = columns.size();
  for (int i=1;i<n;i++){
    for (int j=0;j<m;j++){
      if (columns[2][i]== category) 
        vectorCategories[i].push_back(columns[j][i]);
    }
  }
return vectorCategories;
}

void readCSV(vector<vector<string> > &columns, string filename, char delim) {  
  ifstream file(filename);
  if (file.is_open()) {  
    string line;
    bool firstRow = true;
    while (getline(file, line)) {  
      vector<string> values = split(line,delim); 
      int b = values.size(); 
      for (int i=0;i<b;i++) 
      {  
        if (firstRow) {
          vector<string> column;  
          columns.push_back(column);
        };
        if (i==0){
          columns[i].push_back(values[i]+values[i++]);
          i++;
        }
        columns[i].push_back(values[i]);
      }
      firstRow = false;
    }  
    file.close();
  }
}

int main() {  
  vector <vector<string> > columns;  
  readCSV(columns, "data.csv",',');
  writeHTML(columns, "data.html");
  string category = "HIV/AIDS";
  vector <vector<string> > modified = filterCategory(columns,category);
  writeHTML(modified, "data.html");
  //filterState(columns,string state);
  //filterCounty(columns,string county);
  return 0;
}
