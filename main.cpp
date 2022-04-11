#include <stdio.h>
#include "Stack.h"

void prnMenu(){ //삽입, 삭제, 출력, 종료 기능이 있다는 것을 출력하는 함수이다
	cout<<"*******************************************"<<endl;
	cout<<"* 1. 삽입    2. 삭제    3. 출력   4. 종료 *"<<endl;
	cout<<"*******************************************"<<endl;
	cout<<endl;
	cout<<"원하시는 메뉴를 골라주세요: ";
}

int main(){
	    int mode, selectNumber, tmpItem;
		LinkedList<int> *p;
		bool flag = false;
		cout<<"자료구조 선택(1: Stack, Other: Linked List): "; //자료구조를 선택한다
		cin>>mode;		    
		if(mode == 1) //1을 입력한 경우 스택을 형성한다
			p = new Stack<int>();    // 정수를 저장하는 스택
		else //그 외에는 링크드 리스트를 형성한다
			p = new LinkedList<int>(); //정수를 저장하는 링크드리스트
		do{
			prnMenu();
			cin>>selectNumber;
			switch(selectNumber){ 
				case 1: //1번 메뉴를 선택한 경우
					cout<<"원하시는 값을 입력해주세요: ";
					cin>>tmpItem;    p->Insert(tmpItem); //스택 또는 링크드리스트에 원소를 삽입한다
					cout<<tmpItem<<"가 삽입되었습니다."<<endl; //원소가 삽입되었다는 것을 출력한다
					break;
				case 2: //2번 메뉴를 선택한 경우
					if(p->Delete(tmpItem)==true) //노드가 있는 경우 노드를 삭제한 후(스택의 경우 첫 번째 노드, 링크드 리스트의 경우 마지막 노드), 삭제된 원소를 출력한다
						cout<<tmpItem<<"가 삭제되었습니다."<<endl;
					else cout<<"비어있습니다. 삭제 실패"<<endl; //노드가 없는 경우 삭제 실패했다고 출력한다
					break;
				case 3: //3번 메뉴를 선택한 경우
					cout<<"크기: "<<p->GetSize()<<endl; //노드의 크기 출력
					p->Print(); //전체 노드 출력
					break;
				case 4: //4번 메뉴를 선택한 경우
					flag = true;     break; //반복문 형성을 위해 bool형 변수에 true를 저장한다
				default: //그 외 메뉴를 선택한 경우(잘못된 메뉴를 형성한 경우)
					cout<<"잘못 입력하셨습니다."<<endl;
					break;
			}
			if(flag) break; //4번 메뉴를 선택한 경우 반복문을 종료한다.
		} while(1);
		return 0;
}

