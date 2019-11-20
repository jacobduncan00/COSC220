#include "suqueuearr.h"
#include <iostream>

template <class DataType>
SUQueueArr<DataType>::SUQueueArr(){ // Constructor
	capacity = 3;
	front = 0;
	rear = 0;
	arr = new DataType[capacity];
}

template <class DataType>
SUQueueArr<DataType>::SUQueueArr(const SUQueueArr &obj){ // Copy Constructor
	capacity = obj.capacity ;
	front = obj.front;
	rear = obj.rear;
	for(int i = 0; i < capacity; i++){
		arr[i] = obj.arr[i];
	}
}

template <class DataType>
SUQueueArr<DataType>::~SUQueueArr(){
	delete[] arr;
}

template <class DataType>
int SUQueueArr<DataType>::size() const{ // get the number of elements in the queue
	return rear + 1;
}

template <class DataType>
bool SUQueueArr<DataType>::isEmpty() const{ // Check if the queue is empty
	return size() == 0;
}

template <class DataType>
void SUQueueArr<DataType>::enqueue(const DataType& add){ // Enqueues some data
	if(rear > capacity){
		std::cout << "Queue is Full" << std::endl;
		return;
	}else{
		arr[rear] = add;
		rear++;
	}
	return;
}

template <class DataType>
void SUQueueArr<DataType>::dequeue(DataType& del){ // Get the front element and store it
	if(rear > 0){
		del = arr[front];
		for(int i = 0; i < rear - 1; i++){
			arr[i] = arr[i + 1];
		}
		rear--;
	}
	return;
}

template <class DataType>
void SUQueueArr<DataType>::printQueue() const{ // Prints the queue from the front to the rear
	if(front == rear){
		std::cout << "Queue is Empty" << std::endl;
		return;
	}else{
		for(int i = 0; i < rear; i++){
			std::cout << arr[i] << std::endl;
		}
		return;
	}
}
