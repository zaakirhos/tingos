#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ofstream outFile;
    //ios_base:app tells that we want to append rather than overwrite
    outFile.open("elements.txt", ios_base::app);
    outFile << "Francium\n" << endl;

    outFile.close();
    return 0;
}