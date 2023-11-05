#include <iostream>
using namespace std;
void printWords(int iterations, string inputString)
{
  if (inputString.size()>=1 && 
      inputString.size()<=50 && 
      iterations>0 && 
      iterations<100)
  {
    for (int i=0;i<iterations;i++)
    {
      cout<<inputString<<endl;
    }
  }
}
int main() {
  
    // Digest iteration input from command line
    int iterations = 3;
    // cin>>iterations;

    // Digest word input from command line
    string word = "stuff";
    // cin>>word;

    // Input into the printWords function
    printWords(iterations,word);
    return 0;
}