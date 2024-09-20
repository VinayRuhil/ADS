#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;


template<typename T>
class SkipListNode {
public:
    T value;
    SkipListNode** forward; 

    SkipListNode(T val, int level) : value(val) {
        forward = new SkipListNode*[level + 1];
        for (int i = 0; i <= level; ++i) {
            forward[i] = 0;
        }
    }

    ~SkipListNode() {
        delete[] forward;
    }
};


template<typename T>
class SkipList {
public:
    SkipList(int maxLevel, float p);
    ~SkipList();

    void insert(const T& value);
    bool search(const T& value) const;
    void remove(const T& value);
    void display() const;

private:
    int randomLevel() const;
    void printLevel(int level) const;

    const int maxLevel;
    const float probability;
    SkipListNode<T>* header;
    int currentLevel;
};


template<typename T>
SkipList<T>::SkipList(int maxLvl, float p) : maxLevel(maxLvl), probability(p), currentLevel(0) {
    header = new SkipListNode<T>(T(), maxLevel);
}


template<typename T>
SkipList<T>::~SkipList() {
    SkipListNode<T>* node = header;
    while (node != 0) {
        SkipListNode<T>* next = node->forward[0];
        delete node;
        node = next;
    }
}


template<typename T>
int SkipList<T>::randomLevel() const {
    int level = 0;
    while (static_cast<float>(rand()) / RAND_MAX < probability && level < maxLevel) {
        ++level;
    }
    return level;
}

template<typename T>
void SkipList<T>::insert(const T& value) {
    SkipListNode<T>* update[maxLevel + 1];
    SkipListNode<T>* x = header;

    for (int i = currentLevel; i >= 0; --i) {
        while (x->forward[i] != 0 && x->forward[i]->value < value) {
            x = x->forward[i];
        }
        update[i] = x;
    }

    x = x->forward[0];

    if (x == 0 || x->value != value) {
        int lvl = randomLevel();
        if (lvl > currentLevel) {
            for (int i = currentLevel + 1; i <= lvl; ++i) {
                update[i] = header;
            }
            currentLevel = lvl;
        }

        x = new SkipListNode<T>(value, lvl);
        for (int i = 0; i <= lvl; ++i) {
            x->forward[i] = update[i]->forward[i];
            update[i]->forward[i] = x;
        }
    }
}


template<typename T>
bool SkipList<T>::search(const T& value) const {
    SkipListNode<T>* x = header;
    for (int i = currentLevel; i >= 0; --i) {
        while (x->forward[i] != 0 && x->forward[i]->value < value) {
            x = x->forward[i];
        }
    }
    x = x->forward[0];
    return x != 0 && x->value == value;
}


template<typename T>
void SkipList<T>::remove(const T& value) {
    SkipListNode<T>* update[maxLevel + 1];
    SkipListNode<T>* x = header;

    for (int i = currentLevel; i >= 0; --i) {
        while (x->forward[i] != 0 && x->forward[i]->value < value) {
            x = x->forward[i];
        }
        update[i] = x;
    }

    x = x->forward[0];

    if (x != 0 && x->value == value) {
        for (int i = 0; i <= currentLevel; ++i) {
            if (update[i]->forward[i] != x) break;
            update[i]->forward[i] = x->forward[i];
        }

        delete x;

        while (currentLevel > 0 && header->forward[currentLevel] == 0) {
            --currentLevel;
        }
    }
}


template<typename T>
void SkipList<T>::display() const {
    for (int i = currentLevel; i >= 0; --i) {
        printLevel(i);
        cout << endl;
    }
}

template<typename T>
void SkipList<T>::printLevel(int level) const {
    SkipListNode<T>* x = header->forward[level];
    cout << "Level " << level << ": ";
    while (x != 0) {
        cout << x->value << " ";
        x = x->forward[level];
    }
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int maxLevel, choice;
    float probability;
    
    cout << "Enter the maximum level for the skip list: ";
    cin >> maxLevel;
    cout << "Enter the probability for the level: ";
    cin >> probability;

    SkipList<int> list(maxLevel, probability);

    while (true) {
        cout << "\nChoose an operation: " << endl;
        cout << "1. Insert element" << endl;
        cout << "2. Search for element" << endl;
        cout << "3. Remove element" << endl;
        cout << "4. Display skip list" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            {
                int element;
                cout << "Enter the element to insert: ";
                cin >> element;
                list.insert(element);
                break;
            }

        case 2:
            {
                int element;
                cout << "Enter the element to search for: ";
                cin >> element;
                if (list.search(element)) {
                    cout << "Element found." << endl;
                } else {
                    cout << "Element not found." << endl;
                }
                break;
            }

        case 3:
            {
                int element;
                cout << "Enter the element to remove: ";
                cin >> element;
                list.remove(element);
                cout << "Element removed." << endl;
                break;
            }

        case 4:
            list.display();
            break;

        case 5:
            cout << "Exiting!" << endl;
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}

