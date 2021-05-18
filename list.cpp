#include <iostream>
using namespace std;


struct ListPair {
    int num;
    ListPair *tail;
};

struct List{
    ListPair *head;
};

List newList() {
    List nList;
    nList.head = nullptr;
    return nList;
}

List newList(List const &lst) {
    List nList;
    ListPair *nPointer = new ListPair;
    ListPair *oldPoint = lst.head;
    nList.head = nPointer;
    while((*oldPoint).tail != nullptr){
        (*nPointer).num = (*oldPoint).num; //переносим значения из старого списка в новый
        (*nPointer).tail = new ListPair; //добавляем ссылку на следующий
        nPointer = (*nPointer).tail;
        oldPoint = (*oldPoint).tail;
    }
}

List push_list(List &lst, int num) {
    ListPair *add = new ListPair; //создаем новый элемент списка
    (*add).num = num; //добавляем в него значение
    (*add).tail = lst.head; //указатель на следующий элемент - это указатель на первый элемент изначального списка
    lst.head = add; //указатель на начальный элемент - указатель на новый элемент
    return lst; //возвращаем обновленный список
}

int pop_list(List &lst) {
    int result = (*lst.head).num; //
    lst.head = (*lst.head).tail; //
    return result;
}

int peak_list(List const &lst) {
    return (*lst.head).num;
}

void delete_list(List &lst){
    ListPair *point = lst.head;
    ListPair *buf;
    while (point != nullptr){
        buf = point; //запоминаем старый указатель
        point = (*point).tail; //переходим к следующему указателю
        delete buf; //удаляем старый
    }
    point = nullptr;
}

bool is_empty(List const &lst) {
    if (lst.head == nullptr) return true;
    else return false;
}

List reverse_list(List &lst) {
    ListPair *point = lst.head;
    ListPair *next, *last;
    last = nullptr;
    while(point != nullptr){
        next = (*point).tail;
        (*point).tail = last;
        last = point;
        point = next;
    }
    lst.head = last;
    return lst;
}

void printer(List &lst){ //функция необходимая для проверки
    if(lst.head != nullptr){
        ListPair *a = lst.head;
        while(a != nullptr){
            cout << (*a).num;
            a = (*a).tail;
        }
    }
    else cout << "Empty" << "\n";
}

int main() {
    List a = newList();
    int i = 0;
    while (i < 10){
        push_list(a, i);
        i++;
    }
    printer(a);
    cout << "\n" << pop_list(a) << "\n";
    printer(a);
    cout << "\n";
    List b = reverse_list(a);
    printer(b);
    delete_list(b);
    delete_list(a);
}
