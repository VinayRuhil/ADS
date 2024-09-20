#include <iostream>

using namespace std;

template<typename Elem>
class DoublyLinkedList {
public:

    struct Node {
        Elem data;
        Node* prev;
        Node* next;
        Node(const Elem& e = Elem(), Node* p = 0, Node* n = 0)
            : data(e), prev(p), next(n) {}
    };

    class Iterator {
    public:
        Iterator(Node* p = 0) : node(p) {}

        Elem& operator*() const { return node->data; }
        Iterator& operator++() { node = node->next; return *this; }
        Iterator& operator--() { node = node->prev; return *this; }
        bool operator==(const Iterator& other) const { return node == other.node; }
        bool operator!=(const Iterator& other) const { return node != other.node; }

    private:
        Node* node;
        friend class DoublyLinkedList;
    };

    DoublyLinkedList() : n(0), header(new Node()), trailer(new Node()) {
        header->next = trailer;
        trailer->prev = header;
    }

    int size() const { return n; }
    bool empty() const { return n == 0; }
    Iterator begin() const { return Iterator(header->next); }
    Iterator end() const { return Iterator(trailer); }

    void insertFront(const Elem& e) { insert(begin(), e); }
    void insertBack(const Elem& e) { insert(end(), e); }
    void insert(const Iterator& p, const Elem& e) {
        Node* node = p.node;
        Node* newNode = new Node(e, node->prev, node);
        node->prev->next = newNode;
        node->prev = newNode;
        ++n;
    }

    void eraseFront() { erase(begin()); }
    void eraseBack() { erase(--end()); }
    void erase(const Iterator& p) {
        Node* node = p.node;
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
        --n;
    }

    ~DoublyLinkedList() {
        while (!empty()) {
            eraseFront();
        }
        delete header;
        delete trailer;
    }

private:
    int n;
    Node* header;
    Node* trailer; 
};

int main() {
    DoublyLinkedList<int> list;
    int choice, element;

    while (true) {
        cout << "\nChoose an operation: " << endl;
        cout << "1. Insert element at front" << endl;
        cout << "2. Insert element at back" << endl;
        cout << "3. Display list" << endl;
        cout << "4. Erase element from front" << endl;
        cout << "5. Erase element from back" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element to insert at the front: ";
            cin >> element;
            list.insertFront(element);
            break;

        case 2:
            cout << "Enter the element to insert at the back: ";
            cin >> element;
            list.insertBack(element);
            break;

        case 3:
            cout << "List elements: ";
            if (list.empty()) {
                cout << "List is empty." << endl;
            } else {
                for (DoublyLinkedList<int>::Iterator it = list.begin(); it != list.end(); ++it) {
                    cout << *it << " ";
                }
                cout << endl;
            }
            break;

        case 4:
            if (list.empty()) {
                cout << "List is empty. Cannot erase." << endl;
            } else {
                list.eraseFront();
                cout << "First element erased." << endl;
            }
            break;

        case 5:
            if (list.empty()) {
                cout << "List is empty. Cannot erase." << endl;
            } else {
                list.eraseBack();
                cout << "Last element erased." << endl;
            }
            break;

        case 6:
            cout << "Exiting!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

