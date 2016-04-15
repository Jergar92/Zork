#ifndef _VECTOR
#define _VECTOR
#include <assert.h>

template <class TYPE>
class Vector
{
private:
	int _maxCapacity = 10;
	int numElements = 0;

public:
	TYPE* buffer;

public:

	Vector()
	{
		buffer = new TYPE[_maxCapacity];
	}
	Vector(const Vector &copy){
		numElements = copy.numElements;
		_maxCapacity = copy._maxCapacity;
		buffer = new TYPE[_maxCapacity];
		for (int i = 0; i < _maxCapacity; i++){
			buffer[i] = copy.buffer[i];
		}
	}
	~Vector()
	{
	}
	void push_back(const TYPE &value){

		if (numElements >= _maxCapacity){
			_maxCapacity += 5;
			TYPE* temp = new TYPE[_maxCapacity];
			for (int i = 0; i < _maxCapacity; i++){
				*(temp + i) = *(buffer + i);
			}
			delete[] buffer;
			buffer = temp;
		}
		*(buffer + numElements++) = value;

	}
	void push_front(const TYPE &value){
		int i = 0;
		if (numElements + 1 >= _maxCapacity){
			TYPE* temp = new TYPE[_maxCapacity];
			_maxCapacity += 5;
			for (int i = 0; i < _maxCapacity; i++){
				*(temp + i) = *(buffer + i);
			}
			delete[] buffer;
			buffer = temp;
		}
		for (i = numElements + 1; i > 0; i--){
			*(buffer + i) = *(buffer + i - 1);
		}
		*(buffer + i) = value;
		numElements++;
	}
	void clean_selected(unsigned int index){
		int i = 0;
		for (i = index; i < size(); i++){
			buffer[i] = buffer[i + 1];
		}
		buffer[i] = '\0';
		numElements--;
	}
	bool empty()const{
		return *(buffer + 0) == '\0'
	}
	void clear(){
		numElements = 0;
	}
	int size()const{
		return numElements;
	}
	void capacity()const{
		return _maxCapacity;
	}
	TYPE &operator [](unsigned int index){
		assert(index >= 0 && index < numElements);
		return buffer[index];
	}
	TYPE operator [](unsigned int index)const{
		assert(index >= 0 && index < numElements);
		return buffer[index];
	}
	void pop_back(){
		for (int = numElements; i > 0; i--){
			*(buffer + i - 1) = *(buffer + i)
		}
	}
	void shrink_to_fit(){
		_maxCapacity = numElements;
		TYPE* temp = new TYPE[_maxCapacity];
		for (int i = 0; i < _maxCapacity; i++){
			*(temp + i) = *(buffer + i);
		}
		delete[] buffer;
		buffer = temp;
	}


};
#endif // !1

