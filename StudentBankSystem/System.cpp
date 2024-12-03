#include <iostream>
#include <string>

void menu();

class Bank {
    std::string m_name{};
    int m_accNum{};
    double m_balance{};

public:
    Bank(const std::string& name, int acc, double bal)
        : m_name{ name }, m_accNum{ acc }, m_balance{ bal } {
    }

    void deposit() {
        double money{};
        do {
            std::cout << "\nEnter money to deposit: ";
            std::cin >> money;
            std::cin.ignore();

            if (money < 1) {
                std::cout << "\nEnter money greater than zero (0) to deposit.";
            }
        } while (money < 1);

        m_balance += money;
        std::cout << "\nMoney deposited: " << money << "$\n";
    }

    void withdraw() {
        double money{};
        char input{};
        bool isWithdrawing{ true };

        do {
            std::cout << "\nEnter money to withdraw: ";
            std::cin >> money;

            if (money < 1 || money > m_balance) {
                std::cout << "\nInsufficient funds.";
                std::cout << "\nTry again (c or C to cancel transaction): ";
                std::cin >> input;

                if (input == 'c' || input == 'C') {
                    std::cout << "\nTransaction canceled.\n";
                    return;
                }
            }
            else {
                isWithdrawing = true;
            }
        } while (money < 1 || money > m_balance);

        if (isWithdrawing) {
            m_balance -= money;
            std::cout << "\nMoney withdrawn: " << money << "$\n";
        }
    }

    void print() {
        std::cout << "\n---------------";
        std::cout << "\nAccount Details:";
        std::cout << "\nYour Name       : " << m_name;
        std::cout << "\nAccount Number  : " << m_accNum;
        std::cout << "\nBalance         : " << m_balance << "$";
        std::cout << "\n---------------\n";
    }
};

Bank getBankDetails() {
    std::string name{};
    int acc{};
    double bal{};

    std::cout << "\nEnter your name: ";
    std::getline(std::cin, name);

    do {
        std::cout << "Enter account number: ";
        std::cin >> acc;
        std::cin.ignore();

        if (acc < 1) {
            std::cout << "\nEnter a valid account number.\n";
        }
    } while (acc < 1);

    std::cout << "Initial balance set to 0.\n";

    return { name, acc, bal };
}

void Bankmenu() {
    char input{};
    std::cout << "\nWelcome to the Bank!";
    Bank b{ getBankDetails() };

    do {
        std::cout << "\nChoose an option:";
        std::cout << "\n(d) Deposit";
        std::cout << "\n(w) Withdraw";
        std::cout << "\n(p) Print account details";
        std::cout << "\n(e) Exit";
        std::cout << "\nYour choice: ";
        std::cin >> input;

        switch (input) {
        case 'd': case 'D':
            b.deposit();
            break;

        case 'w': case 'W':
            b.withdraw();
            break;

        case 'p': case 'P':
            b.print();
            break;

        case 'e': case 'E':
            std::cout << "\nThank you for banking with us. Goodbye!\n";
            return;

        default:
            std::cout << "\nInvalid choice! Please try again.\n";
        }
    } while (true);
}

class Student {
    std::string m_name{};
    int m_rollNum{};
    int m_papers{};
    double m_marks{};
    double m_total{};
    double m_perc{};
public:

    enum GradeType {
        O, A, B, C, D, F,
    };

    GradeType getGrade() {
        if (m_perc < 36) {
            return GradeType::F;
        }
        else if (m_perc < 50) {
            return GradeType::D;
        }
        else if (m_perc < 60) {
            return GradeType::C;
        }
        else if (m_perc < 70) {
            return GradeType::B;
        }
        else if (m_perc < 85) {
            return GradeType::A;
        }
        else {
            return GradeType::O;
        }
    }

    std::string getGradeString(GradeType g) {
        switch (g) {
        case GradeType::O:
            return "O";
        case GradeType::A:
            return "A";
        case GradeType::B:
            return "B";
        case GradeType::C:
            return "C";
        case GradeType::D:
            return "D";
        case GradeType::F:
            return "F";
        default:
            return "Invalid Grade";
        }
    }

    Student(const std::string& name, int roll, int papers, double marks, double total, double perc)
        : m_name{ name }, m_rollNum{ roll }, m_papers{ papers }, m_marks{ marks }, m_total{ total }, m_perc{ perc } {

    }

    void print() {
        std::cout << "\n---------------";
        std::cout << "\nStudent Details:";
        std::cout << "\nYour Name       : " << m_name;
        std::cout << "\nRoll Number  : " << m_rollNum;
        std::cout << "\nMarks         : " << m_total;
        std::cout << "\nPercentage         : " << m_perc;
        std::cout << "\nGrade         : " << getGradeString(getGrade());
        std::cout << "\n---------------\n";
    }
};

Student getStudentDetails() {
    std::string name{};
    int roll{};
    int papers{};
    double marks{};
    double total{};
    double perc{};

    std::cout << "\nEnter your name: ";
    std::getline(std::cin, name);

    do {
        std::cout << "Enter Roll number: ";
        std::cin >> roll;
        std::cin.ignore();

        if (roll < 1) {
            std::cout << "\nEnter a valid Roll number.";
        }
    } while (roll < 1);

    do {
        std::cout << "Enter number of papers: ";
        std::cin >> papers;

        if (papers < 1) {
            std::cout << "\nEnter paper number more than One.\n";
        }
    } while (papers < 1);

    do {
        for (int i{ 1 }; i <= papers; i++) {
            std::cout << "Enter marks of paper " << i << " : ";
            std::cin >> marks;

            total += marks;


            if (marks < 1 || marks>100) {
                std::cout << "\nEnter Valid marks.\n";
            }
        }
    } while (marks < 1 || marks>100);

    perc = (total / papers);
    return { name, roll, papers ,marks,total,perc };
}

void Studentmenu() {
    char input{};
    std::cout << "\nWelcome to the Student Section!";
    Student s{ getStudentDetails() };

    do {
        std::cout << "\nChoose an option:";
        std::cout << "\n(p) Print Details..";
        std::cout << "\n(e) Exit";
        std::cout << "\nYour choice: ";
        std::cin >> input;

        switch (input) {
        case 'p': case 'P':
            s.print();
            break;

        case 'e': case 'E':
            std::cout << "\nThank you for Using Student Section. Goodbye!\n";
            return;

        default:
            std::cout << "\nInvalid choice! Please try again.\n";
        }
    } while (true);
}

void menu() {
    char input{};
    std::cout << "Welcome to Management System.\n";
    bool isRunning = true;

    while (isRunning) {
        std::cout << "\nChoose an option:";
        std::cout << "\n(b) Bank system.";
        std::cout << "\n(s) Student system.";
        std::cout << "\n(e) Exit";
        std::cout << "\nYour choice: ";
        std::cin >> input;
        std::cin.ignore();

        switch (input) {
        case 'b': case 'B':
            Bankmenu();
            break;

        case 's': case 'S':
            Studentmenu();
            break;

        case 'e': case 'E':
            std::cout << "\nThank you for using the Management System. Goodbye!\n";
            isRunning = false;
            break;

        default:
            std::cout << "\nInvalid choice! Please try again.\n";
        }
    }
}

int main() {
    menu();
    return 0;
}
