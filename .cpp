#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

using namespace std;
class Employee {
private:
    const int id; 
    string name;
    string position;
    double salary;

    static double budget; 
    static vector<Employee> employ; 

public:
    
    Employee(int id, const string& name, const string& position, double salary)
        : id(id), name(name), position(position), salary(salary) {
        if (budget >= salary * 12) {
            budget -= salary * 12; 
            employ.push_back(*this); 
        }
        else {
            throw runtime_error("Недостатньо бюджету для додавання працівника.");
        }
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    double getMonthlySalary() const { return salary; }

    void setName(const string& newName) { name = newName; }
    void setPosition(const string& newPosition) { position = newPosition; }
    void setMonthlySalary(double newSalary) {
        double salarydifference = (newSalary - salary) * 12;
        if (budget >= salarydifference) {
            budget -= salarydifference;
            salary = newSalary;
        }
        else {
            throw runtime_error("Недостатньо бюджету для зміни зарплати.");
        }
    }


    double getSalary() const {
        return salary * 12;
    }


    static void setBudget(double budget) {
        budget = budget;
    }

    static double getRemainingBudget() {
        return budget;
    }


    static double getTotalSalaries() {
        double total = 0.0;
        for (const auto& employee : employ) {
            total += employee.getSalary();
        }
        return total;
    }

    static void displayemployees() {
        cout << "Список працівників:\n";
        for (const auto& employee : employ) {
            cout << "ID: " << employee.getId()
                << ", Ім'я: " << employee.getName()
                << ", Посада: " << employee.getPosition()
                << ", Місячна зарплата: " << employee.getMonthlySalary() << "\n";
        }
    }
};
double Employee::budget = 200000.0;
vector<Employee> Employee::employ;

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    try {
        Employee::setBudget(100000.0);


        Employee e1(1, "Іван Іваненко", "PM", 3700.0);
        Employee e2(2, "Марія Петренко", "Розробник", 4000.0);

        Employee::displayemployees();


        std::cout << "Залишок бюджету: " << Employee::getRemainingBudget() << "\n";

        std::cout << "Загальні витрати на зарплати: " << Employee::getTotalSalaries() << "\n";


        e1.setMonthlySalary(3500.0);

        Employee::displayemployees();
       cout << "Залишок бюджету після зміни зарплати: " << Employee::getRemainingBudget() << "\n";
    }
    catch (const exception& ex) {
      cerr << "Помилка: " << ex.what() << "\n";
    }

    return 0;
}
