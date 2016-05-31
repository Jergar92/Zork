#ifndef __DobleList
#define __DobleList


template <class TYPE>
class List
{
private:
public:
	struct Node
	{
	private:
	public:
		TYPE data;
		Node* next = nullptr;
		Node* prev = nullptr;

	public:
		Node(const TYPE &value) : data(value)
		{}
		~Node(){}
	};
	Node* first_data = nullptr;
public:
	List(){}
	~List(){}
	bool empty() const{
		return first_data == nullptr;
	}
	unsigned int size() {
		unsigned int mySize = 0;
		Node* temp = first_data;
		while (temp != nullptr){
			mySize++;
			temp = temp->next;
		}
		return mySize;
	}
	Node* end(){
		Node* temp = first_data;
		Node* end = nullptr;
		while (temp != nullptr)
		{
			end = temp;
			temp = temp->next;
		}

		return end;
	}
	void Push_back(const TYPE &data){

		Node* item = new Node(data);
		Node* last = end();

		if (last != nullptr)
		{
			item->prev = last;
			last->next = item;
		
		}
		else{
			first_data = item;
		}

	}
	void Push_front(const TYPE &data){
		Node* temp = first_data;
		Node* newNode = new Node(data);
		if (temp != nullptr){
			newNode->next = first_data;
			first_data->prev = newNode;
		}
		first_data = newNode;
	}
	void Pop_back(){
		Node* temp = first_data;
		Node* save = first_data;
		if (temp != nullptr){

			if (temp->next != nullptr){
				while (temp->next != nullptr){
					temp = temp->next;
				}
				while (save->next != temp){
					save = save->next;
				}
				temp->prev = nullptr;
				delete temp;
				save->next = nullptr;
			}
			else{
				Node* temp = first_data;
				temp->prev = nullptr;
				delete temp;
				first_data = nullptr;
			}
		}
	}
	void Pop_front(){
		Node* temp = first_data;

		if (temp != nullptr){
			first_data = temp->next;
			delete temp;
		}
	}
	void Erase(Node* data){
		
			if (size() > 1)
			{
				if (data->prev == nullptr)
				{
					first_data = data->next;
					first_data->prev = nullptr;
				}
				else if (data->next == nullptr)
				{
					data->prev->next = nullptr;
				}
				else
				{
					data->prev->next = data->next;
					data->next->prev = data->prev;
				}
				delete data;
			}
			else
			{
				first_data = nullptr;
				delete data;
			}
		}

	void Insert(Node* pos, const TYPE &data){
		Node* temp = pos;
		Node* newNode = new Node(data);

		if (temp != nullptr){
			newNode->next = temp;
			newNode->prev = temp->prev;
			temp->prev->next = newNode;

		}
	else{
			first_data = newNode;
		}

	}
	
};
//ERASE Y INSERT

#endif // !__Header
