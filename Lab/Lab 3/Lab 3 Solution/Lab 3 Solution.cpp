#include <iostream>


// Vector Class Implementation:

class Vector {
private:
    int* array;
    int capacity;
    int current_size;

public:
    // Constructor
    Vector(int initial_capacity = 10) {
        capacity = initial_capacity;
        array = new int[capacity];
        current_size = 0;
    }

    // Destructor
    ~Vector() {
        delete[] array;
    }

    // Add an element to the end of the vector
    void push_back(int element) {
        if (current_size == capacity) {
            // Increase capacity by doubling it
            capacity *= 2;
            int* new_array = new int[capacity];
            for (int i = 0; i < current_size; ++i) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
        }
        array[current_size++] = element;
    }

    // Remove the last element from the vector
    void pop_back() {
        if (current_size > 0) {
            --current_size;
        }
    }

    // Insert an element at a specific position
    void insert(int position, int element) {
        if (position >= 0 && position <= current_size) {
            if (current_size == capacity) {
                capacity *= 2;
                int* new_array = new int[capacity];
                for (int i = 0; i < position; ++i) {
                    new_array[i] = array[i];
                }
                new_array[position] = element;
                for (int i = position; i < current_size; ++i) {
                    new_array[i + 1] = array[i];
                }
                delete[] array;
                array = new_array;
                ++current_size;
            }
            else {
                for (int i = current_size; i > position; --i) {
                    array[i] = array[i - 1];
                }
                array[position] = element;
                ++current_size;
            }
        }
    }

    // Erase an element at a specific position
    void erase(int position) {
        if (position >= 0 && position < current_size) {
            for (int i = position; i < current_size - 1; ++i) {
                array[i] = array[i + 1];
            }
            --current_size;
        }
    }

    // Get the element at a specific index
    int& operator[](int index) {
        return array[index];
    }

    // Get the current size of the vector
    int size() {
        return current_size;
    }
};


// Template Class Implementation:
/*
template<typename T>
class Vector {
private:
    T* array;
    size_t capacity;
    size_t currentSize;

public:
    // Constructor
    Vector() : capacity(10), currentSize(0) {
        array = new T[capacity];
    }

    // Destructor
    ~Vector() {
        delete[] array;
    }

    // Add an element to the end of the vector
    void push_back(const T& element) {
        if (currentSize == capacity) {
            // If the array is full, double its capacity
            capacity *= 2;
            T* newArray = new T[capacity];
            for (size_t i = 0; i < currentSize; ++i) {
                newArray[i] = array[i];
            }
            delete[] array;
            array = newArray;
        }
        // warning to not write elements past the end of the array. https://stackoverflow.com/questions/58563272/how-to-solve-c6386-warning
        array[currentSize++] = element;
    }

    // Remove the last element from the vector
    void pop_back() {
        if (currentSize > 0) {
            --currentSize;
        }
    }

    // Insert an element at a specific position
    void insert(size_t index, const T& element) {
        if (index >= 0 && index <= currentSize) {
            if (currentSize == capacity) {
                capacity *= 2;
                // insert new value
                T* newArray = new T[capacity];
                for (size_t i = 0; i < index; ++i) {
                    newArray[i] = array[i];
                }
                // copy elements after the insertion point
                newArray[index] = element;
                for (size_t i = index; i < currentSize; ++i) {
                    // warning details in above comment.
                    newArray[i + 1] = array[i];
                }
                // DELETE
                delete[] array;
                array = newArray;
            }
            else {
                // shift elements to make room for the new one
                for (size_t i = currentSize; i > index; --i) {
                    array[i] = array[i - 1];
                }
                // insert the new one
                array[index] = element;
            }
            ++currentSize;
        }
    }

    // Erase an element at a specific position
    void erase(size_t index) {
        if (index >= 0 && index < currentSize) {
            for (size_t i = index; i < currentSize - 1; ++i) {
                array[i] = array[i + 1];
            }
            --currentSize;
        }
    }

    // Get the element at a specific index
    T& operator[](size_t index) {
        if (index >= 0 && index < currentSize) {
            return array[index];
        }
        throw std::out_of_range("Index out of range");
    }

    // Get the current size of the vector
    size_t size() const {
        return currentSize;
    }
};
*/

int main() {
    Vector vec;
    //Vector<int> vec; un-comment this to test Template case.

    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    std::cout << "Size of vector: " << vec.size() << std::endl;

    std::cout << "Vector elements: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec.pop_back();
    vec.insert(1, 4);

    std::cout << "Size of vector after pop_back and insert: " << vec.size() << std::endl;

    std::cout << "Vector elements after pop_back and insert: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    vec.erase(0);

    std::cout << "Size of vector after erase: " << vec.size() << std::endl;

    std::cout << "Vector elements after erase: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
