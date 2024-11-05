#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Рекурсивна функція для підрахунку кількості пар сусідніх символів "aa", "bb" або "cc"
int Count(char* str) {
    if (strlen(str) < 2)
        return 0;

    if ((str[0] == 'a' && str[1] == 'a') ||
        (str[0] == 'b' && str[1] == 'b') ||
        (str[0] == 'c' && str[1] == 'c')) {
        return 1 + Count(str + 2);
    }
    else {
        return Count(str + 1);
    }
}

// Рекурсивна функція для заміни кожної пари сусідніх символів "aa", "bb" або "cc" на "***"
void Change(char* str, char* result) {
    if (strlen(str) < 2) {
        strcat(result, str);  // Додаємо залишок рядка до результату
        return;
    }

    if ((str[0] == 'a' && str[1] == 'a') ||
        (str[0] == 'b' && str[1] == 'b') ||
        (str[0] == 'c' && str[1] == 'c')) {
        strcat(result, "***");  // Додаємо "***" до результату
        Change(str + 2, result);  // Пропускаємо пару
    }
    else {
        size_t len = strlen(result);
        result[len] = str[0];      // Додаємо поточний символ до результату
        result[len + 1] = '\0';    // Завершуємо рядок
        Change(str + 1, result);   // Переходимо до наступного символу
    }
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Виведення кількості пар
    cout << "String contained " << Count(str) << " groups of 'aa', 'bb' or 'cc'" << endl;

    // Заміна пар
    char result[151] = "";  // Виділяємо достатній обсяг пам'яті для результату
    Change(str, result);
   
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << result << endl;

    return 0;
}

