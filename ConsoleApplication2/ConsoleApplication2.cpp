#include <iostream>
using namespace std;

//Объявить и заполнить двумерный динамический массив случайными числами от 1 до 70. Показать его на экран. Для заполнения и показа на экран написать отдельные функции. 
//(подсказка: функции должны принимать три параметра – указатель на динамический массив, количество строк, количество столбцов). Количество строк и столбцов выбирает пользователь. 
//Написать функцию, которая вычисляет сумму элементов, расположенных на побочной диагонали матрицы.

void Numbers(int** A, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % (70 - 1) + 1 ;
        }
    }
}

void Print(int** A, int M, int N) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << A[i][j] << ' ';
        }
        std::cout << "\n";
    }
}

int SecondaryDiagonalSum(int** A, int M, int N) {
    int sum = 0;
    for (int i = 0, j = N - 1; i < M && j >= 0; ++i) {
        sum += A[i][j--];
    }
    return sum;
}

void test1() {
    int M;
    int N;
    std::cin >> M ;
    std::cin >> N;

    int** A;
    A = new int* [M];
    for (int i = 0; i < M; i++) {
        A[i] = new int[N];
    }
    Numbers(A, M, N);
    Print(A, M, N);
    std::cout << SecondaryDiagonalSum(A, M, N) << std::endl;
    for (int i = 0; i < M; i++) {
        delete[] A[i];
    }
    delete[] A;
}

//С клавиатуры подается на вход размер целочисленного динамического массива. Объявите динамический массив. Заполните его с клавиатуры. 
//Найдите непрерывный подмассив, длиной k, который имеет максимальное среднее значение, и верните это значение. Будет принят любой ответ с ошибкой вычисления менее 10-5.

void FillMatrix(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
}

void PrintMatrix(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

double MaxSubarrayAvg(int* arr, int n, int k) {
   
    int currsum = 0;
    int maxsum = 0;
    for (int i = 0; i < k; ++i) {
        currsum += arr[i];
    }
    maxsum = currsum;
    for (int i = 0, j = k; j < n; ++i, ++j) {
        currsum = currsum - arr[i] + arr[j];
        if (currsum > maxsum) {
            maxsum = currsum;
        }
    }
    return (double)maxsum / k;
}

int test2() {
    int n, k;
    std::cout << "Введите размер массива: " << std::endl;
    std::cin >> n;
    int* arr = new int[n];
    std::cout << "Введите " << n << "значений массива:" << std::endl;
    FillMatrix(arr, n);
    PrintMatrix(arr, n);
    std::cout << "Введите размер подмассива: " << std::endl;
    std::cin >> k;
    std::cout << "Максимальный средний подмассив: " << MaxSubarrayAvg(arr, n, k) << std::endl;

    return 0;
}



int main()
{
    std::cout << "Task 3:" << std::endl;
    test1();

    std::cout << "Task 4:" << std::endl;
    test2();
}