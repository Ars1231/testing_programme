#include <iostream>
#include <string>
using namespace std;

// Класс узла списка
class test_list {
public:
    string data;        // Данные узла
    test_list* next;        // Указатель на следующий узел

    // Конструктор
    test_list(const string& data) : data(data), next(nullptr) {}
};

// Класс связного списка
class LinkedList {
private:
    test_list* head;        // Указатель на голову списка

public:
    // Конструктор
    LinkedList() : head(nullptr) {}

    // Деструктор для освобождения памяти
    ~LinkedList() {
        while (head != nullptr) {
            test_list* temp = head; // Временный указатель
            head = head->next;  // Перемещение указателя на следующий узел
            delete temp;        // Освобождение памяти
        }
    }

    // Метод добавления элемента в конец списка
    void append(const string& data) {
        test_list* newNode = new test_list(data); // Новый узел
        if (head == nullptr) {
            head = newNode;      // Если список пуст, новый узел становится головой
            return;
        }
        test_list* last = head; // Перемещение к последнему узлу
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode; // Присоединение нового узла в конец
    }

    // Метод для вывода содержимого списка
    void printList() const {
        test_list* current = head; // Начало с головы списка
        while (current != nullptr) {
            cout << current->data << " "; // Печать данных узла
            current = current->next;       // Переход к следующему узлу
        }
        cout << endl;
    }

    // Метод сортировки списка
    void sort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }
        bool swapped;
        do {
            swapped = false;
            test_list* current = head; // Начало с головы списка
            while (current->next != nullptr) {

                if (current->data > current->next->data) { // Сравнение текущего узла с следующим
                    swap(current->data, current->next->data);  // Обмен значениями
                    swapped = true;
                }
                current = current->next; // Переход к следующему узлу
            }
        } while (swapped);
    }
};

int main() {
    LinkedList linkedList; // Создаем связанный список
    while (true) {
        string data;
        cout << "Введите элемент списка или exit для завершения ввода: ";
        getline(cin, data);
        if (data == "exit") {
            break;
        }
        linkedList.append(data); // Добавить элемент в список
    }

    cout << "Список до сортировки:" << endl;
    linkedList.printList(); // Вывод несортированного список
    linkedList.sort(); // Сортировка список
    cout << "Список после сортировки:" << endl;
    linkedList.printList(); // Вывод отсортированного список
    return 0;
}
