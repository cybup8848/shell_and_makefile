#include <time.h>

#include <iostream>
#include <random>
#include <stack>
#include <vector>

#include "./bfprt/bfprt.h"
#include "./tradition/tradition.h"
using namespace TRADITION;
using namespace BFPRT;
std::vector<int> gen_data(int size) {
  std::default_random_engine engine(time(nullptr));
  std::uniform_int_distribution<int> int_dis(-10000, 10000);
  std::vector<int> res(size, 0);
  for (int i = 0; i < size; i++) {
    res[i] = int_dis(engine);
  }
  return res;
}

void quick_sort(std::vector<int> &data) {// frome small to big
  int size = data.size();
  std::stack<int> st;
  st.push(0);
  st.push(size - 1);
  while (!st.empty()) {
    int old_end = st.top();
    st.pop();
    int old_begin = st.top();
    st.pop();

    if (old_begin >= old_end) {
      continue;
    }

    int begin = old_begin;
    int end = old_end;
    int pivot_index = begin;// use first element as pivot
    int pivot = data[begin];

    while (begin < end) {// left is less to pivot and right is greater or equal to pivot
      while ((end > begin) && (data[end] >= pivot)) {  // To prevent extreme cases, end crosses the minimum border to the left
        --end;
      }
      while ((begin < end) && (data[begin] <= pivot)) {  // To prevent extreme cases, begin crosses the maximum border to the right;<= is to prevent first is the minimum
        ++begin;
      }
      std::swap(data[begin],data[end]);
    }
    data[pivot_index] = data[begin];
    data[begin] = pivot;
    st.push(old_begin);
    st.push(begin - 1);
    st.push(begin + 1);
    st.push(old_end);
  }
}

void print(const std::vector<int> &vec) {
  int size = vec.size();
  for (int i = 0; i < size; i++) {
    std::cout << vec[i] << "  ";
    if ((i != 0) && (i % 10 == 0)) {
      std::cout << std::endl;
    }
  }
  std::cout << std::endl;
}
int main(int argc, char **argv) {
  int size = 100;
  std::vector<int> data = gen_data(size);

  std::vector<int> copy_data = data;
  quick_sort(copy_data);

  bool flag_tradition = true;
  bool flag_bfprt = true;
  for (int i = 1; i <= size; i++) {
    int tradition_topk1 = TRADITION::tradition_topk(i, data);
    int bfprt_topk1 = BFPRT::bfprt_topk(i, data);

    if (tradition_topk1 != copy_data[i - 1]) {
      flag_tradition = false;
    }
    if (bfprt_topk1 != copy_data[i - 1]) {
      flag_bfprt = false;
    }
  }

  if (flag_tradition) {
    std::cout << "the result of tradition is right" << std::endl;
  } else {
    std::cout << "the result of tradition is wrong" << std::endl;
  }

  if (flag_bfprt) {
    std::cout << "the result of bfprt is right" << std::endl;
  } else {
    std::cout << "the result of bfprt is wrong" << std::endl;
  }
  return 0;
}
