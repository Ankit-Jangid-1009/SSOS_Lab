#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>

using namespace std;
int main()
{
// ____Opening File Assemblet.txt______

 fstream file;
 file.open("Assembler.txt",ios::in);
 if (!file.is_open())
 {
  cerr << "Error: Unable to open the file." << endl;
  return 1;
 }
// _____Creating a Vector<Vector<string>>______
 vector<vector<string> > assem;
 string line;
//_____Storing Data from file in Vector______
 while (getline(file, line))
 {
  vector<string> words;
  istringstream iss(line);
  string word;
  while (iss >> word)
  {
   words.push_back(word);
  }
  assem.push_back(words);
 }

 file.close();
// ________Printing Given Assembly Code_________
 cout<<"Printing Assembly Code : "<<endl<<endl;
 for(int i=0;i<assem.size();i++)
 {
  for(int j=0;j<assem[i].size();j++)
  {
   cout<<assem[i][j]<<"\t";
  }
  cout<<endl;
 }

 cout<<endl;

//______Ope ning SIC/XE Instruction set file________
 file.open("sic_xe_instructions.txt",ios::in);
 if (!file.is_open())
 {
  cerr << "Error: Unable to open the file." << endl;
  return 1;
 }

// ______Creating Vector from SIC/XE instruction
 vector<vector<string> > sicVec;
 while (getline(file, line))
 {
  vector<string> words;
  istringstream iss(line);
  string word;
  while (iss >> word)
  {
   words.push_back(word);
  }
  sicVec.push_back(words);
 }

 file.close();

// ______Creating map from the Vector________
 map<string,string> sicMap;
 
 for(int i=0;i<sicVec.size();i++)
 {
  sicMap[sicVec[i][0]]=sicVec[i][1];
 }

// _______Finding a replacing opcode mnemonics in Vector Assembler______ 
 map<string,string>::iterator it=sicMap.begin();

 for(int i=0;i<assem.size();i++)
 {
  int j;
  if(assem[i].size()==2)
  {
   j=0;
   it=sicMap.find(assem[i][j]);
   if(it!=sicMap.end())
	assem[i][j] = sicMap[assem[i][j]];
  }
  else
  if(assem[i].size()==3)
  {
   j=1;
   it=sicMap.find(assem[i][j]);
   if(it!=sicMap.end())
	assem[i][j] = sicMap[assem[i][j]];
  }
 }


// ______Printing the Modified assem Vector_________

 cout<<"Printing Modified Assembly Code : "<<endl;
 for(int i=0;i<assem.size();i++)
 {
  for(int j=0;j<assem[i].size();j++)
  {
   cout<<assem[i][j]<<"\t";
  }
  cout<<endl;
 }

//_____Opening File to Modify_______
 ofstream outFile("Assembler.txt", ios::out);
 if (!outFile.is_open())
 {
  cerr << "Error: Unable to open the file." << endl;
  return 1;
 }

//_______modifing File "Assembler.txt"___________
 for (int i = 0; i < assem.size(); i++)
 {
  for (int j = 0; j < assem[i].size(); j++)
  {
   outFile << assem[i][j] << "\t";
  }
  outFile << endl;
 }

 outFile.close();

 return 0;
}
