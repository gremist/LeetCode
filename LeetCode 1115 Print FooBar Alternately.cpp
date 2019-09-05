// LeetCode 1115 Print FooBar Alternately.cpp

class FooBar {
public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this] { return state; });
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            state = false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this] { return !state; });
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            state = true;
            cv.notify_one();
        }
    }

private:
    int n;
    mutex m;
    condition_variable cv;
    bool state = true;
};