#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <array>
#include <cstring>
#include <cstdint>

using namespace std;

// MurmurHash3 해시함수

uint32_t murmurhash3(const char* key, size_t len, uint32_t seed)
{
	// 이 변수들은 MurmurHash3의 알고리즘 상수값이다. 각각의 상수값은
	// 해시 값의 분포를 균일하게 하고, 충돌을 최소화하도록 선택된값들이다.

	uint32_t c1 = 0xcc9e2d51;    //c1,c2 : 해시 알고리즘에서 사용되는 사수 값들
	uint32_t c2 = 0x1b873593;	 
	uint32_t r1 = 15;            //r1,r2 : 해시 알고리즘에서 비트를 회전할 떄 사용되는 비트 수입니다. 
	uint32_t r2 = 13; 
	uint32_t m = 5;              // m,n: 해시 알고리즘에서 해시 값을 섞는 데 사용되는 값들
	uint32_t n = 0xe6546b64;
	uint32_t hash = seed;        // 초기 해시 값을 seed로 설정, 해시값에 영향을 미치는 값

	//블록 단위 처리 
	const int nblocks = len / 4;      // 입력 데이터의 길이를 4로 나누어 4바이트 블록의 수를 계산
	const uint32_t* blocks = (const uint32_t*)key;  //입력 데이터를 4바이트 단위로 처리하기위해
	int i;                                          // utnt32_t포인터로 캐스팅
	for (i = 0; i < nblocks; i++)
	{
		uint32_t k = blocks[i];
		k *= c1;                                     // 현재블럭('k')에 상수 c1을 곱함
		// 32비트 끼리 곱하면 64비트가 되지만 uint32_t로 변수가 정의되어있어서 32비트로 되면 뒤에값이 잘린다
		//그이유는 uint32_t는 unsigned integer로 정의 되있기 때문이다.
		k = (k << r1) | (k >> (32 - r2));            // k를 r1만큼 왼쪽으로 회전
		//(k<<r1) : k를 r1비트만큼 왼쪽으로 이동, 왼쪽끝에 밀려난 비트는 버려지고 오른쪽끝에는 0이 채워진다.
		// 비트 OR연산 '|' 위의 두 결과를 OR연산자로 결합, 왼쪽 쉬프트 연산에서 밀려난 비트가 오른쪽끝으로 돌아온다,
		k *= c2;                                     // k에 상수 c2를 곱한다
		hash ^= k;                                   // k를 현재 해시 값과 XOR연산
		hash = (hash << r2) | (hash >> (32 - r2));
	}

	// key의 남은 바이트들을 처리

	const uint8_t* tail = (const uint8_t*)(key + nblocks * 4);
	uint32_t k1 = 0;
	switch (len & 3)
	{
	case 3: k1 ^= tail[2] << 16;
	case 2: k1 ^= tail[1] << 8;
	case 1: k1 ^= tail[0];
		k1 ^= c1;
		k1 ^= (k1 << r1) | (k1 >> (32 - r1));
		k1 *= c2;
		hash ^= k1;
	}

	// 최종 믹싱 단계
	hash ^= len;
	hash ^= (hash >> 16);
	hash *= 0x85ebca6b;
	hash ^= (hash >> 13);
	hash *= 0xc2b2ae35;
	hash ^= (hash >> 16);

	return hash;

}


class BloomFilter
{
private:
	bitset<5000> bit_array; // 고정 크기의 비트셋, 크기 5000  // bitset 각 비트는 논리적인  
	int hash_count; // 해시 함수의 개수

public:
	// BloomFilter 생성자, 해시 함수 개수 설정
	BloomFilter(int size, int hash_count) : hash_count(hash_count) {
		// 비트셋은 고정 크기라 size를 설정하는 것은 불가능, 고정된 크기로 설정
	}

	// 원소를 불룸 필터에 추가하는 함수
	void add(const string& item)
	{
		for (int i = 0; i < hash_count; i++)
		{
			uint32_t hash = murmurhash3(item.c_str(), item.size(), i);
			bit_array[hash % bit_array.size()] = true;
		}
	}

	// 원소가 블룸 필터에 존재하는지 검사하는 함수
	bool query(const string& item)
	{
		for (int i = 0; i < hash_count; i++)
		{
			uint32_t hash = murmurhash3(item.c_str(), item.size(), i);
			if (!bit_array[hash % bit_array.size()])
			{
				return false;  // 하나라도 0이면 존재하지 않음
			}
		}
		return true;  // 모두 1이면 존재 가능성이 높음
	}
};




int main()
{
	BloomFilter bloom(5000, 7); // 비트셋 크기는 5000으로 고정, 해시 함수 개수는 7
	vector<string> items = { "apple", "banana", "cherry" };

	// 각 아이템을 블룸 필터에 추가
	for (const auto& item : items)
	{
		bloom.add(item);
	}

	cout << boolalpha; // true/false 대신 bool값을 출력
	cout << "apple : " << bloom.query("apple") << endl; // apple : true;
	cout << "banana : " << bloom.query("banana") << endl; // bananan : true;
	cout << "cherry : " << bloom.query("cherry") << endl; // cherry : true;
	cout << "grape : " << bloom.query("grape") << endl; // grape : false (False Positive 가능성 있음)


	return 0;
}