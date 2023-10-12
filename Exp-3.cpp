#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
 fstream file;

 file.open("Assembler.txt",ios::in);
 if(!file.is_open())
 {
  cerr<<"Error : Unable to open the file."<<endl;
  return 0;
 }

 vector<vector<string> > asem;
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
  asem.push_back(words);
 }
 file.close();

 file.open("sic_xe_instructions.txt",ios::in);
 if (!file.is_open())
 {
  cerr << "Error: Unable to open the file." << endl;
  return 1;
 }
 map<string,string> sic;
 while(!file.eof())
 {
  getline(file,line);
  stringstream ss(line);
  string word;
  ss >> word;
  string a = word;
  ss >> word;
  sic[a] = word;
 }

 map<string,int> symbol_table;
 int loc=-1;
 for(int i=0;i<asem.size();i++)
 {
  if(asem[i][0]=="START")
  {
   loc=stoi(asem[i][1]);
   continue;
  }
  else
  if(loc!=-1)
  {
   if(asem[i].size()==3) symbol_table[asem[i][0]]=loc;
   if(asem[i].size()==3)
   {
    if(asem[i][1]=="BYTE") loc++;
    else if(asem[i][1]=="RESB") loc+= stoi(asem[i][2]);
   }
   else
   {
    loc+=3;
   }
  }
 }
 cout<<" SYMBOL TABLE "<<endl<<endl;
 for(auto &it : symbol_table) cout<<it.first<< " --> "<<it.second<<endl;
 cout<<endl;
 file.close();

 return 0;
}
