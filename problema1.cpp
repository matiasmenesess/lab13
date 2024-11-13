
//Integrantes:
//1. Olivares Sarmiento, Javier Ignacio Leon
//2. Silva Reyes, Santiago Miguel
//3. Meneses Roncal, Matias Alonso

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct NodeDLL {
    T data;
    NodeDLL<T>* prev = nullptr;
    NodeDLL<T>* next = nullptr;
};

template<typename T>
class Double_Linked_List {
private:
    NodeDLL<T>* front = nullptr;
    NodeDLL<T>* rear = nullptr;
    int size = 0;

public:
    T front_() {
        return front->data;
    }

    T rear_() {
        return rear->data;
    }

    bool empty() {
        return front == nullptr;
    }

    void push_back(T value) {
        NodeDLL<T>* newNode = new NodeDLL<T>;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = rear;

        if (rear == nullptr) {
            front = newNode;
        } else {
            rear->next = newNode;
        }
        rear = newNode;
        size++;
    }

    void pop_front() {
        if (front == nullptr) {
            return;
        }
        NodeDLL<T>* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        } else {
            front->prev = nullptr;
        }
        delete temp;
        size--;
    }

    int getSize() const {
        return size;
    }
};

template<typename T>
class Queue {
    Double_Linked_List<T> queue_;
    int max_size;

public:
    Queue(int size) {
        max_size = size;
    }

    bool isempty() {
        return queue_.empty();
    }

    bool isfull() const {
        return queue_.getSize() == max_size;
    }

    T front() {
        return queue_.front_();
    }

    void enqueue(T val) {
        if (isfull()) {
            return;
        }
        queue_.push_back(val);
    }

    void dequeue() {
        if (isempty()) {
            return;
        }
        queue_.pop_front();
    }

    int getSize() const {
        return queue_.getSize();
    }
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        vector<pair<int, int>> ocho_direciones = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        Queue<pair<int, int>> q(n * n);
        q.enqueue({0, 0});

        vector<vector<bool>> visitado(n, vector<bool>(n, false));
        visitado[0][0] = true;

        int caminolength = 1;

        while (!q.isempty()) {
            int size = q.getSize();

            for (int i = 0; i < size; i++) {
                auto pos = q.front();
                q.dequeue();

                if (pos.first == n - 1 && pos.second == n - 1) {
                    return caminolength;
                }

                for (auto direccion: ocho_direciones) {
                    int x = pos.first + direccion.first;
                    int y = pos.second + direccion.second;
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0 && !visitado[x][y]) {
                        q.enqueue({x, y});
                        visitado[x][y] = true;
                    }
                }
            }

            caminolength++;
        }

        return -1;
    }
};
