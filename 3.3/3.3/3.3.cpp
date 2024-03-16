//3.3.Очередь с помощью стека
//Реализовать очередь с помощью двух стеков.Использовать стек, реализованный с помощью динамического буфера.
//
//Обрабатывать команды push back и pop front.
//
//Формат ввода
//В первой строке количество команд n.n ≤ 1000000.
//
//Каждая команда задаётся как 2 целых числа : a b.
//
//a = 2 - pop front
//a = 3 - push back
//
//Если дана команда pop front, то число b - ожидаемое значение.Если команда pop front вызвана для пустой структуры данных, то ожидается “ - 1”.
//
//Формат вывода
//Требуется напечатать YES - если все ожидаемые значения совпали.Иначе, если хотя бы одно ожидание не оправдалось, то напечатать NO.

#include <iostream>
#include <cassert>

//Stack и его конструкция

class Stack {
public:
    Stack(int size);
    Stack();
    ~Stack();

    Stack(Stack&) = delete;
    Stack operator=(const Stack&) = delete;

    void push(int single_element);
    int pop();

    bool is_empty();
private:
    int buff_size;
    int* buff;
    int top;
};

Stack::Stack(int size) {
    buff_size = size;
    buff = new int[buff_size];
    top = -1;
}

Stack::Stack() {
    top = -1;
    buff_size = 0;
    buff = new int[buff_size];
}

Stack::~Stack() {
    delete[] buff;
}

bool Stack::is_empty() {
    if (top == -1) {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::push(int single_element) {
    if (top == buff_size - 1) {
        int new_size = 0;
        if (buff_size * 2 > 5) {
            new_size = buff_size * 2;
        }
        else {
            new_size = 5;
        }
        int* new_buff = new int[new_size];

        for (int i = 0; i < buff_size; i++) {
            new_buff[i] = buff[i];
        }
        delete[] buff;
        buff = new_buff;
        buff_size = new_size;
        
    }

    ++top;
    buff[top] = single_element;
}

int Stack::pop() {
    assert(top >= 0);
    int pop_element = buff[top];
    --top;
    return pop_element;
}

//Очередь и ее конструкция

class Queue {
public:
    Queue() = default;
    ~Queue();

    Queue(Queue&) = delete;
    Queue operator=(Queue&) = delete;
    
    void Enqueue(int single_element);
    int Dequeue();

private:
    Stack stack_in;
    Stack stack_out;
};

Queue::~Queue() {
    while (!stack_in.is_empty() && !stack_out.is_empty()) {
        Dequeue();
    }
}

void Queue::Enqueue(int single_element) {
    stack_in.push(single_element);
}

int Queue::Dequeue() {
    if (stack_out.is_empty()) {
        if (stack_in.is_empty()) {
            return -1;
        }
        else
        {
            while (!stack_in.is_empty()) {
                stack_out.push(stack_in.pop());
            }
        }
    }
    return stack_out.pop();
}

int main()
{
    int n = 0, command = 0, data = 0;
    bool result = true;
    std::cin >> n;
    Queue intQueue;
    for (int i = 0; i < n; ++i) {
        std::cin >> command >> data;
        switch (command) {
            case 2:
                if (intQueue.Dequeue() != data) {
                    result = false;
                }
                break;
            case 3:
                intQueue.Enqueue(data);
                break;
            default:
                break;
        }
    }
    std::cout << (result ? "YES" : "NO");
    return 0;
}
