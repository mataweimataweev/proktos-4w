#include <iostream>
#include <string>
#include <algorithm>
#include <random>

// Функция для переворачивания слова задом наперед
std::string reverseWord(std::string word) {
    std::reverse(word.begin(), word.end());
    return word;
}

// Функция для удаления гласных букв из слова
std::string removeVowels(std::string word) {
    std::string vowels = "aeiouAEIOU";
    word.erase(std::remove_if(word.begin(), word.end(),
        [&vowels](char c) { return vowels.find(c) != std::string::npos; }),
        word.end());
    return word;
}

// Функция для удаления согласных букв из слова
std::string removeConsonants(std::string word) {
    std::string consonants = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
    word.erase(std::remove_if(word.begin(), word.end(),
        [&consonants](char c) { return consonants.find(c) != std::string::npos; }),
        word.end());
    return word;
}

// Функция для перемешивания букв в слове
std::string shuffleWord(std::string word) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(word.begin(), word.end(), g);
    return word;
}

int main() {
    std::string word;
    std::cout << "Enter the word: ";
    std::cin >> word;

    int choice;
    std::cout << "Select an action:" << std::endl;
    std::cout << "1. The word is displayed backwards." << std::endl;
    std::cout << "2. Print a word without vowels." << std::endl;
    std::cout << "3. Print a word without consonants." << std::endl;
    std::cout << "4. Randomly scatter the letters of a given word." << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Result= " << reverseWord(word) << std::endl;
        break;
    case 2:
        std::cout << "Result=" << removeVowels(word) << std::endl;
        break;
    case 3:
        std::cout << "Result=" << removeConsonants(word) << std::endl;
        break;
    case 4:
        std::cout << "Result= " << shuffleWord(word) << std::endl;
        break;
    default:
        std::cout << "Incorrect choice of action." << std::endl;
    }

    return 0;
}