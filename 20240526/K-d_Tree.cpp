#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;




struct Point
{
	vector<int> coordinates;

	Point(initializer_list<int> init_list) : coordinates(init_list) {}

	int operator[](size_t index) const
	{
		return coordinates[index];
	}
};

struct Node
{
	Point point;
	Node* left;
	Node* rigth;

	Node(const Point& pt) : point(pt), left(nullptr), rigth(nullptr) {}
};


Node* build_kd_tree(vector<Point>& points, int depth = 0)
{
	if (points.empty())
	{
		return nullptr;
	}

	size_t k = points[0].coordinates.size();
	size_t axis = depth % k;

	sort(points.begin(), points.end(), [axis](const Point& a, const Point& b) {return a[axis] < b[axis]; });

	size_t median = points.size() / 2;
	Node* node = new Node(points[median]);

	vector<Point> left_points(points.begin(), points.begin() + median);
	vector<Point> rigth_points(points.begin() + median + 1, points.end());

	node->left = build_kd_tree(left_points, depth + 1);
	node->rigth = build_kd_tree(rigth_points, depth + 1);

	return node;



}

void print_kd_tree(Node* node, int depth = 0)
{
	if (node != nullptr)
	{
		for (int i = 0; i < depth; ++i)
		{
			cout << " ";
		}
		for (size_t i = 0; i < node->point.coordinates.size(); ++i)
		{
			cout << node->point.coordinates[i] << (i + 1 == node->point.coordinates.size() ? "\n" : ", ");
		}
		print_kd_tree(node->left, depth + 1);
		print_kd_tree(node->rigth, depth + 1);
	}
}


int main()
{

	vector<Point> points = { {3,6},{17,15},{13,15},{6,12},{9,1},{2,7},{10,19} };

	Node* kd_tree = build_kd_tree(points);
	print_kd_tree(kd_tree);

	// Cleanup allocated memory
	// (In practice, use smart pointers or add a function to free memory)


	return 0;
}








