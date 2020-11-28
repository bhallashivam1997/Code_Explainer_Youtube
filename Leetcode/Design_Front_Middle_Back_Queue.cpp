class FrontMiddleBackQueue {
public:
    deque<int>dq;
    FrontMiddleBackQueue() {
        dq=deque<int>();
    }
    
    void pushFront(int val) {
        dq.push_front(val);
    }
    
    void pushMiddle(int val) {
        int n=dq.size();
        n=n/2;
        stack<int>s;
        for(int i=0;i<n;i++){
            s.push(dq.front());
            dq.pop_front();
        }
        dq.push_front(val);
        while(!s.empty()){
            dq.push_front(s.top());
            s.pop();
        }
        return;
    }
    
    void pushBack(int val) {
        dq.push_back(val);
    }
    
    int popFront() {
        if(dq.size()==0)
            return -1;
        int val=dq.front();
        dq.pop_front();
        return val;
    }
    
    int popMiddle() {
        if(dq.size()==0)
            return -1;
        int n=dq.size();
        if(n%2==1)
            n=n/2;
        else{
            n=n/2;
            n--;
        }
        stack<int>s;
        for(int i=0;i<=n;i++){
            s.push(dq.front());
            dq.pop_front();
        }
        int val=s.top();
        s.pop();
        while(!s.empty()){
            dq.push_front(s.top());
            s.pop();
        }
        return val;
    }
    
    int popBack() {
        if(dq.size()==0)
            return -1;
        int val=dq.back();
        dq.pop_back();
        return val;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */
