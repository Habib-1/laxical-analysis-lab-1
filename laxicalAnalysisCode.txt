#include <bits/stdc++.h>
using namespace std;

vector<string> arr[5];


vector<string> keywords = {
    "int", "float", "double", "char", "bool", "void", "while", "for",
    "return", "if", "else", "switch", "case", "break", "continue", 
    "namespace", "using", "class", "private", "public", "protected", 
    "new", "delete", "try", "catch","string",
};


vector<char> Operators = {'+', '-', '*', '/', '%','='};


vector<char> punctuators = {
    '{', '}', '[', ']', '(', ')', '<', '>', '.', ',', ';', ':', '?', '#',
    '&', '*', '+', '-', '/', '%', '!', '|', '^', '~'
};


bool isValidIdentifier(const string& word) {
    if (word.empty()) return false;  
    if (!isalpha(word[0]) && word[0] != '_') return false; 
    for (char c : word) {
        if (!isalnum(c) && c != '_') return false; 
    }
    return true;
}



bool isConstant(const std::string& word) {
    // Check for integer constant (positive or negative)
    if (!word.empty() && (word[0] == '-' || std::isdigit(word[0])) &&
        all_of(word.begin() + 1, word.end(), ::isdigit)) {
        return true;
    }

    // Check for float constant (positive or negative, contains a decimal point)
    size_t dotCount = std::count(word.begin(), word.end(), '.');
    if (dotCount == 1 && !word.empty() && (word[0] == '-' || isdigit(word[0])) &&
       all_of(word.begin() + 1, word.end(), [](char c) { return isdigit(c) || c == '.'; })) {
        return true;
    }

    // Check for character constant (single character enclosed in single quotes)
    if (word.size() == 3 && word[0] == '\'' && word[2] == '\'' && isprint(word[1])) {
        return true;
    }

    return false;
}


int main() {
    // array of vector er 
    // arr[0] -> keywords
    // arr[1] -> identifier
    // arr[2] -> constant
    // arr[3] -> arithmetic operator
    // arr[4] -> punctuations
    
    string s;
    getline(cin, s);
    stringstream ss(s);
    string word;

    while (ss >> word) {
        // Check for keywords
        
        if ( find(keywords.begin(), keywords.end(), word)!=keywords.end()) {
            arr[0].push_back(word);
        }
        else {
            // Check for  operators (char)
            if (word.size() == 1 && find(Operators.begin(), Operators.end(), word[0]) != Operators.end()) {
                arr[3].push_back(word);
            }
            // Check for punctuators (char)
            else if (word.size() == 1 && find(punctuators.begin(), punctuators.end(), word[0]) != punctuators.end()) {
                arr[4].push_back(word);
            }
            // Check if it's a valid identifier
            else if (isValidIdentifier(word)) {
                arr[1].push_back(word);
            }
            // Check if it's a constant (integer, float, or character)
            else if (isConstant(word)) {
                arr[2].push_back(word);
            }
        }
    }

    // Output keywords
    cout << "Keywords("<<arr[0].size()<<"): ";
    for (const string& c : arr[0]) {
        cout << c << " ";
    }
    cout << endl;

    // Output arithmetic operators
    cout << "Operators("<<arr[3].size()<<"): ";
    for (const string& c : arr[3]) {
        cout << c << " ";
    }
    cout << endl;

    // Output punctuators
    cout << "Punctuators("<<arr[4].size()<<"): ";
    for (const string& c : arr[4]) {
        cout << c << " ";
    }
    cout << endl;

    // Output identifiers
    cout << "Identifiers("<<arr[1].size()<<"): ";
    for (const string& c : arr[1]) {
        cout << c << " ";
    }
    cout << endl;

    // Output constants
    cout << "Constants("<<arr[2].size()<<"): ";
    for (const string& c : arr[2]) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
