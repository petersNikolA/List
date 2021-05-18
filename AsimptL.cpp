#include<iostream>
#include<chrono>
#include<fstream>
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
        (*nPointer).num = (*oldPoint).num;
        (*nPointer).tail = new ListPair;
        nPointer = (*nPointer).tail;
        oldPoint = (*oldPoint).tail;
    }
}

List push_list(List &lst, int num) {
    ListPair *add = new ListPair;
    (*add).num = num;
    (*add).tail = lst.head;
    lst.head = add;
    return lst;
}

int pop_list(List &lst) {
    int result = (*lst.head).num;
    lst.head = (*lst.head).tail;
    return result;
}

int peak_list(List const &lst) {
    return (*lst.head).num;
}

void delete_list(List &lst){
    ListPair *point = lst.head;
    ListPair *buf;
    while (point != nullptr){
        buf = point;
        point = (*point).tail;
        delete buf;
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

void printer(List &lst){
    if(lst.head != nullptr){
        ListPair *a = lst.head;
        while(a != nullptr){
            cout << (*a).num;
            a = (*a).tail;
        }
    }
    else cout << "Empty" << "\n";
}

double get_time() {
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now().time_since_epoch()).count();
}

int main(){
    ofstream file;
    file.open("list_push.csv");
    List a = newList();
    for (int j = 10000; j < 1010000; j += 10000){
        double start1 = get_time();
        for(int i = 0; i < j; i++){
            push_list(a, i);
        }
        double stop1 = get_time();
        double duration1 = stop1 - start1;
        file << j << ',' << duration1 << endl;
    }
    delete_list(a);

    file.open("list_pop.csv");
    List b = newList();
    for (int k = 10000; k < 1010000; k += 10000){
        for(int l = 0; l < k; l++){
            push_list(b, l);
        }
        double start2 = get_time();
        for(int l = 0; l < k; l++){
            int h = pop_list(b);
        }
        double stop2 = get_time();
        double duration2 = stop2 - start2;
        file << k << ',' << duration2 << endl;
    }
    delete_list(b);
    return 0;
}
