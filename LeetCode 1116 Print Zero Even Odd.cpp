// LeetCode 1116 Print Zero Even Odd.cpp

class ZeroEvenOdd {
public:
    ZeroEvenOdd(int n) {
        this->n = n;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this] { return state == 0; });
            printNumber(0);
            state = i % 2 ? 2 : 1;
            cv.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this] { return state == 2; });
            printNumber(i);
            state = 0;
            cv.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            unique_lock<mutex> ul(m);
            cv.wait(ul, [this] { return state == 1; });
            printNumber(i);
            state = 0;
            cv.notify_all();
        }
    }
    
private:
    int n, state = 0;
    mutex m;
    condition_variable cv;
};