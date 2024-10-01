#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <getopt.h>

using namespace std;


double summa(const vector<double>& operands) {
    double result = 0;
    for (double operand : operands) {
        result += operand;
    }
    return result;
}


double raznost(const vector<double>& operands) {
    if (operands.size() < 2) {
        cerr << "Ошибка: для операции разности требуется минимум два операнда." << endl;
        exit(1);
    }
    double result = operands[0];
    for (size_t i = 1; i < operands.size(); ++i) {
        result -= operands[i];
    }
    return result;
}

int main(int argc, char* argv[]) {
    
    static struct option long_options[] = {
        {"operation", required_argument, 0, 'o'},
        {0, 0, 0, 0}
    };

    
    string operation;
    vector<double> operands;

    int option_index;
    int c;

    
    while ((c = getopt_long(argc, argv, "o:", long_options, &option_index)) != -1) {
        switch (c) {
            case 'o':
                operation = optarg;
                break;
            default:
                cerr << "Ошибка: Неверный параметр." << endl;
                exit(1);
        }
    }

    
    for (int i = optind; i < argc; ++i) {
        operands.push_back(stod(argv[i]));
    }

    
    if (operation.empty() || operands.empty()) {
        cout << "Справка по использованию:" << endl;
        cout << "  calculator -o <operation> <operand1> <operand2> ..." << endl;
        cout << "  Доступные операции: summa, raznost" << endl;
        return 0;
    }

    
    double result;
    if (operation == "summa") {
        result = summa(operands);
    } else if (operation == "raznost") {
        result = raznost(operands);
    } else {
        cerr << "Ошибка: Неверная операция." << endl;
        exit(1);
    }

    cout << "Результат: " << result << endl;

    return 0;
}
