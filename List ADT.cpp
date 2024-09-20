#include <iostream>
#include <list>
#include <stdexcept>

using namespace std;

class ListADT {
private:
    list<int> L; 

public:
    
    ListADT() {}

  
    ListADT(int n) {
        L = list<int>(n, 0);
    }

   
    int size() {
        return L.size();
    }

    bool empty() {
        return L.empty();
    }


    int& front() {
        if (L.empty()) {
            throw out_of_range("List is empty.");
        }
        return L.front();
    }

    int& back() {
        if (L.empty()) {
            throw out_of_range("List is empty.");
        }
        return L.back();
    }

    
    void pushFront(int e) {
        L.push_front(e);
    }

   
    void pushBack(int e) {
        L.push_back(e);
    }

    void popFront() {
        if (L.empty()) {
            throw out_of_range("List is empty.");
        }
        L.pop_front();
    }

  
    void popBack() {
        if (L.empty()) {
            throw out_of_range("List is empty.");
        }
        L.pop_back();
    }


    void display() {
        if (L.empty()) {
            cout << "List is empty." << endl;
        } else {
            for (list<int>::iterator it = L.begin(); it != L.end(); ++it) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    ListADT myList;
    int choice, element;

    while (true) {
        cout << "\nChoose an operation: " << endl;
        cout << "1. Create list with n elements" << endl;
        cout << "2. Check if list is empty" << endl;
        cout << "3. Get size of the list" << endl;
        cout << "4. Display front element" << endl;
        cout << "5. Display back element" << endl;
        cout << "6. Insert element at front" << endl;
        cout << "7. Insert element at back" << endl;
        cout << "8. Remove front element" << endl;
        cout << "9. Remove back element" << endl;
        cout << "10. Display list" << endl;
        cout << "11. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int n;
            cout << "Enter number of elements for the list: ";
            cin >> n;
            myList = ListADT(n);
            break;

        case 2:
            if (myList.empty()) {
                cout << "List is empty." << endl;
            } else {
                cout << "List is not empty." << endl;
            }
            break;

        case 3:
            cout << "Size of the list: " << myList.size() << endl;
            break;

        case 4:
            try {
                cout << "Front element: " << myList.front() << endl;
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 5:
            try {
                cout << "Back element: " << myList.back() << endl;
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 6:
            cout << "Enter element to insert at front: ";
            cin >> element;
            myList.pushFront(element);
            break;

        case 7:
            cout << "Enter element to insert at back: ";
            cin >> element;
            myList.pushBack(element);
            break;

        case 8:
            try {
                myList.popFront();
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 9:
            try {
                myList.popBack();
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 10:
            myList.display();
            break;

        case 11:
            cout << "Exiting!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

