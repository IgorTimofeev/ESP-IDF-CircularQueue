#pragma once

#include <cstddef>

namespace YOBA {
	template<typename _T, size_t _size>
	class CircularQueue {
		public:
			size_t size() const {
				return _size;
			}

			void push(const _T& value) {
				_tail = (_tail + 1) % _size;
				_data[_tail] = value;
				_count++;
			}

			void pop() {
				_head = (_head + 1) % _size;
				_count--;
			}

			const _T& front() const {
				return _data[_head];
			}

			bool empty() const {
				return _count == 0;
			}

			bool full() const {
				return _count == _size;
			}

		private:
			_T _data[_size] {};

			size_t _head = 0;
			size_t _tail = 0;
			size_t _count = 0;
	};
}
