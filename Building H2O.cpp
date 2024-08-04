class H2O {
    int HCount = 0;
    int OCount = 0;

    queue<function<void()>> vHfunc;
    queue<function<void()>> vOfunc;

    mutex mt;
public:
    H2O() {
        
    }

    void hydrogen(function<void()> releaseHydrogen) {
        lock_guard<mutex> lock(mt);
        
        vHfunc.push(releaseHydrogen);
        int hCount = vHfunc.size();
        int oCount =  vOfunc.size();
        if(hCount >= 2 && oCount >= 1)
        {
            vHfunc.front()();
            vHfunc.pop();
            vHfunc.front()();
            vHfunc.pop();

            vOfunc.front()();
            vOfunc.pop();
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        lock_guard<mutex> lock(mt);

        vOfunc.push(releaseOxygen);
        int hCount = vHfunc.size();
        int oCount =  vOfunc.size();
        if(hCount >= 2 && oCount >= 1)
        {
            vHfunc.front()();
            vHfunc.pop();
            vHfunc.front()();
            vHfunc.pop();

            vOfunc.front()();
            vOfunc.pop();
        }
    }
};