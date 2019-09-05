// LeetCode 1114 Print in Order.cpp

class Foo {
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        lock_guard<mutex> lg(m);
        step++;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this] { return step == 2; });
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        step++;
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this] { return step == 3; });
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
    
private:
    mutex m;
    condition_variable cv;
    int step = 1;
};