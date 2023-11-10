#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream new_file;

    new_file.open("file1.txt",ios::out);
    cout<<"File opened"<<endl;
    cout<<"New file created"<<endl;

    new_file<<"Writing into the file"<<endl;
    new_file.close();
}
