#include "LinkedList.h"


//1. 템플릿 클래스로 확장해야함
//2. Stack형식으로 Delete 함수 재정의해야함
//주의: first, current_size는 class의 멤버 변수이기 때문에 this 포인터를 사용하여 가져와야함

//LinkedList class를 상속받음
template <typename T> class Stack : public LinkedList<T>{ //LinkedList class를 상속받음
	public:
		bool Delete (T &element){
			//first가 0이면 false반환
			if (this->current_size == 0) {
				return false;
			}
			Node<T>* tmp = this->first; // LinkedList와 달리 Stack은 current가 가리키는 곳을 삭제한다
			this->first = this->first->link;
			element = tmp->data;
			delete tmp; //메모리를 헤제한다
			this->current_size--; //스택 사이즈를 감소한다
			return true; //true를 반환한다
			}
};
