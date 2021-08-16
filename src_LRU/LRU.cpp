#include "LRU.h"
#include <iostream>

LRUCache::LRUCache(int capacity)
{
    size = capacity;
    head = NULL;
    tail = NULL;
}

void LRUCache::setFaults(int size){
	Faults.resize(size,0);
}
  
void LRUCache::printResult(int key){
    for(unordered_map <int,tpuntero>::iterator it=mp.begin();it!=mp.end();it++){
      	if(pass && key == (*it).first){//existe
      		printf("%s",KYEL);
      		cout<<" "<<(*it).first<<" ";
      		printf("%s",KWHT);
      	}else if(pass == false && key == (*it).first){//no existe
      		printf("%s",KRED);
      		cout<<" "<<(*it).first<<" ";
      		printf("%s",KWHT);
      	}else{
      		cout<<" "<<(*it).first<<" ";
      	}
	 }
  }
 
int LRUCache::get(int key)
  {
    unordered_map <int, tpuntero>::iterator it = mp.find(key);
    if (it != mp.end())
    {
      tpuntero node = it -> second;
      remove(node);
      setHead(node);
      return node -> value;
    }
    else
    {
      return -1;//no existe
    }
  }
 
void LRUCache::set(int key, int value,int index){
    unordered_map <int, tpuntero>::iterator it = mp.find(key);
    if (it != mp.end())
    {
      tpuntero node = it -> second;
      node -> value = value;
      remove(node);
      setHead(node);
      pass = true;
    }
    else{

      tpuntero newNode = new CacheNode(key, value);
      
      if ((int)mp.size() >= (int)size)
      {
  		unordered_map <int, tpuntero>::iterator iter = mp.find(tail -> key);
        remove(tail);
  		mp.erase(iter);
      }
      setHead(newNode);
      mp[key] = newNode;
      pass = false;
      Faults[index] = 1;
    }
  }
 
void LRUCache::remove(tpuntero node){

    if (node -> pre != NULL){
      node -> pre -> next = node -> next;
    }else{
      head = node -> next;
    }

    if (node -> next != NULL){
      node -> next -> pre = node -> pre;
    }else{
      tail = node -> pre;
    }

  }
 
void LRUCache::setHead(tpuntero node){
    node -> next = head;
    node -> pre = NULL;
 
    if (head != NULL)
    {
      head -> pre = node;
    }

    head = node;
    if (tail == NULL)
    {
      tail = head;
    }
}

void LRUCache::printFaults(int size){
	for(int i = 0; i < size; i++){
		if(Faults[i] == 1){//red
			printf("%s F %s",KRED,KWHT);
			num_faults++;
		}else{//white
			printf("%s A %s",KYEL,KWHT);
		}
	}
}

void LRUCache::FaultsP(){
	double result;
	printf("%s",KRED);
	cout<<"Fallos de Pagina: "<<num_faults<<endl;
	printf("%s",KWHT);
	cout<<"Referencias a Pagina: "<<Faults.size()<<endl;

	result = (double)num_faults/(double)Faults.size();
	result = result*(double)100;

	cout<<"Tasa de fallos >> "<<result<<" %"<<endl;
	cout<<"Tasa de aciertos >> "<<100-result<<" %"<<endl;
}






