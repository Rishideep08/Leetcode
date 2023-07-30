#include <semaphore.h>
class FooBar {
private:
    int n;
    sem_t x,y;
public:
    FooBar(int n) {
        this->n = n;
        sem_init(&x,0,1);
        sem_init(&y,0,0);
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            sem_wait(&x);
        	printFoo();
            sem_post(&y);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
            sem_wait(&y);
        	printBar();
            sem_post(&x);
        }
    }
};