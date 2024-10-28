#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <cstdlib>

using namespace std;

// Функция для вывода справки
void showHelp() {
    cout << "Использование: calculator [-o operation] [operand1] [operand2] ..." << endl;
    cout << "Допустимые операции: summa, vychitanie" << endl;
    cout << "Пример: calculator -o summa 45 13 -2" << endl;
}

// Функция для суммирования
double summa(const vector<double>& operands) {
    double result = 0;
    for (double operand : operands) {
        result += operand;
    }
    return result;
}

// Функция для вычитания
double vychitanie(const vector<double>& operands) {
    if (operands.empty()) {
        return 0;
    }
    double result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}

int main(int argc, char* argv[]) {
    // Проверка на наличие параметров
    if (argc < 2) {
        showHelp();
        return 0;
    }

    // Обработка параметров
    string operation;
    vector<double> operands;
    for (int i = 1; i < argc; ++i) {
        string arg = argv[i];
        if (arg == "-o" || arg == "--operation") {
            if (++i < argc) {
                operation = argv[i];
            } else {
                cerr << "Ошибка: отсутствует операция." << endl;
                return 1;
            }
        } else {
            try {
                operands.push_back(stod(arg));
            } catch (const std::invalid_argument& e) {
                cerr << "Ошибка: неверный формат операнда." << endl;
                return 1;
            } catch (const std::out_of_range& e) {
                cerr << "Ошибка: операнд вне диапазона." << endl;
                return 1;
            }
        }
    }

    // Проверка количества операндов
    if (operands.size() < 2 || operands.size() > 4) {
        cerr << "Ошибка: недопустимое количество операндов." << endl;
        return 1;
    }

    // Выполнение операции
    double result;
    if (operation == "summa") {
        result = summa(operands);
    } else if (operation == "vychitanie") {
        result = vychitanie(operands);
    } else {
        cerr << "Ошибка: неподдерживаемая операция." << endl;
        return 1;
    }

    // Вывод результата
    cout << "Результат: " << result << endl;

    return 0;
}

