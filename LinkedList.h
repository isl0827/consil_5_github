#ifndef __LINKEDLIST__
#define __LINKEDLIST__

#include <iostream>
using namespace std;

//LinkedList Node
template<typename T> class Node {
public:
	//데이터를 저장할 변수
	T data;
	//노드구조체 이용; 다음노드의 주소를 저장할 포인터
	Node* link;

	Node(T element) { //노드 
		data = element; //데이터 저장
		link = 0; //다음노드의 주소는 null 포인터
	}
};

//LinkedList Class
template<typename T> class LinkedList{
	protected:
		//첫번째 노드의 주소를 저장할 포인터
		Node<T> *first;
		int current_size;
	public:
		//생성자, 초기화 
		LinkedList(){
			first = 0;
			current_size = 0;
		};
		//노드 개수를 리턴하는 함수
		int GetSize(){
			return current_size;
		};
		//맨 앞에 원소를 삽입하는 함수, LinkedList와 Stack 둘다 같다
		void Insert(T element);
		//맨 뒤의 원소를 삭제하는 함수, LinkedList의 경우 제일 나중에 들어온 원소를 삭제한다
		virtual bool Delete(T &element);
		//리스트를 출력하는 함수
		void Print();
};


//새 노드를 맨 앞에 붙이고 값을 넣음
template <typename T> void LinkedList<T>::Insert(T element){
	//노드 생성
	Node<T> *newnode = new Node<T>(element);
	//새 노드가 첫번째 노드를 가리킴
	newnode -> link = first;
	first = newnode;
	current_size++; //노드의 사이즈 증가
}

template<typename T> bool LinkedList<T>::Delete(T &element){ //마지막 노드의 값을 리턴하면서 메모리에서 할당 해제
	if (first == 0) //노드가 없는 경우 false 리턴
		return false;
	Node<T> *current = first;
	Node<T> *previous = 0;
	while(1){ //마지막 노드까지 찾아가는 반복문
		if (current->link == 0){  //마지막 노드인 경우
			if (previous) //이전 노드가 존재하는 경우 이전 노드가 마지막 노드가 됨
				previous -> link = current -> link;
			else //이전 노드가 없는 경우 첫 번째 노드가 마지막 노드가 됨
				first = first -> link;
			break;
		}
		previous = current; 
		current = current -> link;
	}
	element = current -> data;
	delete current; //마지막 노드의 메모리 해제
	current_size--; //노드의 사이즈 감소
	return true; //true 리턴
}


template<typename T> void LinkedList<T>::Print(){ //리스트를 출력하는 Print 함수
	Node<T> *i;
	int index = 1;
	if (current_size != 0){ //사이즈가 0이 아닌 경우 리스트 출력
		for( i = first; i != NULL; i=i->link){ //노드 끝까지 출력
			if (index == current_size){ //마지막 노드에 도달한 경우에는 '->를 빼고 출력한다
				cout << "[" << index << "|";
				cout << i -> data <<"]";
			}
			else {
				cout << "[" << index << "|";
				cout << i -> data << "]->";
				index++;
			}
		}
		cout << endl;
	}
}


#endif
