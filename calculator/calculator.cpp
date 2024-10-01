#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

void showHelp() {
    std::cout << "Использование: ./calculator -o <операция> <операнд1> <операнд2> [операнд3] [операнд4]\n";
    std::cout << "Доступные операции:\n";
    std::cout << "- summa: суммирование\n";
    std::cout << "- raznost: вычитание (из первого операнда все остальные)\n";
}

double calculateSumma(const std::vector<double>& operands) {
    return std::accumulate(operands.begin(), operands.end(), 0.0);
}

double calculateRaznost(const std::vector<double>& operands) {
    if (operands.size() < 2) {
        std::cerr << "Ошибка: для операции разности требуется минимум два операнда." << std::endl;
        return 0;
    }
    double result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        showHelp();
        return 1;
    }

    std::string operation = argv[2];
    std::vector<double> operands;

    for (int i = 3; i < argc; ++i) {
        operands.push_back(std::stod(argv[i]));
    }

    
    if (operands.size() < 2 || operands.size() > 4) {
        std::cout << "Ошибка: количество операндов должно быть от 2 до 4." << std::endl;
        return 1;
    }

    
    if (operation == "summa") {
        double result = calculateSumma(operands);
        std::cout << "Сумма: " << result << std::endl;
    } else if (operation == "raznost") {
        double result = calculateRaznost(operands);
        std::cout << "Разность: " << result << std::endl;
    } else {
        showHelp();
    }

    return 0;
}
