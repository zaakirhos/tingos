#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void openInputFile(ifstream &inFile)
{
    string filename;
    cout << "What filename? ";
    cin >> filename;
    inFile.open(filename);
    while (!inFile)
    {
        cout << "FILE FAILED TO OPEN" << endl;
        cout << "What filename? ";
        cin >> filename;

        inFile.clear(); //clears the failure flag set by fstream
        inFile.open(filename);
    }
}

struct Student {
    int id;
    double testScore;
    string name;
};

int main()
{
    ifstream input1;
    openInputFile(input1);
    vector<int> v;
    int temp, sum=0;
    /*
    1. each value from the input1 is converted to the appropriate type (type of temp in this case)
    2. eof will not be needed, while will check it for every iteration
    3. >> is the input operator, C++ will: 
        a. skip leafing whitespace chars
        b. Read in "valid" chars (depending on the interested datatype)
        c. stop when reached trailing whitespace or invalid chars
     */
    while (input1 >> temp){
        v.push_back(temp);
    }

    for(int item : v){
        sum += item;
    }
    cout << "The average of the integers in the file is " << sum / v.size() << endl;


    ifstream input2;
    openInputFile(input2);
    vector<Student> vs;
    Student tempStudent;

    while( input2 >> tempStudent.id){ //id is read
        input2 >> tempStudent.testScore; //testScore is read
        input2.ignore(9999, '\t'); // either stop after 9999 chars or skip over first '\t'
        getline(input2, tempStudent.name); // anything after testScore + tab (which is ignored) is read
        vs.push_back(tempStudent);
    }
    for( Student s : vs){
        cout <<"Student name is "<< s.name <<endl;
    }
    return 0;
}
