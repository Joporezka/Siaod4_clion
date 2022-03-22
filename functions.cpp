#include "Header.h"
#include <iostream>
#include <vector>
using namespace std;
const int N = 100;


void printTable(regRow* arr, int n) {
    cout << "ID | Barcode | Quantity | Price | Discount | Total\n";
    for (auto i = 0; i < n; i++) {
        cout << arr[i].id << " " << arr[i].barcode << " " << arr[i].quantity << " " << arr[i].price << " " << arr[i].discount << " " << arr[i].total << endl;
    }
}

void printTableID(regRow* arr, int n) {
    cout << "Введите ID кассы для вывода: \n";
    int id;
    cin >> id;

    cout << "ID | Barcode | Quantity | Price | Discount | Total\n";
    for (auto i = 0; i < n; i++) {
        if(arr[i].id = id)
            cout << arr[i].id << " " << arr[i].barcode << " " << arr[i].quantity << " " << arr[i].price << " " << arr[i].discount << " " << arr[i].total << endl;
    }
}


regRow fillRow(regRow row) {
    cout << "Введите id кассы, код товара, количество, цену и скидку" << endl;
    cin >> row.id;
    cin >> row.barcode;
    cin >> row.quantity;
    cin >> row.price;
    cin >> row.discount;
    row.total = row.price * row.quantity * (1 - (row.discount / 100));
    return row;
}

//==================================STATIC=======================================

void addRow(regRow* arr, int& n) {
    n++;
    if (n == N) {
        return;
    }
    arr[n-1] = fillRow(arr[n-1]);
}

void insert(regRow* arr, int& n) {
    int id;
    cout << "Введите ID кассы для вставки: \n";
    cin >> id;
    regRow temp{};
    temp = fillRow(temp);

    for (auto i = 0; i < n; i++) {
        if (arr[i].id == id) {
            n++;
            for (auto j = i; j < n; j++) {
                swap(arr[j], temp);
            }
            return;
        }
    }
}

void deleteID(regRow* arr, int& n) {
    cout<<"Введите ID кассы для удаления: \n";
    int id;
    cin >> id;
    for (auto i = 0; i < n; i++) {
        if (arr[i].id == id) {
            n--;
            for (int j = i; j < n + 1; j++) {
                swap(arr[j], arr[j + 1]);
            }
            i--;
        }
    }
}

//==================================DYNAMIC=======================================

void addRowD(regRow* &arr,int &n) {
    n++;
    regRow* arr1 = new regRow[n];
    for (auto i = 0; i < n-1; i++) {
        arr1[i] = arr[i];
    }
    arr1[n-1] = fillRow(arr1[n-1]);
    arr = arr1;
}
void insertD(regRow* &arr, int& n) {
    int id;
    cout << "Введите ID кассы для вставки: \n";
    cin >> id;
    regRow temp{};
    temp = fillRow(temp);
    n++;
    regRow* arr1 = new regRow[n];
    arr1[n - 1] = {};

    for (auto i = 0; i < n-1; i++) {
        arr1[i] = arr[i];
    }

    for (auto i = 0; i < n; i++) {
        if (arr1[i].id == id) {
            for (auto j = i; j < n; j++)
                swap(temp, arr1[j]);
            break;
        }
    }
    arr = arr1;
}

void deleteIDD(regRow* &arr, int& n) {
    cout << "Введите ID кассы для удаления: \n";
    int id;
    cin >> id;
    for (auto i = 0; i < n; i++) {
        if (arr[i].id == id) {
            n--;
            for (auto j = i; j < n; j++) {
                swap(arr[j], arr[j + 1]);
            }
            i--;
        }
    }
    regRow* arr1 = new regRow[n];
    for (auto i = 0; i < n; i++) {
        arr1[i] = arr[i];
    }
    arr = arr1;
}

//==================================VECTOR=======================================


int printTableV(vector<regRow> &arr, int n) {
    cout << "ID | Barcode | Quantity | Price | Discount | Total\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].id << " " << arr[i].barcode << " " << arr[i].quantity << " " << arr[i].price << " " << arr[i].discount << " " << arr[i].total << endl;
    }
    return 0;
}

void printTableIDV(vector<regRow> &arr, int n) {
    cout << "Введите ID кассы для вывода: \n";
    int id;
    cin >> id;

    cout << "ID | Barcode | Quantity | Price | Discount | Total\n";
    for (int i = 0; i < n; i++) {
        if (arr[i].id == id)
            cout << arr[i].id << " " << arr[i].barcode << " " << arr[i].quantity << " " << arr[i].price << " " << arr[i].discount << " " << arr[i].total << endl;
    }
}

void addRowV(vector<regRow> &arr, int &n) {
    n++;
    regRow temp{};
    arr.push_back(fillRow(temp));
}

void insertV(vector<regRow> &arr, int &n) {
    int id;
    cout << "Введите ID кассы для вставки: \n";
    cin >> id;
    regRow temp{};
    for (int i = 0; i < n; i++) {
        if (arr[i].id == id) {
            n++;
            arr.insert(arr.begin() + i, fillRow(temp));
            return;
        }
    }
}

void deleteIDV(vector<regRow> &arr, int &n) {
    int id;
    cout << "Введите ID кассы для удаления: \n";
    cin >> id;
    regRow temp{};
    for (int i = 0; i < n; i++) {
        if (arr[i].id == id) {
            n--;
            arr.erase(arr.begin() + i);
            i--;
        }
    }
}