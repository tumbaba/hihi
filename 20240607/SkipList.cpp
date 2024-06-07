#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

using namespace std;




 /*
    -- O(log n) : 알고리즘의 시간 복잡도를 나타내는 표기법 주 하나
 skip list는 평균적으로 O(log n)의 시간 복잡도를 갖는 검색, 삽입, 삭제를 지원하는 확률적인 자료구조
 이진 트리와 유사한 효율성을 가지면서도 구현이 간단하고 빠르게 동작하는 특징을 가지고 있다.

 스킵 리스트는 각 노드가 여러 개의 링크를 가질 수 있는데, 이 링크들이 'skip' 역활을 합니다
 이러한 링크들은 레벨(level)이라고 불리며, 각 노드는 다양한 레벨의 링크를 가질 수 있습니다.
 상위 레벨의 링크는 아래쪽 레벨로 빠르게 이동할  수 있게 도와주는 역활을 합니다.

 스킵 리스트의 레벨은 확률적으로 결정되는데, 높은 레벨일수록 해당 노드는 더 자주 건너 뛸수 있다.
 이를 통해 검색 연산의 평균 시간 복잡도를 줄일 수 있다.

 스킵리스트는 단순한 연결 리스트를 기반으로 하며, 각 노드는 키값을 가지고 있습니다. 노드는 키값을 기준으로
 오름차순으로 정렬되어 있습니다. 스킵리스트의 특정 노드를 찾는 과정은 이러한 링크를 통해 빠르게 이동하면서
 찾고자하는 키 값을 찾아가는 과정입니다.

 */


 //memset??
 // csiring제공 
 // 메모리 블록을 특정한 값으로 설정하는데 사용






// 노드 정의 
struct Node
{
	int value;       // 노드가 저장하는 값
	Node** forward;  // 다음 레벨의 노드에 대한 포인터 배열


	// 생성자
	Node(int level, int value)
	{
		this->value = value;
		forward = new Node * [level + 1];  // forward 포인터 배열 동적 할당
		memset(forward, 0, sizeof(Node*) * (level + 1));  // 초기화
	}

	~Node() 
	{
		delete[] forward;
	}
};

// 스킵 리스트 클래스 정의
class SkipList
{
private:
	int MAX_LEVEL;   // 최대 레벨
	float P;         // 확률
	int level;       // 현재 레벨
	Node* header;    // 헤더 노드

	// 랜덤 레벨 생성 함수
	int randomLevel()
	{
		int lvl = 0;
		// 확률 P에 따라 레벨을 랜덤하게 선택
		while ((rand() & 100) < (P * 100) && lvl < MAX_LEVEL)
		{
			lvl++;
		}
		return lvl;
	}
public:
	// 생성자 : 최대 레벨과 확률을 받아서 초기화
	SkipList(int maxLevel, float p) : MAX_LEVEL(maxLevel), P(p)
	{
		level = 0;
		header = new Node(MAX_LEVEL, -1); // -1은 헤더 노드의 값
	}
	~SkipList()
	{
		Node* current = header->forward[0];
		while (current != nullptr)
		{
			Node* next = current->forward[0];
			delete current;
			current = next;
		}
		delete header;
	}

	// 삽임 함수
	void insert(int value)
	{
		Node* current = header;
		Node** update = new Node*[MAX_LEVEL + 1];
		memset(update, 0, sizeof(Node*) * (MAX_LEVEL + 1));

		// 각 레벨별로 현재 노드를 업데이트할 노드들을 찾음
		for (int i = level; i >= 0; i--)
		{
			while (current->forward[i] != nullptr && current->forward[i]->value < value)
			{
				current = current->forward[i];
			}
			update[i] = current;
		}

		//현재 노드의 다음 노드가 nullptr이거나 햔재 노드의 값과 다른 경우에만 삽입
		current = current->forward[0];
		if (current == nullptr || current->value != value)
		{	// 랜덤한 레벨 선택
			int rlevel = randomLevel();
			// 랜덤 레벨이 현재 레벨보다 크면 업데이트 배열 갱신
			if (rlevel > level)
			{
				for (int i = level + 1; i <= rlevel; i++)
				{
					update[i] = header;
				}
				level = rlevel;
			}
			// 새 노드 생성
			Node* n = new Node(rlevel, value);
			// 업데이트 된 배열을 사용하여 새 노드를 링크
			for (int i = 0; i <= rlevel; i++)
			{
				n->forward[i] = update[i]->forward[i];
				update[i]->forward[i] = n;
			}
			cout << "Succeefully inserted key" << value << endl;
		}

	}

	// 검색 함수
	bool search(int value) const
	{
		Node* current = header;
		// 최상위 레벨부터 시작하여 검색
		for (int i = level; i >= 0; i--)
		{
			while (current->forward[i] && current->forward[i]->value < value)
			{
				current = current->forward[i];
			}
		}
		// 검색한 노드의 값을 반환하거나 없으면 false반환
		current = current->forward[0];
		if (current && current->value == value)
		{
			cout << "Found key : " << value << endl;
			return true;
		}
		else
		{
			cout << "key not found : " << value << endl;
			return false;
		}
	}

	// 삭제 함수
	void remove(int value)
	{
		Node* current = header;
		Node** update = new Node*[MAX_LEVEL + 1];
		memset(update, 0, sizeof(Node*) * (MAX_LEVEL + 1));

		// 각 레벨별로 삭제할 노드의 이전 노드를 찾음
		for (int i = level; i >= 0; i--)
		{
			while (current->forward[i] != nullptr && current->forward[i]->value < value)
			{
				current = current->forward[i];
			}
			update[i] = current;
		}
		// 삭제할 노드를 찾은 경우에만 삭제 수행
		current = current->forward[0];
		if (current != nullptr && current->value == value)
		{
			// 업데이트된 배열을 사용하여 삭제 수행
			for (int i = 0; i <= level; i++)
			{
				if (update[i]->forward[i] != current)
				{
					break;
				}
				update[i]->forward[i] = current->forward[i];
			}
		}
		delete current;

		// 레벨 조정
		while (level > 0 && header->forward[level] == nullptr)
		{
			level--;
		}
		cout << "Successfully deleted key " << value << endl;
	}

	//출력 함수
	void display() const
	{
		for (int i = 0; i <= level; i++)
		{	// 각 레벨별로 노드를 출력
			Node* node = header->forward[i];
			cout << "level" << i << " : ";
			while (node != nullptr)
			{
				cout << node->value << " ";
				node = node->forward[i];
			}
			cout << endl;
		}
	}
};


int main()
{



	srand((unsigned)time(0));

	SkipList list(3, 0.5);

	list.insert(3);
	list.insert(6);
	list.insert(7);
	list.insert(9);
	list.insert(12);
	list.insert(19);
	list.insert(17);
	list.insert(26);
	list.insert(21);
	list.insert(25);

	list.display();

	list.search(19);
	list.search(15);

	list.remove(19);
	list.remove(25);

	list.display();










	return 0;
}






















