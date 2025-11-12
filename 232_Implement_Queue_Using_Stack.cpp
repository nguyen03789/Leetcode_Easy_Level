#include <iostream>
#include <stack>

class MyQueue {
private:
    std::stack<int> s;
    int front_element = 0;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(s.size() == 1) front_element = x;
    }
    
    int pop() {
        std::stack<int> s_temp;
        if(s.size() == 1){
            int res = s.top();
            s.pop();
            return res;
        }
        else{
            while(s.size() >  1){
                s_temp.push(s.top());
                s.pop();
            }
            int res = s.top();
            s.pop();
            front_element = s_temp.top();
            while(s_temp.size() != 0){
                s.push(s_temp.top());
                s_temp.pop();
            }
            return res;
        }
    }
    
    int peek() {
        return front_element;
    }
    
    bool empty() {
        return s.empty();
    }
};

int main(){
    // Code tuong tu bai 225
    return 0;
}