#include <semaphore.h>
class Foo {
private:
    sem_t x1;
    sem_t x2;
public:
    Foo() {
        sem_init(&x1,0,0);
        sem_init(&x2,0,0);
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        // x1++;
        sem_post(&x1);
        // cout<<x1<<endl;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        sem_wait(&x1);
        printSecond();
        // x2++;
        sem_post(&x2);
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
//         while(x2==0){
            
//         }
        sem_wait(&x2);
        printThird();
    }
};