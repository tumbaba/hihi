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
	// ���� Ʈ���� �����ϴ� �Լ�
	bool insert(Point* point)
	{
		if (!contains(point))
		{   // ���� ���� ����� ��� ���� ������ �������� ����
			return false;
		}
		
		if (points.size() < capacity)
		{   // ���� ��忡 �뷮�� ���� ������ ���� �߰�
			points.push_back(point);
			return true;
		}
		else
		{
			if (!divided)
			{
				subdivide();
			}
			// �ڽ� ��忡 ���� ����
			if (northWest->insert(point)) return true;
			if (northEast->insert(point)) return true;
			if (southWest->insert(point)) return true;
			if (southEast->insert(point)) return true;
		}
		return false;

	}

	// �־��� ���� ���� �ִ� ������ ã�� �Լ�
	void query(int rangeX, int rangeY, int rangeWidth, int rangeHeight, vector<Point*>& found)
	{	// ������ ���� ���� ��ġġ ������ ��ȯ
		if (rangeX + rangeWidth < x - width || rangeX - rangeWidth > x + width ||
			rangeY + rangeHeight < y - height || rangeY - rangeHeight > y + height)
		{
			return;
		}
		//���� ����� ���� �� ���� ���� �ִ� ������ ã��
		for (auto p : points)
		{
			if (p->x >= rangeX - rangeWidth && p->x < rangeX + rangeWidth && p->y >= rangeY - rangeHeight && p-> y < rangeY + rangeHeight)
			{
				found.push_back(p);
			}
		}
		// �ڽ� ��� �鿡 ���� ��������� ���� ����
		if (divided)
		{
			northWest->query(rangeX, rangeY, rangeWidth, rangeHeight, found);
			northEast->query(rangeX, rangeY, rangeWidth, rangeHeight, found);
			southWest->query(rangeX, rangeY, rangeWidth, rangeHeight, found);
			southEast->query(rangeX, rangeY, rangeWidth, rangeHeight, found);
		}
	}
	// ���� Ʈ������ �����ϴ� �Լ�
	bool remove(Point* point)
	{
		if (!contains(point))
		{
			return false;
		}
		// ���� ��忡�� ���� ����
		for (auto it = points.begin(); it != points.end(); it++)
		{
			if (*it == point)
			{
				points.erase(it);
				return true;
			}
		}
		// �ڽ��� ���ҵǾ� ������ �ڽ� ��忡�� ���� ����
		if (divided)
		{
			if (northWest->remove(point)) return true;
			if (northEast->remove(point)) return true;
			if (southWest->remove(point)) return true;
			if (southEast->remove(point)) return true;
		}
		return false; 
	}
	// ���� ��尡 ������� Ȯ���ϴ� �Լ�
	bool isEmpty() const
	{
		return points.empty() && (!divided || (northWest->isEmpty() && northEast->isEmpty() && southWest->isEmpty() && southEast->isEmpty()));
	}

	// �ڽĳ�带 �����ϴ� �Լ�
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
	// ���� Ʈ�� ���� (�߽� ��ǥ : (0,0) , ũ�� : 8x8, �뷮 1
	QuadTree qt(0, 0, 8, 8, 1);
	// ������ �����Ͽ� ���Ϳ� �߰�
	vector<Point>  points = { {1, 1}, {-5, 2}, {-3, 3}, {6, -1}, {-1, -4}, {3, 3}, {0, 0} };
	// ������ ���� Ʈ����  ����
	for (auto& p : points)
	{
		qt.insert(&p);
	}
	// Ư�� ���� ���� ������ ã�� (�ֽ� ��ǥ:(0,0) ũ��:5x5)
	vector<Point*> found;
	qt.query(0, 0, 5, 5, found);

	// ã�� ������ ���
	cout << "Points found in range (0,0) with width 5 and height 5 :" << endl;
	for (auto p : found)
	{
		cout << "(" << p->x << ", " << p->y << ")" << endl;
	}
	// Ư�� ���� ����
	Point* pToRemove = &points[0]; // {1,1} ���� ����
	if (qt.remove(pToRemove))
	{
		cout << "Point (" << pToRemove->x << ", " << pToRemove->y << ") removed" << endl;
	}
	else
	{
		cout<< "Point (" << pToRemove->x << ", " << pToRemove->y << ") not found" << endl;
	}
	
	// ã�� ������ ���
	
	found.clear(); // found ���͸� �ʱ�ȭ�Ͽ� ������ ã�� ������ ����.

	qt.query(0, 0, 5, 5, found);
	cout << "Points found in range (0,0) with width 5 and height 5 :" << endl;
	for (auto p : found)
	{
		cout << "(" << p->x << ", " << p->y << ")" << endl;
	}

	return 0;
}