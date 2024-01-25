#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <regex>
using namespace std;


string cutAndAdd(string inputString) {
  string cutString = inputString.substr(2);
    string newString = "1 " + cutString;
    return newString;
}

int getnumber(const string &liniuta) {
    size_t space_index = liniuta.find(' ');
    string linienoua;
    int num;
    if (space_index != string::npos) {
        linienoua = liniuta.substr(0, space_index);

        std::stringstream sstr(linienoua);
        
        if (sstr >> num && sstr.eof()) {
            return num;
        }
        else {
            throw std::invalid_argument("Invalid number format");
        }
    }
    else {
        throw std::invalid_argument("No number found");
    }
    num = stoi(linienoua);
    return num;
}

void depack_multiple_rows(string filename) {
    ifstream inputfile(filename);
    ofstream outputinput("input_processed.txt");
    if (!inputfile.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }
    
    int startingnumber;
    string line;
    while (getline(inputfile, line)) {
        
        cout << line << "\n";
        if (line.empty()||isspace(line[0])||line=="\n"|| line.empty() || line == "\r" || line == "\n" || line == "\r\n") {
            continue;
        }
        startingnumber = getnumber(line);
        cout << startingnumber<<'\n';
        if (startingnumber == 1) {
            outputinput << line << "\n";
        }
        else
        {
            regex expression(R"(\d+)");
            string replacement = "1";

            line = regex_replace(line, expression, replacement);

           
            for (int i = 0; i < startingnumber; i++) {
                outputinput << line << "\n";
            }
        }
    }

}


void processFile(string filename) {
    ifstream inputFile(filename);
    ofstream outputFile("output.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening file " << filename << endl;
        return;
    }

    int rowNum = 0;
    string line;


    while (getline(inputFile, line)) {
     
        

        // Insert "BACK" rows if necessary
      /*  if (rowNum % 9 == 0 && hasComment) {
            hasComment = false;

            // Insert the text after comment
            for (int i = 0; i < commentsAfterRow.length(); i++) {
                outputFile << commentsAfterRow[i];
            }
        }*/ 
        outputFile << line << "\n";
        rowNum++;

         if (rowNum % 9 == 0) {
            for (int i = 0; i < 9; i++) {
                outputFile << "1 Back (EXTRA) 001\n";
                rowNum = 0;
            }
        }



      
    }

    inputFile.close();
    outputFile.close();
}

int main() {
    depack_multiple_rows("input.txt");
   processFile("input_processed.txt");

    return 0;
}
/*#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main() {
    // Open input file
    ifstream inputFile("input.txt");

    // Read number of rows
    int rows;
    inputFile >> rows;
    cout << rows;

    // Initialize line counter and repeat counter
    int lineCount = 0;
    int repeatCount = 1;

    // Read and process lines
    while (lineCount < rows) {
        // Read line
        string line;
        getline(inputFile, line);

        // Extract number and check if it's greater than 1
        int number;
        istringstream iss(line);
        iss >> number;
        if (number > 1) {
            // Repeat the line multiple times
            for (int i = 0; i < number - 1; i++) {
                cout << line << endl;
            }

            // Repeat the line once with number changed to 1
            cout << "1 " << line.substr(2) << endl;

            // Skip the specified number of lines
            for (int i = 0; i < number; i++) {
                getline(inputFile, line);
                lineCount++;
            }

            // Reset repeat counter
            repeatCount = 1;
        }
        else {
            // Just print the line as is
            cout << line << endl;
        }

        // Check for EXTRA section
        if (lineCount % 9 == 0) {
            // Print nine EXTRA lines
            for (int i = 0; i < 9; i++) {
                cout << "1 Back (EXTRA) 001\n";
            }
        }

        // Increment line count
        lineCount++;
    }

    // Close input file
    inputFile.close();

    return 0;
}*/