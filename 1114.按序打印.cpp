#include <semaphore.h>
class Foo {
private:
    sem_t first1;
    sem_t second1;

public:
    Foo() {
        sem_init(&first1, 0, 0);
        sem_init(&second1, 0, 0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&first1);
    }

    void second(function<void()> printSecond) {
        sem_wait(&first1);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&second1);
    }

    void third(function<void()> printThird) {
        sem_wait(&second1);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};
