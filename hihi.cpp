#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	std::vector<std::string>fields;
	// CSV ���� ���
	std::string filename = "data.csv";

	//���Ͽ���
	std::ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Failed to open the file : " << filename << endl;
		return 1;
	}
	//���Ͽ��� �� ������ ������ �б�
	std::string line;

	while (getline(file, line))
	{//���� ��ǥ�� �����ϱ� ���� stringstream���
		std::stringstream ss(line);
		std::string field;
		

		//��ǥ�� ���ҵ� �� �ʵ� �б�
		while (std::getline(ss, field, ','))
		{
			fields.push_back(field);
		}

		// �� �ʵ� ���
		for (const auto& f : fields)
		{
			cout << f << endl;
		}
		cout << endl;
	}
	file.close();
	
	cout << "����" << endl;
	for(int i = 0; i<fields.size(); i++)
	{
		cout << fields[i] << endl;
		
	}
	cout << "��" << endl;

	return 0;
}

