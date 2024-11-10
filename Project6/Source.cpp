#include <iostream>  
#include <string>  
using namespace std;
class Bankomat {
private:
    int id;                 // ����������������� ����� ���������  
    int currentAmount;      // ������� ����� ����� � ���������  
    const int minWithdraw;  // ����������� ����� ��� ������  
    const int maxWithdraw;  // ������������ ����� ��� ������  

public:
   
    Bankomat(int id, int minWithdraw, int maxWithdraw)
        : id(id), currentAmount(0), minWithdraw(minWithdraw), maxWithdraw(maxWithdraw) {}

   
    void initialize(int initialAmount) {
        currentAmount = initialAmount;
    }

    // ����� ��� �������� ����� � ��������  
    void loadCash(int amount) {
        if (amount > 0) {
            currentAmount += amount;
            cout << "���������: " << amount << " �������.\n";
        }
        else {
            cout << "������: ����� ��� �������� ������ ���� �������������.\n";
        }
    }

    // ����� ������ ������������ ����� �����  
    bool withdraw(int amount) {
       
        if (amount < minWithdraw || amount > maxWithdraw) {
            cout << "������: ����� ������ ���� ����� " << minWithdraw << " � " << maxWithdraw << ".\n";
            return false; 
        }

        if (amount > currentAmount) {
            cout << "������: ������������ ������� � ���������.\n";
            return false; 
        }

        currentAmount -= amount; // ��������� ������� �����  
        cout << "�����: " << amount << " �������.\n";
        return true; // �����  
    }

    // ����� ��� �������������� ��������� � ������  
    string toString() const {
        return "�������� ID: " + to_string(id) + "\n" +
            "������� �����: " + to_string(currentAmount) + " �������\n" +
            "����������� ����� ��� ������: " + to_string(minWithdraw) + " �������\n" +
            "������������ ����� ��� ������: " + to_string(maxWithdraw) + " ������� \n";
    }
};

int main() {
    Bankomat atm(1, 100, 1000); // ������� �������� � ID 1 � �������� �� ������  
    atm.initialize(5000);       // �������������� �������� � ��������� ������  
    cout << atm.toString(); // ������� ������� ��������� ���������  

    atm.loadCash(1000);         // ��������� �������������� ������  
    cout << atm.toString(); // ��������� ��������� ����� ��������  

    atm.withdraw(200);          // �������� ����� 200  
    cout << atm.toString(); // ��������� ��������� ����� ������  

    atm.withdraw(1500);         // �������� ����� 1500 (���� ������)  
    atm.withdraw(3000);         // �������� ����� 3000 (������������ �������)  

    return 0;
}