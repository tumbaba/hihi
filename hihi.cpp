#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	std::vector<std::string>fields;
	// CSV 파일 경로
	std::string filename = "data.csv";

	//파일열기
	std::ifstream file(filename);
	if (!file.is_open())
	{
		cerr << "Failed to open the file : " << filename << endl;
		return 1;
	}
	//파일에서 줄 단위로 데이터 읽기
	std::string line;

	while (getline(file, line))
	{//줄을 쉼표로 분할하기 위해 stringstream사용
		std::stringstream ss(line);
		std::string field;
		

		//쉼표로 분할된 각 필드 읽기
		while (std::getline(ss, field, ','))
		{
			fields.push_back(field);
		}

		// 각 필드 출력
		for (const auto& f : fields)
		{
			cout << f << endl;
		}
		cout << endl;
	}
	file.close();
	
	cout << "시작" << endl;
	for(int i = 0; i<fields.size(); i++)
	{
		cout << fields[i] << endl;
		
	}
	cout << "끝" << endl;

	return 0;
}

