#include <iostream>
#include <algorithm>

std::string convertatsia(int p, int n) { // обращаемся к параметрам по значению
	std::string s = "0123456789abcdef", ans;
	for (int i = 0; n > 0; ++i) { // перевод в p-ичную систему счисления
		int x = n % p;
		ans += s[x];
		n /= p;
	} 
    std::reverse(ans.begin(), ans.end());
	return ans;
}
int main() {
	setlocale(LC_ALL, "russian");
	std::cout << "Введите основание системы p (2<=p<=16): ";
	int p; std::cin >> p;
	std::cout << "Введите число в 10-ичной системе счисления: ";
	int n; std::cin >> n;
	std::cout << n << '(' << 10 << ')' << " = "; // вывод числа
	for (auto& i : convertatsia(p, n)) std::cout << i; // вводим в параметры основание системы и 10-ичное число
	std::cout << '(' << p << ')' << '\n';
}
