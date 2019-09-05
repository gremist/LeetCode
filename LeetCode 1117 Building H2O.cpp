// LeetCode 1117 Building H2O.cpp

class H2O {
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this] { return H < 2 * O + 2; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        H++;
        cv.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> ul(m);
        cv.wait(ul, [this] { return O < H / 2 + 1; });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        O++;
        cv.notify_one();
    }
    
private:
    mutex m;
    condition_variable cv;
    int H = 0, O = 0;
};