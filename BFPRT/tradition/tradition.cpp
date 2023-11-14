#include "tradition.h"
namespace TRADITION {
int tradition_rand(int begin, int end) {
  std::default_random_engine engine(time(nullptr));
  std::uniform_int_distribution<int> int_dis(begin, end); //[begin,end]
  return int_dis(engine);
}

int tradition_topk(int k, std::vector<int> data) {
  int old_begin = 0;
  int old_end = data.size() - 1;
  int k_small = 0;

  while (true) {
    int begin = old_begin;
    int end = old_end;
    int pivot_index = tradition_rand(begin, end);
    int pivot = data[pivot_index];
    std::swap(data[pivot_index], data[old_end]);

    while(begin<end){
      while((begin<end)&&(data[begin]<=pivot)){
        ++begin;
      }
      data[end]=data[begin];
      while((begin<end)&&(data[end]>=pivot)){
        --end;
      }
      data[begin]=data[end];
    }
    data[begin]=pivot;

    int number_of_left = begin+1;
    if (k == number_of_left) {
      k_small = pivot;
      break;
    } else if (k > number_of_left) {
      old_begin = begin+1;
    } else {
      old_end = begin-1;
    }
  }
  return k_small;
}
} // namespace TRADITION