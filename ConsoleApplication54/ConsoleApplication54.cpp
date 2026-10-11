#include <iostream>
using namespace std;

int main() {
    double a, b, x;

    cout << "Введіть першу межу: ";
    cin >> a;

    cout << "Введіть другу межу: ";
    cin >> b;

    if (a > b) {
        double t = a;
        a = b;
        b = t;
    }

    do {
        cout << "Введіть число від " << a << " до " << b << ": ";
        cin >> x;
    } while (x < a || x > b);

    cout << "Число прийнято: " << x << endl;

    return 0;
}

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string names[4] = { "Ялинкова кулька", "Гірлянда", "Ялинка", "Мішура" };
    double prices[4] = { 25, 150, 800, 40 };
    int stock[4] = { 100, 30, 10, 80 };
    double revenue = 0;
    char nextClient = 'y';

    while (nextClient == 'y' || nextClient == 'Y') {
        double total = 0;
        int choice, quantity;

        cout << "\n=== НОВОРІЧНИЙ МАГАЗИН ===\n";

        while (true) {
            cout << "\nТовари:\n";

            for (int i = 0; i < 4; i++) {
                cout << i + 1 << ". " << names[i]
                    << " - " << prices[i] << " грн"
                    << " (залишок: " << stock[i] << ")\n";
            }

            cout << "0. Завершити покупку\n";
            cout << "Ваш вибір: ";

            if (!(cin >> choice)) {
                cout << "Помилка введення!\n";
                return 0;
            }

            if (choice == 0)
                break;

            if (choice < 1 || choice > 4) {
                cout << "Такого товару немає!\n";
                continue;
            }

            int index = choice - 1;

            cout << "Введіть кількість: ";

            if (!(cin >> quantity)) {
                cout << "Помилка введення!\n";
                return 0;
            }

            if (quantity <= 0) {
                cout << "Кількість повинна бути додатною!\n";
                continue;
            }

            if (quantity > stock[index]) {
                cout << "Недостатньо товару на складі!\n";
                continue;
            }

            stock[index] -= quantity;
            total += prices[index] * quantity;

            cout << "Товар додано до покупки!\n";
        }

        double discount = 0;

        if (total >= 2000)
            discount = 10;
        else if (total >= 1000)
            discount = 5;

        double discountAmount = total * discount / 100;
        double payment = total - discountAmount;

        cout << fixed << setprecision(2);
        cout << "\nСума покупки: " << total << " грн\n";
        cout << "Знижка: " << discount << "%\n";
        cout << "До сплати: " << payment << " грн\n";

        revenue += payment;

        cout << "\nОбслугувати наступного клієнта? (y/n): ";
        cin >> nextClient;
    }

    cout << "\nЗагальна виручка магазину: "
        << fixed << setprecision(2) << revenue << " грн\n";

    return 0;
}


#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    int level, questions;

    cout << "Виберіть рівень складності:\n";
    cout << "1. Легкий\n";
    cout << "2. Середній\n";
    cout << "3. Складний\n";
    cout << "Ваш вибір: ";
    cin >> level;

    if (level == 1)
        questions = 5;
    else if (level == 2)
        questions = 10;
    else if (level == 3)
        questions = 15;
    else {
        cout << "Неправильний рівень!\n";
        return 0;
    }

    int correct = 0;

    for (int i = 1; i <= questions; i++) {
        int a, b, answer;

        if (level == 1) {
            a = rand() % 5 + 1;
            b = rand() % 5 + 1;
        }
        else if (level == 2) {
            a = rand() % 10 + 1;
            b = rand() % 10 + 1;
        }
        else {
            a = rand() % 20 + 1;
            b = rand() % 20 + 1;
        }

        cout << i << ". " << a << " * " << b << " = ";
        cin >> answer;

        if (answer == a * b) {
            cout << "Правильно!\n";
            correct++;
        }
        else {
            cout << "Неправильно! Відповідь: " << a * b << "\n";
        }
    }

    cout << "\nПравильних відповідей: "
        << correct << " з " << questions << endl;

    int grade = correct * 12 / questions;

    cout << "Оцінка: " << grade << " з 12\n";

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Введіть розмір ромба (непарне число): ";
    cin >> n;

    if (n < 1 || n % 2 == 0) {
        cout << "Введіть додатне непарне число!\n";
        return 0;
    }

    for (int i = 1; i <= n; i += 2) {
        for (int j = 0; j < (n - i) / 2; j++)
            cout << " ";

        for (int j = 0; j < i; j++)
            cout << "*";

        cout << endl;
    }

    for (int i = n - 2; i >= 1; i -= 2) {
        for (int j = 0; j < (n - i) / 2; j++)
            cout << " ";

        for (int j = 0; j < i; j++)
            cout << "*";

        cout << endl;
    }

    return 0;
}