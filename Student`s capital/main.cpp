#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Структура для хранения информации о ноутбуке
struct Laptop {
    int index;
    int price;
    int gain;
};

// Функция для максимизации капитала
int maximize_capital(int N, int C, vector<int>& gains, vector<int>& prices) {
    vector<Laptop> laptops;

    // Создаем список ноутбуков
    for (int i = 0; i < gains.size(); ++i) {
        laptops.push_back({ i, prices[i], gains[i] });
    }

    // Сортируем ноутбуки по соотношению прибыль/цена в порядке убывания
    sort(laptops.begin(), laptops.end(), [](const Laptop& a, const Laptop& b) {
        return (double)a.gain / a.price > (double)b.gain / b.price;
        });

    int total_capital = C;
    int laptops_bought = 0;

    for (const auto& laptop : laptops) {
        if (total_capital >= laptop.price && laptops_bought < N) {
            total_capital -= laptop.price;
            total_capital += laptop.gain;
            laptops_bought++;
        }
    }

    return total_capital;
}

int main() {
    int N, C;
    cout << "Enter the maximum number of laptops (N): ";
    cin >> N;
    cout << "Enter the initial capital (C): ";
    cin >> C;

    vector<int> gains;
    vector<int> prices;

    int numberOfLaptops;
    cout << "Enter the number of available laptops: ";
    cin >> numberOfLaptops;

    cout << "Enter the gains for each laptop: ";
    for (int i = 0; i < numberOfLaptops; ++i) {
        int gain;
        cin >> gain;
        gains.push_back(gain);
    }

    cout << "Enter the prices for each laptop: ";
    for (int i = 0; i < numberOfLaptops; ++i) {
        int price;
        cin >> price;
        prices.push_back(price);
    }

    int result = maximize_capital(N, C, gains, prices);
    cout << "Capital at the end of the summer: " << result << endl;

    return 0;
}

