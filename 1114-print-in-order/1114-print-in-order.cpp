class Foo {
private:
    atomic<int> x1;
    atomic<int> x2;
public:
    Foo() {
        x1 = 0;
        x2 = 0;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        x1++;
        // cout<<x1<<endl;
    }

    void second(function<void()> printSecond) {
        
        // printSecond() outputs "second". Do not change or remove this line.
        while(x1==0){
        }
        printSecond();
        x2++;
    }

    void third(function<void()> printThird) {
        
        // printThird() outputs "third". Do not change or remove this line.
        while(x2==0){
            
        }
        printThird();
    }
};