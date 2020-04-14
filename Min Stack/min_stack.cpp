#include <iostream>
#include <stack>
#include <vector>

template <class T>
class MinStack {
public:
    MinStack() = default;
    MinStack(std::vector <T>& v) {
        this->build(v);
    }
    ~MinStack() = default;
    void push(T x) {
        if (this->st_.empty()) {
            this->min_ = x;
            this->st_.push(x);
        }
        else if (x < this->min_)
        {
            this->st_.push(2 * x - this->min_);
            this->min_ = x;
        }
        else {
            this->st_.push(x);
        }
    }
	
    void pop() {
        T t = this->st_.top();
        this->st_.pop();
        if (t < this->min_)
            this->min_ = 2 * this->min_ - t;
    }

    T top() {
	    const T t = this->st_.top();
        if (t < this->min_) return this->min_;
        return t;
    }

    T get_min() const {
        return this->min_;
    }
private:
    void build(std::vector <T>& v) {
        for (auto el : v)
            this->push(el);
    }
    std::stack <T> st_;
    T min_;
};

int32_t main() {
    std::vector <int> v = { 1, 2, 5, -100, -5 };
    const MinStack <int> S(v);
    std::cout << S.get_min() << "\n";
    return 0;
}
