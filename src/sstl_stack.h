#ifndef SSTL_SSTL_STACK_H
#define SSTL_SSTL_STACK_H

#include "sstl_deque.h"


namespace sstl {

template <class T, class Sequence = deque<T>>
class stack {
    friend bool operator==(const stack<T, Sequence>& x, const stack<T, Sequence>& y)
    {
        return x.c == y.c;
    }

    friend bool operator<(const stack<T, Sequence>& x, const stack<T, Sequence>& y)
    {
        return x.c < y.c;
    }

public:
    typedef typename Sequence::value_type       value_type;
    typedef typename Sequence::size_type        size_type;
    typedef typename Sequence::reference        reference;
    typedef typename Sequence::const_reference  const_reference;

protected:
    Sequence m_seq;

public:
    stack() { m_seq = new Sequence(); }
    explicit stack(size_type n) { m_seq = new Sequence(n); }
    stack(size_type n, const value_type& value)
    {
        m_seq = new Sequence(n, value);
    }
    ~stack() { delete m_seq; }

    bool empty() const { return m_seq->empty(); }
    size_type size() const { return m_seq->size(); }
    reference top() { return m_seq->back(); }
    const_reference top() const { return m_seq->back(); }
    void push(const value_type& x) { m_seq->push_back(x); }
    void pop() { m_seq->pop_back(); }
};

} // sstl


#endif //SSTL_SSTL_STACK_H
