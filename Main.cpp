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
//	// 파일에 쓸 문자열
//   
//	string textToWrite1 = "*";
//	
//	string textToWrite2 = " ";
//    string textToWrite3 = "\n";
//
//	// 파일에 문자열 쓰기
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
//		cout << "파일을 정상적으로 저장하지 못했습니다. example.txt있는지 확인해주세요" << endl;
//		return 1;
//	}
//
//    //파일에서 문자열 읽기
//    string readText;
//
//    ifstream inputFile("example.txt");
//    if (inputFile.is_open())
//    {
//        int i = 1;
//        while (getline(inputFile, readText))
//        {
//            cout << "라인번호 : " << i << readText << endl;
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
//    fstream file("exeample.txt", ios::in | ios::out | ios::app);//읽기, 쓰기, 파일끝에 추가하기
//    if (file.is_open())
//    {
//        file << "hello, World!" << endl;
//        file.seekg(0); //파일의 시작위치로 이동
//
//        string line;
//        int i = 1;
//        while (getline(file, line))
//        {
//            cout << "라인번호 : " << i << "\n" << line << endl;
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