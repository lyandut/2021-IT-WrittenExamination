#include <iostream>

using namespace std;

/* 手写智能指针 */

template<typename T>
class SmartPtr {
public:
    // 构造函数
    SmartPtr(T *p=0) : _ptr(p) {
        if(p) _ref_cnt = new size_t(1);
        else _ref_cnt = new size_t(0);
    }
	// 拷贝构造
    SmartPtr(const SmartPtr &src) : _ptr(src._ptr), _ref_cnt(src._ref_cnt) {
        ++(*_ref_cnt);
    }
	// 析构函数
    ~SmartPtr() {
        if(--(*_ref_cnt) == 0) {
            delete _ptr;
            delete _ref_cnt;
            _ptr = nullptr;
            _ref_cnt = nullptr;
        }
    }
	// 重载赋值运算符
    SmartPtr<T>& operator=(const SmartPtr<T> &src) {
        if(this == &src) return *this;
        if(--(*_ref_cnt) == 0) {
            delete _ptr;
            delete _ref_cnt;
        }
        _ptr = src._ptr;
        _ref_cnt = src._ref_cnt;
        ++(*_ref_cnt);
        return *this;
    }

    // 第二种实现方式：先递增引用计数，防止自身赋值导致内存释放掉
    // SmartPtr<T>& operator=(const SmartPtr<T> &src) {
    //     ++(*src._ref_cnt);
    //     if(--(*_ref_cnt) == 0) {
    //         delete _ptr;
    //         delete _ref_cnt;
    //     }
    //     _ptr = src._ptr;
    //     _ref_cnt = src._ref_cnt;
    //     return *this;
    // }

    T& operator*() { return *_ptr; }

    T* operator->() { return _ptr; }

private:
    T *_ptr;
    size_t *_ref_cnt;
};

int main() {
    SmartPtr<char> p1(new char('a'));
    SmartPtr<char> p2(p1);
    SmartPtr<char> p3;
    p3 = p1;
    cout << *p1 << endl;
    cout << *p2 << endl;
    cout << *p3 << endl;
    return 0;
}