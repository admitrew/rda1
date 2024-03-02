    #include <iostream>
    #include <cmath>
    #include <vector>
    #include <string>
    #include <algorithm>

    /**
     * @brief Функция, проверяющая строку s на акронимичность к тексту text 
     * 
     * @param s Входная строка 
     * @param text Вектор со словами
     * @param sz Размер вектора
     * 
     * @return Возвращает результат проверки
    */
    bool acronym(std::string s, std::vector <std::string> text, int sz){
        for (int i=0; i<sz; ++i){
            if (s[i]!=text[i][0]){
                return false;
            }
        }
        return true;
    }

    /** 
     * @brief Функция, возвращающая минимальное необходимое количество действий, чтобы s1 и s2 стали анаграммами по отношению друг к другу
     *  
     * @param s1 Первая строка
     * @param s2 Вторая строка
     *  
     * @return Возвращает минимальное необходимое количество операций
    */  
    int anagram(std::string s1, std::string s2){
        int cnts1[26]={0};
        int cnts2[26]={0};
        for (int i=0; i<(int)s1.size(); ++i){
            cnts1[s1[i]-'a']++;
        }
        for (int i=0; i<(int)s2.size(); ++i){
            cnts2[s2[i]-'a']++;
        }
        int ans=0;
        for (int i=0; i<(int)s1.size(); ++i){
            ans+=abs(cnts1[i]-cnts2[i]);
        }
        return ans;
    }

    /** 
     * @brief Функция, возвращающая максимальный счёт vecint среди множества слов vecstr, сформированных из вектора vecchar
     *  
     * @param vecstr Вектор строк, определяющий множество строк
     * @param vecchar Вектор символов, определяющий множество символов
     * @param vecint Вектор подсчёта с целочисленными значениями, определяющий счёт за каждый символ в слове
     * 
     * @return Возвращает максимальный счёт среди множества слов
    */  
    int counting(std::vector <std::string> vecstr, std::vector <char> vecchar, std::vector <int> vecint){
        int cntchar[26]={0};
        int maxans=0;
        for (int i=0; i<(int)vecchar.size(); ++i){
            cntchar[vecchar[i]-'a']++;
        }
        for (size_t i=0; i<vecstr.size(); ++i){
            bool fl=true;
            std::string word = vecstr[i];
            int cntstr[26]={0};
            for (int j=0; j<(int)word.size(); ++j){
                cntstr[word[j]-'a']++;
            }
            
            for (int k=0; k<26; ++k){
                if (cntchar[k]<cntstr[k]){
                    fl=false;
                    break;
                }
            }

            if (!fl){
                continue;
            }

            int ans=0;
            for (int j=0; j<(int)word.size(); ++j){
                ans+=vecint[word[j]-'a'];
            }

            if (maxans<ans) maxans=ans;
        }
        return maxans;
    }

    int main() {
        setlocale(LC_ALL, "russian");
        std::string s="csrd";
        std::vector <std::string> vec={"computer", "science", "robotics", "memory"};
        std::cout << "Результат функции acronym: " << acronym(s, vec, (int)vec.size()) << '\n';

        std::string s1="knowledge";
        std::string s2="experience";
        std::cout << "Результат функции anagram: " << anagram(s1, s2) << '\n';

        std::vector <std::string> vstr = {"apple", "lenovo", "samsung", "acer"}; 
        std::vector <char> vchr = {'a', 'p', 'l', 'e', 'n', 'o', 'v', 'o', 'c', 'r', 'r', 'r'};
        std::vector <int> vint;
        for (int i=0; i<26; ++i){
            vint.push_back(i+1);
        }
        std::cout << "Результат функции counting: " << counting(vstr, vchr, vint) << '\n';
        return 0;
    }