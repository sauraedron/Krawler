/*
Use Wget to download all links from a given HTML File
use ./a.out inputFileName DestinationFolder filter
Author: Saurabh Wankhade 5 June 2016
 */
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>

using namespace std;
int main(int argv, char ** argc)
{
  string srcFile, destFile, filter="pdf";
  vector<string> downloadlinks;
  if(argc[1]==NULL)
    {
      cout<<"InputFileName is Mandatory";
      exit(1);
    }
  else
    srcFile = argc[1];
  if(argc[2]==NULL)
    {
      cout<<"Destination Folder Cannot be empty";
      exit(1);
    }
  else
    destFile = argc[2];   
  
  if(argc[3]==NULL)
    {
      cout<<"Setting Default filter to pdf\n";
    }
  else
    filter=argc[3];
    
  ifstream infile(argc[1]);
  string s;
  string tmp = "cd ";
  tmp.append(destFile);
  while(getline(infile,s))
    {
      int httpstart = s.find("http");

      if(s.find("http")!=string::npos)
	{
	  int httpend = s.find("\">");	  
	  string link = s.substr(httpstart, httpend-httpstart);
	  if(link.find(filter.c_str())!=string::npos)
	    downloadlinks.push_back(link);
	}
    }
  cout<<"A total of "<<downloadlinks.size()<<" files found\nInitiating Download\n";
  for(auto it = downloadlinks.begin(); it!=downloadlinks.end(); ++it)
    {
      string dwl = "wget ";
      dwl.append(*it);
      dwl.append(" -P ");
      dwl.append(destFile);
      cout<<"Executing "<<dwl<<endl;
      system(dwl.c_str());
      cout<<"Finished Executing " <<dwl<<endl;
      
    }
  cout<<"*******************************\n";
  cout<<"    Wget(ed) on "<<downloadlinks.size()<<" files\n";
  cout<<"*******************************\n";



}
