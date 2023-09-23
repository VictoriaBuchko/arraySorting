//Дан массив случайных чисел в диапазоне от –20 до +20.
//Необходимо найти позиции крайних отрицательных
//элементов(самого левого отрицательного элемента
//и самого правого отрицательного элемента) и отсортировать элементы, находящиеся между ними.

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void minMax(const int arr[], int size, int& leftI, int& rightI) {//функция для нахождения границ 
    leftI = 0;
    rightI = 0;

    for (int i = 0; i < size; i++)
        if (arr[i] < 0)
        {
            rightI = i;
        }
    for (int i = size - 1; i >= 0; i--)
        if (arr[i] < 0) {
            leftI = i;
        }
}


void selectionSort(int arr[], int leftI, int rightI) {//функция сортировки выбором 
    int x;

    for (int i = leftI; i < rightI; i++) {

        int minI = i;
        x = arr[minI];

        for (int j = i + 1; j <= rightI; j++) {

            if (arr[j] < x) {

                minI = j;
                x = arr[minI];
            }
        }
        if (minI != i) {

            arr[minI] = arr[i];
            arr[i] = x;
        }
    }
}

int main() {
    srand(time(nullptr));

    const int SIZE = 20;
    int arr[SIZE];
    int leftI, rightI;

    for (int i = 0; i < SIZE; i++) {//инициализация масива
        arr[i] = rand() % 41 - 20;
    }

    for (int i = 0; i < SIZE; i++) {//вывод начального самива на экран
        cout << arr[i] << "\t";
    }
    cout << endl;

    minMax(arr, SIZE, leftI, rightI);//вызов функции сортировки для поиска границ

    selectionSort(arr, leftI + 1, rightI - 1);//вызов функции сортировки 

    for (int i = 0; i < SIZE; i++) {//вывод конечного масива на экран
        cout << arr[i] << "\t";
    }


    return 0;
}

/* Task 2--------------------------------------------------------------------------------------------------------------------
2) Дан массив из 20 целых чисел со значениями от 1 до 20.
Необходимо:

■ написать функцию, разбрасывающую элементы массива произвольным образом;

■ создать случайное число из того же диапазона и найти
позицию этого случайного числа в массиве;

■ отсортировать элементы массива, находящиеся слева от найденной позиции, по убыванию, а элементы
массива, находящиеся справа от найденной позиции, по возрастанию.*/

//РАСКОММЕНТИРУЙТЕ КОД!

/*
 
 
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void mixing(int arr[], int SIZE) {//1 задание 

    for (int i = 0; i < SIZE; i++) {
        int k = rand() % SIZE;
        int t = arr[i];
        arr[i] = arr[k];
        arr[k] = t;
    }
}

int randomNumber(int arr[], int SIZE) {// 2задание в этом задании я нахожу позицию (индекс) числа в масиве 
// если я не правильно поняла смысл слова позиция и это номер в последовательности, то в 125 строчке нужно прибавить 1 к i ( i + 1)

    int random_num = rand() % 20 + 1;
    cout << "Random number: " << random_num << endl;

    int numberI = -1;

    cout << "Index number " << random_num << " : ";
    for (int i = 0; i < SIZE; i++) {

        if (arr[i] == random_num) {

            numberI = i;
            cout << i << " ";
        }
    }

    return numberI;
}


void sorting(int arr[], int SIZE, int numberI) {//задание 
    int i, j;

    for (i = 1; i < numberI - 1; i++) {

        int x = arr[i];

        for (j = i - 1; j >= 0 && arr[j] < x; j--) {

            arr[j + 1] = arr[j];
        }
        arr[j + 1] = x;
    }


    for (i = numberI + 1; i < SIZE; i++) {

        int x = arr[i];

        for (j = i - 1; j >= numberI && arr[j] > x; j--) {

            arr[j + 1] = arr[j];
        }
        arr[j + 1] = x;
    }
}



int main() {
    srand(time(nullptr));

    const int SIZE = 20;
    int arr[SIZE];

    for (int i = 0; i < SIZE; i++) {// инициализация масива 
       
        arr[i] = i + 1;
    }

    for (int i = 0; i < SIZE; i++) {//вывод начального масива на экран 
        
        cout << arr[i] << "\t";
    }
    cout << endl;

    mixing(arr, SIZE);//1 задание( функция для розбрасывания чисел в масиве)


    for (int i = 0; i < SIZE; i++) {//вывод масива с разбросаными числами 
        cout << arr[i] << "\t";
    }
    cout << "\n\n";


    int numberI = randomNumber(arr, SIZE);//2 задание

    cout << "\n\n";

    sorting(arr, SIZE, numberI);//3 задание 


    for (int i = 0; i < SIZE; i++) {//вывод масива с отсортироваными частями
        cout << arr[i] << "\t";
    }

    return 0;
}
*/


