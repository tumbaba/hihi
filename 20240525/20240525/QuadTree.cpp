#include "stdafx.h"



class Point
{
public: 
	int x, y;
	Point(int _x, int _y) : x(_x), y(_y) {}
};

class QuadTree
{
private:
	//Bounds of this node
	int x, y, width, height;
	int capacity;
	bool divided;
	vector<Point*> points;
	QuadTree* northWest, * northEast, * southWest, * southEast;

public:
	QuadTree(int _x, int _y, int _width, int _height, int _capacity)
		: x(_x), y(_y), width(_width), height(_height), capacity(_capacity), divided(false),
		northWest(nullptr), northEast(nullptr), southWest(nullptr), southEast(nullptr) {}

	~QuadTree()
	{
		delete northWest;
		delete northEast;
		delete southWest;
		delete southEast;
	}

	bool contains(Point* point)
	{
		return (point->x >= x - width && point->x < x + width && point->y >= y - height && point->y < y + height);
	}
	void subdivide()
	{
		int halfWidth = width / 2;
		int halfHeight = height / 2;
		northWest = new QuadTree(x - halfWidth, y - halfHeight, halfWidth, halfHeight, capacity);
		northEast = new QuadTree(x + halfWidth, y - halfHeight, halfWidth, halfHeight, capacity);
		southWest = new QuadTree(x - halfWidth, y + halfHeight, halfWidth, halfHeight, capacity);
		southEast = new QuadTree(x + halfWidth, y + halfHeight, halfWidth, halfHeight, capacity);
		divided = true;
	}
	// 점을 트리에 삽입하는 함수
	bool insert(Point* point)
	{
		if (!contains(point))
		{   // 점이 현재 노드의 경계 내에 없으면 삽입하지 않음
			return false;
		}
		
		if (points.size() < capacity)
		{   // 현재 노드에 용량이 남이 있으면 점을 추가
			points.push_back(point);
			return true;
		}
		else
		{
			if (!divided)
			{
				subdivide();
			}
			// 자식 노드에 점을 삽입
			if (northWest->insert(point)) return true;
			if (northEast->insert(point)) return true;
			if (southWest->insert(point)) return true;
			if (southEast->insert(point)) return true;
		}
		return false;

	}

	// 주어진 범위 내에 있는 점들을 찾는 함수
	void query(int rangeX, int rangeY, int rangeWidth, int rangeHeight, vector<Point*>& found)
	{	// 범위가 현재 노드와 겹치치 않으면 반환
		if (rangeX + rangeWidth < x - width || rangeX - rangeWidth > x + width ||
			rangeY + rangeHeight < y - height || rangeY - rangeHeight > y + height)
		{
			return;
		}
		//현재 노드의 점들 중 범위 내에 있는 점들을 찾음
		for (auto p : points)
		{
			if (p->x >= rangeX - rangeWidth && p->x < rangeX + rangeWidth && p->y >= rangeY - rangeHeight && p-> y < rangeY + rangeHeight)
			{
				found.push_back(p);
			}
		}
		// 자식 노드 들에 대해 재귀적으로 퀴리 수행
		if (divided)
		{
			northWest->query(rangeX, rangeY, rangeWidth, rangeHeight, found);
			northEast->query(rangeX, rangeY, rangeWidth, rangeHeight, found);
			southWest->query(rangeX, rangeY, rangeWidth, rangeHeight, found);
			southEast->query(rangeX, rangeY, rangeWidth, rangeHeight, found);
		}
	}
	// 점을 트리에서 제거하는 함수
	bool remove(Point* point)
	{
		if (!contains(point))
		{
			return false;
		}
		// 현재 노드에서 점을 제거
		for (auto it = points.begin(); it != points.end(); it++)
		{
			if (*it == point)
			{
				points.erase(it);
				return true;
			}
		}
		// 자식이 분할되어 있으면 자식 노드에서 점을 제거
		if (divided)
		{
			if (northWest->remove(point)) return true;
			if (northEast->remove(point)) return true;
			if (southWest->remove(point)) return true;
			if (southEast->remove(point)) return true;
		}
		return false; 
	}
	// 현재 노드가 비었는지 확인하는 함수
	bool isEmpty() const
	{
		return points.empty() && (!divided || (northWest->isEmpty() && northEast->isEmpty() && southWest->isEmpty() && southEast->isEmpty()));
	}

	// 자식노드를 병합하는 함수
	void merge()
	{
		if (divided)
		{
			if (northWest->isEmpty() && northEast->isEmpty() && southWest->isEmpty() && southEast->isEmpty()) 
			{
				delete northWest;
				delete northEast;
				delete southWest;
				delete southEast;
				northWest = northEast = southWest = southEast = nullptr;
				divided = false;
			}
			
		}
	}
};






int main()
{
	// 쿼드 트리 생성 (중심 좌표 : (0,0) , 크기 : 8x8, 용량 1
	QuadTree qt(0, 0, 8, 8, 1);
	// 점들을 생성하여 벡터에 추가
	vector<Point>  points = { {1, 1}, {-5, 2}, {-3, 3}, {6, -1}, {-1, -4}, {3, 3}, {0, 0} };
	// 점들을 퀴드 트리에  삽입
	for (auto& p : points)
	{
		qt.insert(&p);
	}
	// 특정 벙위 내의 점들을 찾음 (주심 좌표:(0,0) 크기:5x5)
	vector<Point*> found;
	qt.query(0, 0, 5, 5, found);

	// 찾은 점들을 출력
	cout << "Points found in range (0,0) with width 5 and height 5 :" << endl;
	for (auto p : found)
	{
		cout << "(" << p->x << ", " << p->y << ")" << endl;
	}
	// 특정 정을 제거
	Point* pToRemove = &points[0]; // {1,1} 점을 제거
	if (qt.remove(pToRemove))
	{
		cout << "Point (" << pToRemove->x << ", " << pToRemove->y << ") removed" << endl;
	}
	else
	{
		cout<< "Point (" << pToRemove->x << ", " << pToRemove->y << ") not found" << endl;
	}
	
	// 찾은 점들을 출력
	
	found.clear(); // found 벡터를 초기화하여 이전에 찾은 점들을 비운다.

	qt.query(0, 0, 5, 5, found);
	cout << "Points found in range (0,0) with width 5 and height 5 :" << endl;
	for (auto p : found)
	{
		cout << "(" << p->x << ", " << p->y << ")" << endl;
	}

	return 0;
}