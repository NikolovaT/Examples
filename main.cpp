#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string get_file(string filename){
    ifstream file;

    file.open(filename.c_str());

    if(file.fail()) return "File failed to open.";

    stringstream buffer;
    buffer << file.rdbuf();
    file.close();

    return buffer.str();
}

string get_line(string filename, int line_num){
    ifstream file;
    if(line_num <= 0) return "Line number must be greater than 0.";

    file.open(filename.c_str());
    if(file.fail()) return "File failed to open.";

    int current_line = 0;
    string line;

    while(!file.eof()){
        current_line++;
        getline(file, line);
        if(current_line == line_num) break;
    }

    file.close();

    if(current_line < line_num) return "Line not found.";

    return line;
}

int main()
{
    string filename;
    int line_num;
    cout<< "File: ";
    cin>>filename;

    cout<<"Line: ";
    cin>>line_num;

    string f1 = get_line(filename, line_num);
    cout<<f1<<endl;


    string f2 = get_file("text.txt");
    cout<<f2<<endl;

    return 0;
}
