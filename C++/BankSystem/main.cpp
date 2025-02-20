#include <iostream>
#include <string>
#include <vector>
#include <ctime>

using namespace std;

// 交易记录类
class Transaction {
private:
    string type;  // 交易类型
    double amount;  // 交易金额
    time_t timestamp;  // 交易时间
    
public:
    Transaction(string t, double a) : type(t), amount(a) {
        timestamp = time(0);
    }
    
    void print() const {
        cout << type << ": " << amount << " at " << ctime(&timestamp);
    }
};

// 银行账户类
class BankAccount {
private:
    string owner;  // 账户持有人
    double balance;  // 账户余额
    vector<Transaction> transactions;  // 交易记录
    
public:
    BankAccount(string name) : owner(name), balance(0) {}
    
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "存款金额必须大于0" << endl;
            return;
        }
        balance += amount;
        transactions.push_back(Transaction("存款", amount));
        cout << "存款成功！当前余额：" << balance << endl;
    }
    
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "取款金额必须大于0" << endl;
            return;
        }
        if (amount > balance) {
            cout << "余额不足！" << endl;
            return;
        }
        balance -= amount;
        transactions.push_back(Transaction("取款", amount));
        cout << "取款成功！当前余额：" << balance << endl;
    }
    
    void showBalance() const {
        cout << owner << "的账户余额：" << balance << endl;
    }
    
    void showTransactions() const {
        cout << owner << "的交易记录：" << endl;
        for (const Transaction& t : transactions) {
            t.print();
        }
    }
};

// 用户界面
void showMenu() {
    cout << "1. 存款" << endl;
    cout << "2. 取款" << endl;
    cout << "3. 查看余额" << endl;
    cout << "4. 查看交易记录" << endl;
    cout << "5. 退出" << endl;
    cout << "请选择操作：";
}

int main() {
    string name;
    cout << "请输入您的姓名：";
    cin >> name;
    
    BankAccount account(name);
    int choice;
    double amount;
    
    while (true) {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "请输入存款金额：";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "请输入取款金额：";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                account.showBalance();
                break;
            case 4:
                account.showTransactions();
                break;
            case 5:
                cout << "感谢使用银行系统，再见！" << endl;
                return 0;
            default:
                cout << "无效选择，请重试" << endl;
        }
    }
    
    return 0;
}