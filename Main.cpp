//#include "stdafx.h"
//
//
//
//
//
//  
//    
//
//
//    
//
//
//
//int main()
//{
//    
//	// ���Ͽ� �� ���ڿ�
//   
//	string textToWrite1 = "*";
//	
//	string textToWrite2 = " ";
//    string textToWrite3 = "\n";
//
//	// ���Ͽ� ���ڿ� ����
//	ofstream outputFile("example.txt");
//    
//    if (outputFile.is_open())
//    {
//        for (int b = 0; b <= 12; b++)
//        {
//            for (int c = b; c <= 12; c++)
//            {
//                outputFile << textToWrite2;
//            }
//            for (int f = 12 + b; 12 <= f; f--)
//            {
//                outputFile << textToWrite1;
//
//            }
//            for (int f = 11 + b; 12 <= f; f--)
//            {
//                outputFile << textToWrite1;
//            }
//            for (int c = b; c <= 12; c++)
//            {
//                outputFile << textToWrite2;
//            }
//            outputFile << textToWrite3;
//        }
//        for (int b = 0; b <= 12; b++)
//        {
//
//            for (int f = 12 + b; 12 <= f; f--)
//            {
//                outputFile << textToWrite2;
//
//            }
//            for (int c = b + 1; c <= 12; c++)
//            {
//                outputFile << textToWrite1;
//            }
//            for (int c = b; c <= 12; c++)
//            {
//                outputFile << textToWrite1;
//            }
//            for (int f = 12 + b; 12 <= f; f--)
//            {
//                outputFile << textToWrite2;
//            }
//
//            outputFile << textToWrite3;
//        }
//    
//		outputFile << textToWrite2 << endl;
//		outputFile << textToWrite1 << endl;
//		
//        
//
//		outputFile.close();
//		cout << "Text successfully written example.txt" << endl;
//
//	}
//	else
//	{
//		cout << "������ ���������� �������� ���߽��ϴ�. example.txt�ִ��� Ȯ�����ּ���" << endl;
//		return 1;
//	}
//
//    //���Ͽ��� ���ڿ� �б�
//    string readText;
//
//    ifstream inputFile("example.txt");
//    if (inputFile.is_open())
//    {
//        int i = 1;
//        while (getline(inputFile, readText))
//        {
//            cout << "���ι�ȣ : " << i << readText << endl;
//            i++;
//        }
//
//        inputFile.close();
//        cout << "Text read form the file : " << readText << endl;
//    }
//    else
//    {
//        cout << "Unable to open the file for reading  " << endl;
//    }
//
//    fstream file("exeample.txt", ios::in | ios::out | ios::app);//�б�, ����, ���ϳ��� �߰��ϱ�
//    if (file.is_open())
//    {
//        file << "hello, World!" << endl;
//        file.seekg(0); //������ ������ġ�� �̵�
//
//        string line;
//        int i = 1;
//        while (getline(file, line))
//        {
//            cout << "���ι�ȣ : " << i << "\n" << line << endl;
//            i++;
//        }
//        file.close();
//    }
//    else
//    {
//        cout<< "Unable to open the file for reading  " << endl;
//        return 1;
//    }
//
//    return 0;
//}