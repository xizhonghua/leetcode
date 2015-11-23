/*

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.

*/

class MinStack {
public:
    void push(int x) {
        
        m_data.push(x);
        
        if(m_s.empty() || x <= m_s.top())
            m_s.push(x);
    }

    void pop() {
        if(!m_s.empty() && m_data.top() == m_s.top())
            m_s.pop();
        
        m_data.pop();
    }

    int top() {
        return m_data.top();
    }

    int getMin() {
        return m_s.empty() ? m_data.top() : m_s.top();
    }
private:
    stack<int> m_data;
    stack<int> m_s;
};
