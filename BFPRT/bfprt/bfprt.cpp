#include "bfprt.h"
namespace BFPRT {
// use insert sort to search the median of every group
int get_median(std::vector<int> data) {
  int size = data.size();
  for (int i = 1; i < size; i++) {
    int insert_val = data[i];
    int index = i - 1;
    while ((index >= 0) && (insert_val < data[index])) {
      data[index + 1] = data[index];
      index--;
    }
    data[index + 1] = insert_val;
  }
  return data[size / 2];
}


// the number of every group is num_every_group(eg 5)
int bfprt(int num_every_group,
                        const std::vector<int> &data) {
  int size = data.size();
  if (size == 1) {
    return data.back();
  }
  int groups = size / num_every_group;
  int rem = size % num_every_group;
  std::vector<int> medians; // store the median of every group
  std::vector<int>::const_iterator ibegin = data.begin();
  std::vector<int>::const_iterator iend = data.end();
  int median = 0;
  int i = 0;
  while (i < groups) {
    std::vector<int> tmp(ibegin + i * num_every_group,ibegin + (i + 1) * num_every_group);
    median = get_median(tmp);
    medians.emplace_back(median);
    ++i;
  }
  if (rem) {
    std::vector<int> tmp(ibegin + groups * num_every_group, iend);
    median = get_median(tmp);
    medians.emplace_back(median);
  }
  return bfprt(num_every_group, medians);
}

int bfprt_topk(int k, std::vector<int> data, int num_every_group) {
  int old_begin = 0;
  int old_end = data.size() - 1;
  int k_small = 0;
  while (true) {
    int begin = old_begin;
    int end = old_end;

    std::vector<int> tmp_vec(data.begin() + begin, data.begin() + end + 1);
    int pivot = bfprt(num_every_group, tmp_vec);
    int pivot_index=0;
    //find index of pivot;
    for(int i=begin;i<=end;i++){
      if(data[i]==pivot){
        pivot_index=i;
        break;
      }
    }
    std::swap(data[end],data[pivot_index]);
    int index=begin;
    for(int i=begin;i<end;i++){
      if(data[i]<pivot){
        std::swap(data[i],data[index++]);
      }
    }
    std::swap(data[index],data[end]);
    
    int number_of_left = index + 1;
    if (k == number_of_left) {
      k_small = pivot;
      break;
    } else if (k > number_of_left) {
      old_begin = index+1;
    } else {
      old_end = index-1;
    }
  }
  return k_small;
}

} // namespace BFPRT