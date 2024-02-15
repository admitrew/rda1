#include <iostream>
#include <algorithm>

/**
 *  @brief Функция, конвертирующая 10-ичное число в число с base-ичной СС
 * 
 * 	@param base Система счисления, в которую нужно преобразовать число
 *  @param number Исходное десятичное число, которое нужно преобразовать
 *  
 *  @return Функция возвращает строку, в которой с помощью цифр и латинских букв записано преобразованное число в base-ичной СС
 **/
std::string convertatsia(int base, int number) { // обращаемся к параметрам по значению
	std::string str = "0123456789abcdef", answer;
	for (int i = 0; number > 0; ++i) { // перевод в base-ичную систему счисления
		int x = number % base;
		answer += str[x];
		number /= base;
	} 
    std::reverse(answer.begin(), answer.end());
	return answer;
}

/**
 * @brief Подпрограмма для конвертации чисел из 10-ичной СС в base-ичную СС
 **/
void num_convert() {
	setlocale(LC_ALL, "russian");
	std::cout << "Введите основание системы base (2<=base<=16): ";
	int base; std::cin >> base;
	std::cout << "Введите число в 10-ичной системе счисления: ";
	int number; std::cin >> number;
	std::cout << number << '(' << 10 << ')' << " = "; // вывод числа
	for (auto& i : convertatsia(base, number)) std::cout << i; // вводим в параметры основание системы и 10-ичное число
	std::cout << '(' << base << ')' << '\n';
}

/**
 * @brief Функция, выполняющая инвертацию бита в числе
 * 
 * @param number Число, подлежащее изменению
 * @param bit Номер бита, подлежащего инвертации
 * 
 * @return Функция не возвращает значение (тип void), но изменяет number напрямую через ссылку
**/
void function(int& number, int bit) { // передаём number по ссылке
	int mask = (1 << bit);
	number = (number ^ mask);
}
/**
 * @brief Подпрограмма, инвертирующая бит под номером bit в числе number
*/
void bit_invert() {
	setlocale(LC_ALL, "russian");
	int number, bit;
	std::cout << "Введите число number и номер бита bit: ";
	std::cin >> number >> bit;
	function(number, bit);
	std::cout << "dec  oct  hex\n";
	std::cout << number << std::oct << ' ' << number << std::hex << ' ' << number << std::dec << '\n';
}

/**
 * @brief Функция пузырьковой сортировки по убыванию на массиве arr
 * 
 * @param arr Указатель на массив
 * @param arrsize Размер массива arr
 * 
 * @return Функция не возвращает ничего (тип void), но изменяет сам массив arr через указатель
*/
void BubbleSort(int* arr, int arrsize) { // обращаемся к массиву с помощью указателя на него
	for (int i = 0; i < arrsize - 1; i++) { // сортировка пузырьком по убыванию
		for (int j = 0; j < arrsize - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
			}
		}
	}
}

/**
 * @brief Подпрограмма, реализующая пузырьковую сортировку по убыванию на случайном массиве размера number
*/
void arr_sorting() {
	setlocale(LC_ALL, "russian");
	int number;
	std::cout << "Введите размер массива: ";
	std::cin >> number;
	int* arr = new int[number];
	int ans = 0;
	for (int i = 0; i < number; i++) {
		arr[i] = rand() % 20;
	}
	std::cout << "Неотсортированный массив: ";
	for (int i = 0; i < number; ++i) std::cout << arr[i] << ' ';
	BubbleSort(arr, number); // вводим в параметры массив и его размер
	std::cout << '\n' << "Отсортированный массив: ";
	for (int i = 0; i < number; ++i) std::cout << arr[i] << ' ';
	delete[] arr;
}

/**
 * @brief Главная функция программы, с которой мы вызываем остальные подпрограммы
*/
int main(){
	num_convert();
	bit_invert();
	arr_sorting();
	return 0;
}