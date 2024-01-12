#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <limits>

using namespace std;

int main() {
    int M;
    int N;

    std::cout << "Homework 2. Option 6" << std::endl;

    std::cout << "enter N" << std::endl;
    std::cin >> N;
    while (std::cin.fail() || N < 1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "N must be integer and > 0!" << std::endl;
        std::cin >> N;
    }

    std::cout << "enter M" << std::endl;
    std::cin >> M;
    while (std::cin.fail() || M < 1) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "M must be integer and > 0!" << std::endl;
        std::cin >> M;
    }

    std::cout << "fill matrix..." << std::endl;
    char** matrix = new char* [M];
    char a;
    for (int i = 0; i < M; i++) {
        matrix[i] = new char[N];
        for (int j = 0; j < N; j++) {
            std::cin >> a;
            matrix[i][j] = a;
        }
    } //fill matrix
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }// print matrix

    int result = 0;
    bool mass[256] = { false };

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (!mass[(int) matrix[i][j]]) { 
                result++;
                mass[(int) matrix[i][j]] = true; 
            }
        }
    }

    std::cout << "result = " << result << std::endl;

    for (int i = 0; i < N; i++) {
        delete[M](matrix[i]);
    }
    delete[N](matrix);
    matrix = NULL;
    return 0;
}