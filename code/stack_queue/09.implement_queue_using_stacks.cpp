#include<stack>
#include<stdexcept>

using std::stack;
class MyQueue {
public:
    MyQueue() = default;
    
    void push(int x) {
        st_in.push(x);
    }
    
    int pop() {
        if(empty()){
            throw std::out_of_range("Queue is empty");
        }
        transferStacks();
        int result = st_out.top();
        st_out.pop();
        return result;
    }
    
    // int peek() {
    //     // if(empty()){
    //     //     throw std::out_of_range("Queue is empty");
    //     // }
    //     int result = this->pop();
    //     st_out.push(result);
    //     return result;
    // }
    
    int peek(){
        if(empty()){
            throw std::out_of_range("Queue is empty");
        }
        transferStacks();
        return st_out.top();
    }

    bool empty() const {
        return st_out.empty() && st_in.empty();
    }
private:
    stack<int> st_in;
    stack<int> st_out;
    // 辅助函数：将 st_in 中的所有元素转移到 st_ou，即入栈到出栈的转移
    void transferStacks() {
        if(st_out.empty()){
            while(!st_in.empty()){
                st_out.push(st_in.top());
                st_in.pop();
            }
        }
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