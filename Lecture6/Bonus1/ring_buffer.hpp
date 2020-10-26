#ifndef RING_BUFFER_HPP_
#define RING_BUFFER_HPP_

#include <array>
#include <mutex>
#include <memory>
#include <iostream>

template <class T, size_t SIZE=50>
class RingBuffer{
public:
	RingBuffer() = default;
	void put(T item);
	T get();
	void reset();
	bool empty() const;
	bool full() const;
	size_t capacity() const;
	size_t size() const;
  ~RingBuffer();

private:
	std::mutex mutex_;
	T* buf_ = new T[SIZE];
	size_t head_ = 0;
	size_t tail_ = 0;
	const size_t max_size_ = SIZE;
	bool full_ = 0;
};

template <class T, size_t SIZE>
void RingBuffer<T,SIZE>::reset(){
	std::lock_guard<std::mutex> lock(mutex_);
	head_ = tail_;
	full_ = false;
}
template <class T, size_t SIZE>
bool RingBuffer<T,SIZE>::empty() const{
	//if head and tail are equal, we are empty
	return (!full_ && (head_ == tail_));
}
template <class T, size_t SIZE>
bool RingBuffer<T,SIZE>::full() const{
	//If tail is ahead the head by 1, we are full
	return full_;
}

template <class T, size_t SIZE>
size_t RingBuffer<T,SIZE>::capacity() const{
	return max_size_;
}

template <class T, size_t SIZE>
size_t RingBuffer<T,SIZE>::size() const
{
	size_t size = max_size_;

	if(!full_)
	{
		if(head_ >= tail_)
		{
			size = head_ - tail_;
		}
		else
		{
			size = max_size_ + head_ - tail_;
		}
	}

	return size;
}

template <class T, size_t SIZE>
void RingBuffer<T,SIZE>::put(T item)
{
	std::lock_guard<std::mutex> lock(mutex_);

	buf_[head_] = item;

	if(full_)
	{
		tail_ = (tail_ + 1) % max_size_;
	}

	head_ = (head_ + 1) % max_size_;

	full_ = head_ == tail_;
}

template <class T, size_t SIZE>
T RingBuffer<T,SIZE>::get()
{
	std::lock_guard<std::mutex> lock(mutex_);

	if(empty())
	{
		return T();
	}

	//Read data and advance the tail (we now have a free space)
	auto val = buf_[tail_];
	full_ = false;
	tail_ = (tail_ + 1) % max_size_;

	return val;
}

template <class T, size_t SIZE>
RingBuffer<T,SIZE>::~RingBuffer(){
  delete [] this->buf_;
}

#endif