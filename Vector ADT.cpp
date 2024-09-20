#include <iostream>
#include <vector>
#include <stdexcept> 

using namespace std;

class VectorADT {
private:
    vector<int> V; 

public:
    
    VectorADT() {}

   
    VectorADT(int n) {        V.resize(n);
    }

  
    int size() {
        return V.size();
    }


    bool empty() {
        return V.empty();
    }

    void resize(int n) {
        V.resize(n);
    }

    void reserve(int n) {
        V.reserve(n);
    }

    int& front() {
        if (V.empty()) {
            throw out_of_range("Vector is empty");
        }
        return V.front();
    }

    int& back() {
        if (V.empty()) {
            throw out_of_range("Vector is empty");
        }
        return V.back();
    }


    void pushBack(int e) {
        V.push_back(e);
    }


    void popBack() {
        if (V.empty()) {
            throw out_of_range("Vector is empty");
        }
        V.pop_back();
    }


    int at(int i) {
        if (i < 0 || i >= V.size()) {
            throw out_of_range("Index out of range");
        }
        return V[i];
    }

    void set(int i, int e) {
        if (i < 0 || i >= V.size()) {
            throw out_of_range("Index out of range");
        }
        V[i] = e;
    }

    void insert(int i, int e) {
        if (i < 0 || i > V.size()) {
            throw out_of_range("Index out of range");
        }
        V.insert(V.begin() + i, e);
    }


    void erase(int i) {
        if (i < 0 || i >= V.size()) {
            throw out_of_range("Index out of range");
        }
        V.erase(V.begin() + i);
    }


    void display() {
        if (V.empty()) {
            cout << "Vector is empty." << endl;
        } else {
            for (size_t i = 0; i < V.size(); ++i) {
                cout << V[i] << " "; 
            }
            cout << endl;
        }
    }
};

int main() {
    VectorADT vec;
    int choice, index, element, n;

    while (true) {
        cout << "\nChoose an operation: " << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Access element" << endl;
        cout << "3. Set element" << endl;
        cout << "4. Erase element" << endl;
        cout << "5. Display vector" << endl;
        cout << "6. Get size of the vector" << endl;
        cout << "7. Check if vector is empty" << endl;
        cout << "8. Resize the vector" << endl;
        cout << "9. Reserve storage for vector" << endl;
        cout << "10. Get front element" << endl;
        cout << "11. Get back element" << endl;
        cout << "12. Push element to back" << endl;
        cout << "13. Pop element from back" << endl;
        cout << "14. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the index where you want to insert: ";
            cin >> index;
            cout << "Enter the element to insert: ";
            cin >> element;
            try {
                vec.insert(index, element);
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 2:
            cout << "Enter the index to access: ";
            cin >> index;
            try {
                cout << "Element at index " << index << ": " << vec.at(index) << endl;
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 3:
            cout << "Enter the index to set: ";
            cin >> index;
            cout << "Enter the new element: ";
            cin >> element;
            try {
                vec.set(index, element);
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 4:
            cout << "Enter the index to erase: ";
            cin >> index;
            try {
                vec.erase(index);
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 5:
            vec.display();
            break;

        case 6:
            cout << "Size of the vector: " << vec.size() << endl;
            break;

        case 7:
            if (vec.empty()) {
                cout << "Vector is empty." << endl;
            } else {
                cout << "Vector is not empty." << endl;
            }
            break;

        case 8:
            cout << "Enter new size for the vector: ";
            cin >> n;
            vec.resize(n);
            break;

        case 9:
            cout << "Enter the number of elements to reserve space for: ";
            cin >> n;
            vec.reserve(n);
            break;

        case 10:
            try {
                cout << "Front element: " << vec.front() << endl;
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 11:
            try {
                cout << "Back element: " << vec.back() << endl;
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 12:
            cout << "Enter the element to push at the back: ";
            cin >> element;
            vec.pushBack(element);
            break;

        case 13:
            try {
                vec.popBack();
            } catch (out_of_range& e) {
                cout << e.what() << endl;
            }
            break;

        case 14:
            cout << "Exiting!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

