#include <iostream>
#include <Windows.h>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    double interestRate;

public:
    void deposit();
    void withdraw();
    void getBalance();
    void getInterestRate();
    void setInterestRate();
    void getAccountNumber();

    BankAccount(int accountNumber, double balance, double interestRate) {
        this->accountNumber = accountNumber;
        this->balance = 0;
        this->interestRate = 0;
    }

    friend bool transfer(BankAccount& from, BankAccount& to, double amount);
};

    void BankAccount::deposit() {
        cout << "Введите номер счета: ";
        cin >> this->accountNumber;
        cout << "Внесите деньги: ";
        cin >> this->balance;
        cout << "Счет открыт!" << endl << endl;
    }

    void BankAccount::withdraw() {
        long long int a;

        do {
            cout << "Введите сумму, которую желаете снять ";
            cin >> a;
            if (a > this->balance) cout << "Недостаточно средств. Введите 0 для возврата на начальный экран. " << endl;
        } while (a > this->balance);
        this->balance -= a;
        cout << "Деньги успешно сняты" << endl;
    }

    void BankAccount::getBalance() {
        cout << endl << "Состояние счета: " << endl;
        cout << "Номер счета: " << this->accountNumber << endl;
        cout << "Колличество средств на счете: " << this->balance << endl;
    }
    void BankAccount::getInterestRate() {
        double monthlyInterestRate = 1.0 / 12;
        cout << "Ваша процентная ставка пока что ноль. Введите по какой ставке хотите положить деньги. " << endl;
        cin >> this->interestRate;
        double interestEarned = this->balance * this->interestRate * monthlyInterestRate;
        cout << "Теперь вы будете получать в год: " << interestEarned << endl;

    }
    void BankAccount::setInterestRate() {
        double a = 1.0 / 12;
        int b = 5;
        this->interestRate = this->balance * b * a;
        cout << "Ваша процентная ставка обновлена до 5-ти и теперь вы будете получать: " << this->interestRate << endl;
    }
    void BankAccount::getAccountNumber() {
        cout << "Ваш номер банковского счета: " << this->accountNumber << endl;
    }

    bool transfer(BankAccount& from, BankAccount& to, double amount)
    {
        if (from.balance >= amount) {
            from.balance -= amount;
            to.balance += amount;
            cout << "Перевод выполнен." << endl;
            return true;
        }
        else {
            std::cerr << "Некорректная сумма для перевода или недостаточно средств на счете." << std::endl;
            return false;
        }
    }

    int main() {
        SetConsoleCP(1251);
        setlocale(LC_ALL, "Russian");

        BankAccount account(0, 0.0, 0); // Инициализация счета с номером 0, начальным балансом 0.0 и процентной ставкой 0

        int choice;
        do {
            cout << "1. Внести средства на счет" << endl;
            cout << "2. Снять средства со счета" << endl;
            cout << "3. Узнать текущий баланс" << endl;
            cout << "4. Получить сумму процентов" << endl;
            cout << "5. Обновить процентную ставку" << endl;
            cout << "6. Узнать номер банковского счёта" << endl;
            cout << "7. Выйти из программы" << endl;
            cout << "Выберите операцию: ";
            cin >> choice;

            switch (choice) {
            case 1:
                account.deposit();
                break;
            case 2:
                account.withdraw();
                break;
            case 3:
                account.getBalance();
                break;
            case 4:
                account.getInterestRate();
                break;
            case 5:
                account.setInterestRate();
                break;
            case 6:
                account.getAccountNumber();
                break;
            case 7:
                cout << "Выход из программы..." << endl;
                break;
            default:
                cout << "Некорректный выбор. Выберите номер, который присутствует в списке." << endl;
            }
        } while (choice != 7);

        return 0;
    }