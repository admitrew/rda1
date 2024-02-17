#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

/**
 * @brief Функция, складывающая два числа-вектора
 * 
 * @param vec1 Первое число-вектор
 * @param vec2 Второе число-вектор
 * @param sz Размер большего массива
 * 
 * @return Возвращает вектор-сумму
*/
std::vector <int> vecsum(std::vector <int> vec1, std::vector <int> vec2, int sz){
    std::vector <int> resultvector; // число-вектор с результатом
    resultvector.push_back(0);
    resultvector[0]=(vec1[0]+vec2[0])%10;
    int md=(vec1[0]+vec2[0])/10; // переменная остатка
    for (int i=1; md>0 || i<sz; ++i){
        vec1.push_back(0);
        vec2.push_back(0);
        resultvector.push_back(0);

        resultvector[i]=(vec1[i]+vec2[i]+md)%10;    
        md=(vec1[i]+vec2[i]+md)/10;
    }
    return resultvector;
}

/**
 * @brief Функция для вывода чисел-векторов на экран
 * 
 * @param vec Принимает на вход число-вектор, подлежащее выводу на экран
 * @param sz Принимает размер числа-вектора
 * 
 * @return Выводит в терминал число-вектор
*/
void print(std::vector <int> vec, int sz){
    for (int i=sz-1; i>=0; --i){
        std::cout << vec[i];
    } std::cout << '\n';
}

int main() {
    setlocale(LC_ALL, "russian");
    int x,y; // две степени из исходных данных
    std::cin >> x >> y;
    std::vector <int> vec1={2}, vec2={2};
    for (int i=0; i<x-1; ++i){
        vec1 = vecsum(vec1, vec1, vec1.size());
    }
    for (int i=0; i<y-1; ++i){
        vec2 = vecsum(vec2, vec2, vec2.size());
    }
    std::vector <int> vecanswer = vecsum(vec1, vec2, std::max(vec1.size(),vec2.size()));
    print(vecanswer, (int)vecanswer.size());
    return 0;
}