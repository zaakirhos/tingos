#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile; //same as ofstream outFile("filename")
    outFile.open("outfile.txt");

    outFile << "This text will go to the outfile.txt" << endl;
    
    return 0;
}
