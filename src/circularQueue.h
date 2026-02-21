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
				const auto tail = (_head + _count) % _size;
				_data[tail] = value;
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
			size_t _count = 0;
	};
}
