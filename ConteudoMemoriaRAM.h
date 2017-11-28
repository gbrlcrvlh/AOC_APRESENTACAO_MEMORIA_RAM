#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char** argv)
{
   char c;
   unsigned long int offset=0;
   ifstream curFile("/dev/mem");
   ofstream fout("fileDump");
   while(!curFile.eof() && !curFile.fail())
   {
      curFile.get(c);
      if(c>31 && c<127)
      {
         fout.put(c);
         offset++;
      }
      if(offset==80)
      {
         fout.put('\n');
         offset=0;
      }
   }
   curFile.close();
   fout.close();
}