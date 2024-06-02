#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <array>
#include <cstring>
#include <cstdint>

using namespace std;

// MurmurHash3 �ؽ��Լ�

uint32_t murmurhash3(const char* key, size_t len, uint32_t seed)
{
	// �� �������� MurmurHash3�� �˰��� ������̴�. ������ �������
	// �ؽ� ���� ������ �����ϰ� �ϰ�, �浹�� �ּ�ȭ�ϵ��� ���õȰ����̴�.

	uint32_t c1 = 0xcc9e2d51;    //c1,c2 : �ؽ� �˰��򿡼� ���Ǵ� ��� ����
	uint32_t c2 = 0x1b873593;	 
	uint32_t r1 = 15;            //r1,r2 : �ؽ� �˰��򿡼� ��Ʈ�� ȸ���� �� ���Ǵ� ��Ʈ ���Դϴ�. 
	uint32_t r2 = 13; 
	uint32_t m = 5;              // m,n: �ؽ� �˰��򿡼� �ؽ� ���� ���� �� ���Ǵ� ����
	uint32_t n = 0xe6546b64;
	uint32_t hash = seed;        // �ʱ� �ؽ� ���� seed�� ����, �ؽð��� ������ ��ġ�� ��

	//��� ���� ó�� 
	const int nblocks = len / 4;      // �Է� �������� ���̸� 4�� ������ 4����Ʈ ����� ���� ���
	const uint32_t* blocks = (const uint32_t*)key;  //�Է� �����͸� 4����Ʈ ������ ó���ϱ�����
	int i;                                          // utnt32_t�����ͷ� ĳ����
	for (i = 0; i < nblocks; i++)
	{
		uint32_t k = blocks[i];
		k *= c1;                                     // �����('k')�� ��� c1�� ����
		// 32��Ʈ ���� ���ϸ� 64��Ʈ�� ������ uint32_t�� ������ ���ǵǾ��־ 32��Ʈ�� �Ǹ� �ڿ����� �߸���
		//�������� uint32_t�� unsigned integer�� ���� ���ֱ� �����̴�.
		k = (k << r1) | (k >> (32 - r2));            // k�� r1��ŭ �������� ȸ��
		//(k<<r1) : k�� r1��Ʈ��ŭ �������� �̵�, ���ʳ��� �з��� ��Ʈ�� �������� �����ʳ����� 0�� ä������.
		// ��Ʈ OR���� '|' ���� �� ����� OR�����ڷ� ����, ���� ����Ʈ ���꿡�� �з��� ��Ʈ�� �����ʳ����� ���ƿ´�,
		k *= c2;                                     // k�� ��� c2�� ���Ѵ�
		hash ^= k;                                   // k�� ���� �ؽ� ���� XOR����
		hash = (hash << r2) | (hash >> (32 - r2));
	}

	// key�� ���� ����Ʈ���� ó��

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

	// ���� �ͽ� �ܰ�
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
	bitset<5000> bit_array; // ���� ũ���� ��Ʈ��, ũ�� 5000  // bitset �� ��Ʈ�� ������  
	int hash_count; // �ؽ� �Լ��� ����

public:
	// BloomFilter ������, �ؽ� �Լ� ���� ����
	BloomFilter(int size, int hash_count) : hash_count(hash_count) {
		// ��Ʈ���� ���� ũ��� size�� �����ϴ� ���� �Ұ���, ������ ũ��� ����
	}

	// ���Ҹ� �ҷ� ���Ϳ� �߰��ϴ� �Լ�
	void add(const string& item)
	{
		for (int i = 0; i < hash_count; i++)
		{
			uint32_t hash = murmurhash3(item.c_str(), item.size(), i);
			bit_array[hash % bit_array.size()] = true;
		}
	}

	// ���Ұ� ��� ���Ϳ� �����ϴ��� �˻��ϴ� �Լ�
	bool query(const string& item)
	{
		for (int i = 0; i < hash_count; i++)
		{
			uint32_t hash = murmurhash3(item.c_str(), item.size(), i);
			if (!bit_array[hash % bit_array.size()])
			{
				return false;  // �ϳ��� 0�̸� �������� ����
			}
		}
		return true;  // ��� 1�̸� ���� ���ɼ��� ����
	}
};




int main()
{
	BloomFilter bloom(5000, 7); // ��Ʈ�� ũ��� 5000���� ����, �ؽ� �Լ� ������ 7
	vector<string> items = { "apple", "banana", "cherry" };

	// �� �������� ��� ���Ϳ� �߰�
	for (const auto& item : items)
	{
		bloom.add(item);
	}

	cout << boolalpha; // true/false ��� bool���� ���
	cout << "apple : " << bloom.query("apple") << endl; // apple : true;
	cout << "banana : " << bloom.query("banana") << endl; // bananan : true;
	cout << "cherry : " << bloom.query("cherry") << endl; // cherry : true;
	cout << "grape : " << bloom.query("grape") << endl; // grape : false (False Positive ���ɼ� ����)


	return 0;
}