#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q;
public:
    MyStack() {
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        queue<int> q_temp;
        if(!q.empty()){
            // dua phan tu cuoi cua queue q thanh phan tu dau cua q_temp va xoa
            while(q.size() != 1){
                q_temp.push(q.front());
                q.pop();
            }
        int res = q.front();
            q.pop();
            while (q.size() != q_temp.size()) {
                q.push(q_temp.front());
                q_temp.pop();
            }
            return res;
        }
        else return -1;
    }
    
    int top() {
        return q.back();
    }
    
    bool empty() {
        if(q.empty()) return 1;
        else return 0;
    }
};

int main(){
    MyStack* obj = new MyStack();
    obj->push(10);
    obj->push(20);
    obj->push(30);
    obj->push(40);
    int b = obj->pop();
    cout << b << endl;
    int a = obj->pop();
    cout << a << endl;
    int c = obj->pop();
    cout << c << endl;
    return 0;
}
