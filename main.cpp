#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    setlocale(LC_ALL, "rus");

    string withSpaces = "Hello i am is a cat9 my name is fffRomapppppp ";

    string firstSubstring = "Roma";
    string secondSubstring = "Ivan!";

    int spaceIndex = withSpaces.find(" ");
    int lastIndex = -1;

    string newString = "";

    while (spaceIndex != -1) { // Пока находится пробел, цикл итерирует
        int lastIndexWithSpace = lastIndex + 1; // Получение индекса начала текущего слова
        string currentWord = withSpaces.substr(lastIndexWithSpace, spaceIndex - lastIndexWithSpace); // Получение текущего слова по индексу начала и конца
        int currentWordLength = currentWord.length(); // Вспомогательная переменная

        // Преобразовать массив слов строки, заменив во всех словах первое вхождение первой подстроки на вторую подстроку.
        int firstSubstringIndex = currentWord.find(firstSubstring); // Индекс первого вхождения первой подстроки

        if (firstSubstringIndex != -1) { // Если подстрока найдена
            int firstSubstringLength = firstSubstring.length();

            currentWord.replace(firstSubstringIndex, firstSubstringLength, secondSubstring); // Замена в исходной строке
        }

        // Сформировать предложение из слов, в составе которых есть цифры, предварительно добавив к слову это же перевернутое слово (например, слово “ab9cd” должно войти в предложение в виде “ab9cddc9ba”)
        string numbers = "0123456789";
        int isWordHaveNumber = currentWord.find_first_of(numbers) != -1;

        if (isWordHaveNumber) { // Если в слове есть цифры
            string palendromicBuffer = ""; // Буфер для хранения созданого палендрома
            for(char& word : currentWord) {
                palendromicBuffer.insert(0, 1, word); // Каждая буква слова вставляется в буффер в начало
            }
            currentWord.insert(currentWordLength, palendromicBuffer);
        }

        newString += currentWord + " "; // Формирование новой строки с добавлением пробела

        withSpaces.replace(spaceIndex, 1, "_"); // Замена пробела в исходной строке на другой символ, чтобы можно было производить поиск и не наткнуться на старый пробел

        lastIndex = spaceIndex; // Сохранение индекса пробела
        spaceIndex = withSpaces.find(" "); // Обновление индекса пробела
    }

    cout << newString << endl;

    return 0;
}