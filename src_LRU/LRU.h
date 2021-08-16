#include <unordered_map>
#include <vector>
#include <stdio.h>
//Colores
#define KNRM "\x1B[0m"
#define KRED "\x1B[31m"//RED
#define KCYN "\x1B[36m"//CYAN
#define KWHT "\x1B[37m"//WHITE
#define KYEL "\x1B[33m"//YELLOW

using namespace std;
using Vector = vector<int>;


struct CacheNode {
  int key;
  int value;
  CacheNode *pre, *next;
  CacheNode(int k, int v) : key(k), value(v), pre(NULL), next(NULL) {}
};

typedef struct CacheNode *tpuntero;
 
class LRUCache{
private:
	int size;//capacity                    
    tpuntero head, tail;
	unordered_map <int, tpuntero> mp;
	bool pass;  
	Vector Faults;
	int num_faults = 0;
public:
	void setFaults(int size);
	LRUCache(int capacity);
	void printResult(int key);
	int get(int key);
	void set(int key, int value,int index);
	void remove(tpuntero node);
	void setHead(tpuntero node);
	void printFaults(int size);
	void FaultsP();
};
