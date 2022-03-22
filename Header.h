#pragma once
#ifndef _HEADER
#define _HEADER
#include <iostream>
#include <vector>
using namespace std;

struct regRow {
    int id;
    int barcode;
    int quantity;
    double price;
    double discount;
    double total;
};

//общие функции для статик динамик
void printTable(regRow* arr,int n);
void printTableID(regRow* arr, int n);
regRow fillRow(regRow row);

//статик
void addRow(regRow* arr, int& n);
void insert(regRow* arr, int& n);
void deleteID(regRow* arr, int& n);

//функции динамик
void addRowD(regRow* &arr,int &n);
void insertD(regRow* &arr, int& n);
void deleteIDD(regRow* &arr, int& n);


//функции вектор
int printTableV(vector<regRow>& arr, int n);
void printTableIDV(vector<regRow> &arr, int n);
void addRowV(vector<regRow> &arr, int &n);
void insertV(vector<regRow> &arr, int &n);
void deleteIDV(vector<regRow> &arr, int &n);

#endif // !_HEADER
