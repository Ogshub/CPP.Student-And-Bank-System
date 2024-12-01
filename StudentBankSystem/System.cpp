#include <iostream>
#include <string>

void MenuDisplay() {
    std::cout << "---------------------------\n";
    std::cout << "\t   Menu\n";
    std::cout << "Choose from the following options:\n";
    std::cout << "1) Student Grade Calculator.\n";
    std::cout << "2) Bank System.\n";
    std::cout << "3) Exit.\n";
}

// Bank System
class Bank {
    std::string m_name{};
    int m_accNum{};
    double m_bal{};

public:
    Bank(const std::string& name, int accNum, double bal)
        : m_name{ name }, m_accNum{ accNum }, m_bal{ bal } {}

    void deposit() {
        double dep{};
        do {
            std::cout << "\nEnter money to deposit: ";
            std::cin >> dep;
            if (dep < 1) {
                std::cout << "Enter a valid amount to deposit.\n";
            }
        } while (dep < 1);
        m_bal += dep;
        std::cout << "\nMoney deposited: " << dep;
        std::cout << "\nBalance: " << m_bal << "\n";
    }

    void withdraw() {
        double wit{};
        while (true) {
            std::cout << "\nEnter money to withdraw (or enter -1 to cancel): ";
            std::cin >> wit;

            if (wit == -1) {
                std::cout << "Withdrawal canceled. Returning to menu.\n";
                break;
            }

            if (wit < 1) {
                std::cout << "Invalid amount! You cannot withdraw less than 1.\n";
            }
            else if (wit > m_bal) {
                std::cout << "Insufficient funds! Your balance is " << m_bal << ".\n";
            }
            else {
                m_bal -= wit;
                std::cout << "Money withdrawn: " << wit << "\n";
                break;
            }
        }
    }


    void print() const {
        std::cout << "\nName: " << m_name;
        std::cout << "\nAccount Number: " << m_accNum;
        std::cout << "\nBalance: " << m_bal << "\n";
    }
};

Bank getBankDetails() {
    std::string name{};
    int accnum{};
    double bal{};

    std::cout << "Enter your name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    do {
        std::cout << "Enter your Account Number: ";
        std::cin >> accnum;
        if (accnum < 1) {
            std::cout << "Enter a valid account number.\n";
        }
    } while (accnum < 1);

    return { name, accnum, bal };
}

// Student Grade Calculator
enum class GradeType { O, A, B, C, D, F };

class Student {
    std::string m_name{};
    int m_roll{};
    double m_marks{};

public:
    Student(const std::string& name, int roll, double marks)
        : m_name{ name }, m_roll{ roll }, m_marks{ marks } {}

    GradeType gradeCal() const {
        if (m_marks < 36) return GradeType::F;
        if (m_marks < 50) return GradeType::D;
        if (m_marks < 60) return GradeType::C;
        if (m_marks < 70) return GradeType::B;
        if (m_marks < 85) return GradeType::A;
        return GradeType::O;
    }

    std::string enumToString(GradeType grade) const {
        switch (grade) {
        case GradeType::O: return "O";
        case GradeType::A: return "A";
        case GradeType::B: return "B";
        case GradeType::C: return "C";
        case GradeType::D: return "D";
        case GradeType::F: return "F";
        }
        return "Invalid Grade";
    }

    void print() const {
        std::cout << "\nName: " << m_name;
        std::cout << "\nRoll Number: " << m_roll;
        std::cout << "\nMarks: " << m_marks;
        std::cout << "\nGrade: " << enumToString(gradeCal())<<"\n";
    }
};

Student getInput() {
    std::string name{};
    int roll{};
    double marks{};

    std::cout << "Enter your name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    do {
        std::cout << "Enter your roll number: ";
        std::cin >> roll;
        if (roll < 1) {
            std::cout << "Enter a valid roll number.\n";
        }
    } while (roll < 1);

    do {
        std::cout << "Enter your marks: ";
        std::cin >> marks;
        if (marks < 0 || marks > 100) {
            std::cout << "Enter valid marks (0-100).\n";
        }
    } while (marks < 0 || marks > 100);

    return { name, roll, marks };
}

void choiceOption() {
    int choice{};
    do {
        MenuDisplay();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            Student s = getInput();
            s.print();
            break;
        }
        case 2: {
            Bank b = getBankDetails();
            b.print();
            char option;
            do {
                std::cout << "\nDo you want to deposit (D), withdraw (W), or exit (X)? ";
                std::cin >> option;
                if (option == 'D' || option == 'd') b.deposit();
                else if (option == 'W' || option == 'w') b.withdraw();
            } while (option != 'X' && option != 'x');
            break;
        }
        case 3: {
            char confirm{};
            std::cout << "Are you sure you want to exit? (Y/N): ";
            std::cin >> confirm;
            if (confirm == 'Y' || confirm == 'y') {
                std::cout << "Exiting program. Goodbye!\n";
                return;
            }
            break;
        }
        default:
            std::cout << "Invalid choice! Please select again.\n";
        }
    } while (true); 
}

int main() {
    choiceOption();
    return 0;
}