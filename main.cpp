#include <iostream>
#include <vector>
#include <cstdlib>

void getCombination(std::vector<int>& combination) {
    std::cout << "Игрок 1, введите комбинацию из 4 чисел от 1 до 6: ";
    for (int i = 0; i < 4; ++i) {
        int num;
        std::cin >> num;
        while (num < 1 || num > 6) {
            std::cout << "Число должно быть от 1 до 6. Повторите ввод: ";
            std::cin >> num;
        }
        combination.push_back(num);
    }
    std::system("clear"); 
}

void evaluateGuess(const std::vector<int>& secret, const std::vector<int>& guess, int& correctPlace, int& correctNumber) {
    correctPlace = 0;
    correctNumber = 0;
    std::vector<bool> usedSecret(4, false), usedGuess(4, false);

    for (int i = 0; i < 4; ++i) {
        if (guess[i] == secret[i]) {
            ++correctPlace;
            usedSecret[i] = true;
            usedGuess[i] = true;
        }
    }

    for (int i = 0; i < 4; ++i) {
        if (!usedGuess[i]) {
            for (int j = 0; j < 4; ++j) {
                if (!usedSecret[j] && guess[i] == secret[j]) {
                    ++correctNumber;
                    usedSecret[j] = true;
                    break;
                }
            }
        }
    }
}

int main() {
    std::vector<int> secretCombination;
    getCombination(secretCombination);

    std::cout << "Игрок 2, вам нужно угадать комбинацию за 6 попыток!" << std::endl;

    for (int attempt = 1; attempt <= 6; ++attempt) {
        std::cout << "Попытка " << attempt << ": введите вашу комбинацию из 4 чисел от 1 до 6: ";
        std::vector<int> guess(4);
        for (int i = 0; i < 4; ++i) {
            std::cin >> guess[i];
            while (guess[i] < 1 || guess[i] > 6) {
                std::cout << "Число должно быть от 1 до 6. Повторите ввод: ";
                std::cin >> guess[i];
            }
        }

        int correctPlace = 0, correctNumber = 0;
        evaluateGuess(secretCombination, guess, correctPlace, correctNumber);

        if (correctPlace == 4) {
            std::cout << "Поздравляю! Вы угадали комбинацию!" << std::endl;
            return 0;
        }

        std::cout << "Чисел на своих местах: " << correctPlace << std::endl;
        std::cout << "Числа правильные, но не на своих местах: " << correctNumber << std::endl;
    }

    std::cout << "Вы проиграли! Загаданная комбинация: ";
    for (int num : secretCombination) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
