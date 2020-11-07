#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    setlocale(LC_ALL, "rus");

    string line;

    ifstream file("../file.txt");
    ofstream outFile("../out.txt");

    string maxLengthLine;
    int maxLengthLineLength = 0;
    int maxLengthLineNumber = -1;

    vector<string> lines;

    int lineCount = 0;

    string sentence;
    bool isSentenceFinded = false;

    getline(file, line);
    while (true) {
        int wordsCount = 0;
        int letterInWordCount = 0;
        int letterInLineCount = 0;
        string newLine;

        for(char& c : line) {
            letterInLineCount++;

            if (!isSentenceFinded) {
                sentence += c;
            }

            // Задание 1
            if (c == ' ' || letterInLineCount >= line.length()) {
                if (letterInWordCount > 0) {
                    wordsCount++;
                }
            } else {
                letterInWordCount++;
            }

            // Задание 6
            if (c != '.') {
                newLine += c;
            } else if (!isSentenceFinded) {
                // Задание 21
                cout << "Первое предложение: " << sentence << endl;
                isSentenceFinded = true;
            }
        }

        lineCount++;
        lines.push_back(newLine);

        // Задание 11
        if (maxLengthLineLength < letterInLineCount) {
            maxLengthLine = line;
            maxLengthLineLength = letterInLineCount;
            maxLengthLineNumber = lineCount;
        }

        // Задание 1
        cout << "Сиволов в строке: " << wordsCount << "\n";
        // Задание 6
        cout << "Текст без точек: " << newLine << endl;

        if (!getline(file, line)) break;
    }

    // Задание 11
    cout << maxLengthLine << ": " << maxLengthLineNumber << endl;

    // Задание 16
    int outLineCount = 0;
    for (auto& line : lines) {
        if (outLineCount != maxLengthLineNumber) {
            outFile << line << endl;
        }
        outLineCount++;
    }


    outFile.close();
    file.close();

    return 0;
}