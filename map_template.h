#ifndef MAP_TEMPLATE_H_INCLUDED
#define MAP_TEMPLATE_H_INCLUDED

#include <cstdlib>
#include <iostream>

using namespace std;

template <class K, class W> class cell
{
public:
  K = cell_key;
  W = cell_data;

  cell(K key = K(), W data = W())
  {
    this->cell_key = key;
    this->cell_data = data;
  }
};

class Employee
{
  public:
  string Name;
  string Position;
  int Age;

  Emplyee(char* n = "", char* p = "", int w = 0)
  {
    this->Name = n;
    this->Position = p;
    this->Age = w;
  };
};


template <class K, class W> class map_template
{
  typedef cell<K, W> tcell
  tcell*map_db;
  int size;

public:
  map_template()
  {
    this->map_db = (tcell) malloc(0 * sizeof(tcell));
    size = 0;
  };
  ~map_template()
  {
    free(this->map_db);
  };

  void defragment(map_template<K, W> &Wrong)
  {
    for(int i = 0; i < Wrong->size; i++)
      for(int j = 0; j < Wrong->size - i - 1;j++)
        if(Wrong->map_db[j].cell_key > Wrong->map_db[j+1].cell_key)
          swap(Wrong->map_db+j, Wrong->map_db+j+1);
  };

  void Add(K key, W data)
  {
    tcell *temp = (tcell) realloc(this->map_db, this->size  + 1);
    if(temp == NULL)
    {
      cout << "Allocation Error" << endl;
      return;
    }

    this->map_db = temp;
    this->map_db[size - 1].cell_key = key;
    this->map_db[size - 1].cell_data = data;

    defragment(this);
  };







};
#endif
