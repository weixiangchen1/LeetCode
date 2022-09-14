#include <pthread.h>
class FooBar {
private:
    pthread_mutex_t mutex1;
    pthread_mutex_t mutex2;

private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
        pthread_mutex_init(&mutex1, nullptr);
        pthread_mutex_init(&mutex2, nullptr);
        pthread_mutex_lock(&mutex2);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex1);
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            pthread_mutex_unlock(&mutex2);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex2);
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            pthread_mutex_unlock(&mutex1);

        }
    }
};
