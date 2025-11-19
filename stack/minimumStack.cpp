#include <stack>

using namespace std;

class MinStack {
    private:
        stack<int> stk, stkMin;  // utilizarei a classe stack builtin mesmo, e também um outro stack que guardará o valor mínimo 'atual'

    public:
        MinStack() {} // classe construtora, não há problema *nesse caso* de não ter nada

        void push(int val) {
            stk.push(val); // insere o valor normalmente

            if (stk.size() == 1) // se a stack principal só tiver 1 valor, insere na stackMin também, definindo o valor atual como mínimo
                stkMin.push(val);

            if (stk.top() < stkMin.top()) // se o valor do topo da stack principal for menor que o valor do topo da stack mínima
                stkMin.push(stk.top()); // adiciona o valor do topo da stack principal à stack mínima
            else // caso não for
                stkMin.push(stkMin.top()); // adiciona o valor do topo da stack mínima à ela mesma, *pois ele continua sendo o valor mínimo*
        }
        
        void pop() { // realiza a operação pop em ambas stacks
            stkMin.pop();
            stk.pop();
        }
        
        int top() {
            return stk.top();
        }
        
        int getMin() {
            return stkMin.top();
        }
};

/*
Input: ["MinStack", "push", 1, "push", 2, "push", 0, "getMin", "pop", "top", "getMin"]

Output: [null,null,null,null,0,null,2,1]

Explanation:
MinStack minStack = new MinStack();
minStack.push(1);
minStack.push(2);
minStack.push(0);
minStack.getMin(); // return 0
minStack.pop();
minStack.top();    // return 2
minStack.getMin(); // return 1
*/


int main() {
    MinStack minStack;

    minStack.push(1);
    minStack.push(2);
    minStack.push(0);
    minStack.getMin(); // return 0
    minStack.pop();
    minStack.top();    // return 2
    minStack.getMin(); // return 1

    return 0;
}