#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

ofstream fout ("output.txt");

void printLine(string line)
{
    for (int i = 0; i < line.size(); i++)
        if (line[i] != '-') fout << line[i];
        else if (line[i] == '-') fout << "=";
}

int main()
{
    ifstream fin ("cpzcombined.fasta");

    string line; int counter;
    while (fin >> line) {
        if (line[0] == '>') {
            fout << endl << line << endl;
            counter = 0;
        }

        else if (counter < 10 && line[0] != '-') {
            counter++;
            printLine(line);
        }
    }

}
