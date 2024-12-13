#include <bits/stdc++.h>
using namespace std;

vector<string> arr[5];

vector<string> keywords = {
    "int", "float", "double", "char", "bool", "void", "while", "for",
    "return", "if", "else", "switch", "case", "break", "continue", 
    "namespace", "using", "class", "private", "public", "protected", 
    "new", "delete", "try", "catch"
};

vector<char> arithmeticOperators = {'+', '-', '*', '/', '%'};
vector<char> punctuators = {
    '{', '}', '[', ']', '(', ')', '<', '>', '.', ',', ';', ':', '?', '#',
    '&', '*', '+', '-', '/', '%', '=', '!', '|', '^', '~'
};

// Function to check if a string is a valid identifier
bool isValidIdentifier(const string& word) {
    if (word.empty()) return false;
    if (!isalpha(word[0]) && word[0] != '_') return false; // Starts with a letter or underscore
    for (char c : word) {
        if (!isalnum(c) && c != '_') return false; // Only alphanumeric or underscores
    }
    return true;
}

// Function to check if a string is a valid constant (integer, float, or character)
bool isConstant(const string& word) {
    // Check for integer constant
    if (all_of(word.begin(), word.end(), ::isdigit)) return true;
    
    // Check for float constant (contains a decimal point)
    if (word.find('.') != string::npos && all_of(word.begin(), word.end(), [](char c) { return isdigit(c) || c == '.'; })) {
        return true;
    }
    
    // Check for character constant (single character enclosed in single quotes)
    if (word.size() == 3 && word[0] == '\'' && word[2] == '\'') {
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
            // Check for arithmetic operators (char)
            if (word.size() == 1 && find(arithmeticOperators.begin(), arithmeticOperators.end(), word[0]) != arithmeticOperators.end()) {
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
    cout << "Arithmetic Operators("<<arr[3].size()<<"): ";
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
