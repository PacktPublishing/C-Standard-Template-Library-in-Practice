#ifndef _circular_buffer_hpp
#define _circular_buffer_hpp

#include <array>
#include <iterator>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <stdexcept>

template<typename T, int cap, typename Container = std::array<T, cap>>
class CircularBuffer {
  public :
    using value_type = T;

    CircularBuffer() : _head(0), _tail(0), _size(0), _current(0), _capacity(cap) {}

    T& head() {
      return c.at(_head);
    }

    T& tail() {
      return c.at(_tail);
    }

    T const& head() const {
      return c.at(_head);
    }

    T const& tail() const {
      return c.at(_tail);
    }

    void push_back(T val) noexcept {
      if (_current >= _capacity) {
        _current = 0;
      }

      c.at(_current++) = val;
      
      _tail = _current - 1;
      
      if (_size++ >= _capacity) {
        _size = _capacity;
        _head++;
        if (_head >= _capacity) {
          _head = 0;
        }
      }
    }

    void place_back(T val) {
      if (full()) {
        throw std::overflow_error("place_back(): full buffer");
      }

      push_back(val);
    }

    void pop() {
      if (_size <= 0) {
        throw std::underflow_error("pop(): empty buffer");
      }

      _head++;
      if (_head >= _capacity) {
        _head = 0;
      }

      _size--;
    }

    std::size_t size() const noexcept {
      return _size;
    }

    std::size_t capacity() noexcept {
      return _capacity;
    }

    bool empty() const noexcept {
      return (size() <= 0);
    }

    bool full() const noexcept {
      return (int)size() >= _capacity;
    }

    typename Container::iterator begin() {
      return c.begin();
    }

    typename Container::iterator end() {
      return c.end();
    }

    friend std::ostream& operator<<(std::ostream& os, const CircularBuffer& buf) {
      return (os << "head: " << buf._head << ", tail: " << buf._tail << ", current: "
          << buf._current << ", capacity: " << buf._capacity << ", size: " << buf.size());
    }

  private :
    Container c;
    int _head;
    int _tail;
    int _size;
    int _current;
    int _capacity;
};

#endif
