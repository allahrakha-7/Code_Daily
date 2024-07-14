class MyQueue {
private:
        stack<int> inputStack;
        stack<int> outputStack;

        void transferElements() {
            while (!inputStack.empty())
            {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

public:
    MyQueue() { }

    void push(int x) {
        inputStack.push(x);    
    }
    
    int pop() {
        if (outputStack.empty())
        {
            transferElements();
        }
        int topElement = outputStack.top();
        outputStack.pop();
        return topElement;
    }
    
    int peek() {
        if (outputStack.empty())
        {
            transferElements();
        }
        return outputStack.top();
    }
    
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */