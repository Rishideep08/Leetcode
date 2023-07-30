#include <semaphore.h>
class ZeroEvenOdd {
private:
    int n;
    sem_t x,z,w;
    atomic<int> count; 
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&z,0,0);
        sem_init(&w,0,0);
        sem_init(&x,0,1);
        count = 1;
        
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        // cout<<"HI in zero"<<endl;
        while(count.load()<=n){
            sem_wait(&x);
            // std::cout<<count<<endl;
            if(count.load()==n+1){
                sem_post(&z);
                sem_post(&w);
                continue;
            }
            printNumber(0);
            // cout<<count<<endl;
            if(count.load()%2==0){
                sem_post(&z);
            }else{
                sem_post(&w);
            } 

        }
    }

    void even(function<void(int)> printNumber) {
        // cout<<"HI in even"<<endl;
        while(count.load()<=n){
            sem_wait(&z);
            if(count.load() == n+1){
                continue;
            }
            
            printNumber(count.load());
            count++;
            sem_post(&x);
        }
        // sem_post(&w);
    }

    void odd(function<void(int)> printNumber) {
        // cout<<"HI in odd"<<endl;
        while(count.load()<=n){
            sem_wait(&w);
            if(count.load() == n+1){
                continue;
            }
            // cout<<"Hi in the odd\n";
            printNumber(count.load());
            count++;
            // cout<<count<<endl;
            sem_post(&x);
        }
        // sem_post(&z);
    }
    
    
};