#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
int main()
{
 fstream file;
 file.open("Assembler.txt",ios::in);
 if (!file.is_open())
 {
  cerr << "Error: Unable to open the file." << endl;
  return 1;
 }

 vector<vector<string> > lines;

 string line;
 while (getline(file, line))
 {
  vector<string> words;
  istringstream iss(line);
  string word;
  while (iss >> word)
  {
   words.push_back(word);
  }
  lines.push_back(words);
 }

 file.close();
 int cnt=0;
 for(int i=0;i<lines.size();i++)
 {
  for(int j=0;j<lines[i].size();j++)
  {
   cout<<lines[i][j]<<"\t";
   cnt++;
  }
  cout<<endl;
 }
 
 cout<<"\nNo. of words in the file : "<<cnt;

 return 0;
}

