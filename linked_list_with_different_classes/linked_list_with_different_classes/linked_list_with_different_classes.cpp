// linked_list_with_different_classes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

class Vect {
public:
    Vect() {}
    virtual ~Vect() {}
    virtual double getLenght() = 0;
    virtual string getType() = 0;
};

class Vect1d : public Vect {
public:
    Vect1d(double x_) {
        this->x = x_;
    }
    double getLenght() override {
        return fabs(x);
    }
    string getType() override {
        return "Vect1d";
    }
private:
    double x;
};

class Vect2d : public Vect {
public:
    Vect2d(double x_, double y_) {
        this->x = x_;
        this->y = y_;
    }
    double getLenght() override {
        return sqrt(x * x + y * y);
    }
    string getType() override {
        return "Vect2d";
    }
    void WTF_DEBUG() { cout << x << " " << y << "\n";}
private:
    double x;
    double y;
};

class linked_list {
public:
    linked_list() {
        size = 0;
        head = nullptr;
    }
    ~linked_list() { clear(); }
    void Add(Vect* ref) {
        if (head == nullptr)
        {
            head = new Node(ref);
            size++;
            return;
        }
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = new Node(ref);
        size++;
    }
    void getLengths() {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->ref->getLenght() << "\n";
            current = current->next;
        }
    }
    void getTypes() {
        Node* current = head;
        while (current != nullptr)
        {
            cout << current->ref->getType() << "\n";
            current = current->next;
        }
    }
    void pop_first() {
        Node* current = head;
        head = head->next;
        delete current;
        size--;
    }
    void clear() {
        while (size)
        {
            pop_first();
        }
    }
private:
    class Node {
    public:
        Node(Vect* ref, Node* next = nullptr) { this->ref = ref; this->next = next; }
        Vect* ref;
        Node* next;
    };
    int size;
    Node* head;
};


int main()
{
    Vect1d a1(1.0);
    Vect2d a2(3.0, 4.0);
    Vect1d a3(4.0);
    Vect2d a4(6.0, 5.0);
    Vect1d a5(2.0);
    Vect2d a6(1.0, 1.0);
    linked_list lst;
    lst.Add(&a1);
    lst.Add(&a2);
    lst.Add(&a3);
    lst.Add(&a4);
    lst.Add(&a5);
    lst.Add(&a6);
    lst.getLengths();
    lst.getTypes();
    lst.pop_first();
    lst.getLengths();
    lst.clear();
    lst.getLengths();
    //a2.WTF_DEBUG();
    //cout << endl << a2.getLenght();
    //getchar();
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
