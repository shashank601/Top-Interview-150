class MinStack {
public:
    stack<int> st;
    stack<int> mn;

    MinStack() {
        
    }
    
    void push(int val) {
        if (mn.empty() || mn.top() >= val) {  <--  not strict
            mn.push(val);
        }    
        st.push(val);
    }
    
    void pop() {
        if (!st.empty() && mn.top() == st.top()) {
            mn.pop();
        }
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};
====

reason:

push 2
push 2 <-- if used '>'  this would not get pushed

pop()
mn become empty
st removes 2

st still have a val
and mn is empty    <-- violates the variant  should had atleast one element

pop()
mn.empty() but i used .top() on empty


