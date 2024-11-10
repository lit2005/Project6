#include <iostream>  
#include <string>  
using namespace std;
class Bankomat {
private:
    int id;                 // Идентификационный номер банкомата  
    int currentAmount;      // Текущая сумма денег в банкомате  
    const int minWithdraw;  // Минимальная сумма для снятия  
    const int maxWithdraw;  // Максимальная сумма для снятия  

public:
   
    Bankomat(int id, int minWithdraw, int maxWithdraw)
        : id(id), currentAmount(0), minWithdraw(minWithdraw), maxWithdraw(maxWithdraw) {}

   
    void initialize(int initialAmount) {
        currentAmount = initialAmount;
    }

    // Метод для загрузки купюр в банкомат  
    void loadCash(int amount) {
        if (amount > 0) {
            currentAmount += amount;
            cout << "Загружено: " << amount << " гривень.\n";
        }
        else {
            cout << "Ошибка: Сумма для загрузки должна быть положительной.\n";
        }
    }

    // Метод снятия определенной суммы денег  
    bool withdraw(int amount) {
       
        if (amount < minWithdraw || amount > maxWithdraw) {
            cout << "Ошибка: Сумма должна быть между " << minWithdraw << " и " << maxWithdraw << ".\n";
            return false; 
        }

        if (amount > currentAmount) {
            cout << "Ошибка: Недостаточно средств в банкомате.\n";
            return false; 
        }

        currentAmount -= amount; // Уменьшаем текущую сумму  
        cout << "Снято: " << amount << " гривень.\n";
        return true; // Успех  
    }

    // Метод для преобразования состояния в строку  
    string toString() const {
        return "Банкомат ID: " + to_string(id) + "\n" +
            "Текущая сумма: " + to_string(currentAmount) + " гривень\n" +
            "Минимальная сумма для снятия: " + to_string(minWithdraw) + " гривень\n" +
            "Максимальная сумма для снятия: " + to_string(maxWithdraw) + " гривень \n";
    }
};

int main() {
    Bankomat atm(1, 100, 1000); // Создаем банкомат с ID 1 и лимитами на снятие  
    atm.initialize(5000);       // Инициализируем банкомат с начальной суммой  
    cout << atm.toString(); // Выводим текущее состояние банкомата  

    atm.loadCash(1000);         // Загружаем дополнительные купюры  
    cout << atm.toString(); // Проверяем состояние после загрузки  

    atm.withdraw(200);          // Пытаемся снять 200  
    cout << atm.toString(); // Проверяем состояние после снятия  

    atm.withdraw(1500);         // Пытаемся снять 1500 (выше лимита)  
    atm.withdraw(3000);         // Пытаемся снять 3000 (недостаточно средств)  

    return 0;
}