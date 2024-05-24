#include "stdafx.h"



// LinkedListNode 정의
class LinkedListNode
{
public:
	int data;
	LinkedListNode* next;

	LinkedListNode(int val) : data(val), next(nullptr) {}
};

//Geid 정의
class Grid
{
private:
	int rows;
	int cols;
	vector<vector<LinkedListNode*>> grid;

public:

	int getRows() { return rows; }
	int getCols() { return cols; }

	Grid(int r, int c) : rows(r), cols(c)
	{
		grid.resize(rows, vector<LinkedListNode*>(cols, nullptr));
	}

	void setLinkedListNode(int row, int col, int data)
	{
		grid[row][col] = new LinkedListNode(data);
	}

	LinkedListNode* getLinkedListNode(int row, int col)
	{
		return grid[row][col];
	}

	void connectNode()
	{
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (i < rows - 1)
				{
					grid[i][j]->next = grid[i + 1][j];
				}
				if (j < cols - 1)
				{
					grid[i][j]->next = grid[i][j + 1];
				}
			}
		}

	}
	void removeLinkedListNode(int row, int col)
	{
		delete grid[row][col];
		grid[row][col] = nullptr;
	}

	LinkedListNode* searchLinkedListNode(int startRow, int startCol, int target)
	{
		for (int i = startRow; i < rows; ++i)
		{
			for (int j = startCol; j < cols; ++j)
			{
				LinkedListNode* currentNode = grid[i][j];
				while (currentNode != nullptr)
				{
					if (currentNode->data == target)
					{
						return currentNode;
					}
					else
					{
						return nullptr;
					}
					currentNode = currentNode->next;
				}
			}
		}
		return nullptr; // 찾지 못한경우
	}

	// Euclidean distance
	LinkedListNode* EuclideanSearchLLN(int target)
	{
		double minDistance = numeric_limits<double>::max();  // 초기화: minDistance를 가능한 최대값으로 설정
		LinkedListNode* closestNode = nullptr;

		int target_row;
		int target_col;

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				if (grid[i][j]->data == target)
				{
					target_row = i;
					target_col = j;
				}
			}
		}

		// 모든 노드를 탐색하여 유클리드 거리계산
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				LinkedListNode* currentNode = grid[i][j];
				while (currentNode != nullptr)
				{
					// 유클리드 거리 계산   sqrt(루트) pow(제곱)
					double distance = sqrt(pow(i - target_row, 2) + pow(j - target_col, 2));
					if (i == target_row && j == target_col)
					{

					}
					else if (distance < minDistance)
					{
						minDistance = distance;
						closestNode = currentNode;
					}
					currentNode = currentNode->next;

				}
			}
		}
		return closestNode;
	}

	// 맨해튼 거리
	LinkedListNode* MsearchLLN(int startRow, int startCol, int target)
	{
		int maxDistance = rows + cols - 2;// 최대 맨해튼 거리
		for (int distance = 0; distance <= maxDistance; ++distance)
		{
			for (int i = max(0, startRow - distance); i <= min(rows - 1, startRow + distance); ++i)
			{
				for (int j = max(0, startCol - (distance - abs(startRow - i))); j <= min(cols - 1, startCol + (distance - abs(startRow - i))); ++j)
				{
					LinkedListNode* currentNode = grid[i][j];
					while (currentNode != nullptr)
					{
						if (currentNode->data == target)
						{
							return currentNode;
						}
						currentNode = currentNode->next;
					}
				}
			}
		}
		return nullptr; // 찾지 못한 경우
	} 

};




int main()
{	
	Grid myGrid(3,3);

	// LinkedList 설정
	myGrid.setLinkedListNode(0,0,1);
	myGrid.setLinkedListNode(0,1,2);
	myGrid.setLinkedListNode(0,2,3);
	myGrid.setLinkedListNode(1,0,4);
	myGrid.setLinkedListNode(1,1,5);
	myGrid.setLinkedListNode(1,2,6);
	myGrid.setLinkedListNode(2,0,7);
	myGrid.setLinkedListNode(2,1,8);
	myGrid.setLinkedListNode(2,2,9);
	
	myGrid.connectNode();

	//myGrid.removeLinkedListNode(1, 1);

	for (int i = 0; i < myGrid.getRows(); ++i)
	{
		for (int j = 0; j < myGrid.getCols(); ++j)
		{
			cout << "(" << i << ", " << j << ") : ";
			if (myGrid.getLinkedListNode(i, j) != nullptr)
			{
				cout << myGrid.getLinkedListNode(i, j)->data;
				if (myGrid.getLinkedListNode(i, j)->next != nullptr)
				{
					cout << "-> (" << myGrid.getLinkedListNode(i, j)->data;
				}
				else
				{
					cout << "-> None";
				}
			}
			else
			{
				cout << "None";
			}
			cout << endl;
			
		}
	}


	LinkedListNode* resultNode = myGrid.searchLinkedListNode(0, 0, 5);

	if (resultNode != nullptr)
	{
		cout << " Found node with data : " << resultNode->data << endl;

	}
	else
	{
		cout << "Node not found" << endl;
	}

	LinkedListNode* closestNode = myGrid.EuclideanSearchLLN(5);

	if (closestNode != nullptr)
	{
		cout << "Closest node found with data : " << closestNode->data << endl;
	}
	else
	{
		cout << "No node found" << endl;
	}

	LinkedListNode* resultNode1 = myGrid.MsearchLLN(0, 0, 5);

	if (resultNode1 != nullptr)
	{
		cout << "Found node with data : " << resultNode1->data << endl;
	}
	else
	{
		cout << "Node not found" << endl;
	}


	return 0;
}