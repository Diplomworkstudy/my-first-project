#include <iostream>
#include <string>
using namespace std;
struct Stud {
    string fio;
    string group;
    double sredniyBal;
    Stud* next;
};
int main() {
    int n;
    cout << "How many students? : ";
    cin >> n;
    cin.ignore();
    Stud* head = NULL;
    Stud* tail = NULL;
    for (int i = 0; i < n; i++) {
        string fio, group;
        double bal;
        cout << "\nFIO: ";
        getline(cin, fio);
        cout << "Group: ";
        getline(cin, group);
        cout << "Sredniy bal: ";
        cin >> bal;
        cin.ignore();
        Stud* newNode = new Stud;
        newNode->fio = fio;
        newNode->group = group;
        newNode->sredniyBal = bal;
        newNode->next = NULL;
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    for (Stud* i = head; i != NULL; i = i->next) {
        for (Stud* j = i->next; j != NULL; j = j->next) {
            if (i->sredniyBal > j->sredniyBal) {
                swap(i->fio, j->fio);
                swap(i->group, j->group);
                swap(i->sredniyBal, j->sredniyBal);
            }
        }
    }
    Stud* temp = head;
    int idx = 1;
    while (temp != NULL) {
        cout << "Student " << idx++ << ":\n";
        cout << "FIO: " << temp->fio << "\n";
        cout << "Group: " << temp->group << "\n";
        cout << "Sredniy bal: " << temp->sredniyBal << "\n\n";
        temp = temp->next;
    }
    while (head != NULL) {
        Stud* t = head;
        head = head->next;
        delete t;
    }
}

