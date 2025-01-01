#include<queue>
#include<stdexcept>
using std::queue;

class MyStack {
public:
    MyStack() = default;
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        if(empty()){
            throw std::out_of_range("Stack is empty");
        }
        else{
            int size = que.size();
            size--;
            while(size--){
                que.push(que.front());
                que.pop();
            }
            int result = que.front();
            que.pop();
            return result;
        }
    }
    
    int top() {
        if(empty()){
            throw std::out_of_range("Stack is empty");
        }
        return que.back();
    }
    
    bool empty() const{
        return que.empty();
    }
private:
    queue<int> que;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */