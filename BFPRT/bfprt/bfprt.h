#include<vector>
namespace BFPRT {
int get_median(std::vector<int> data);
int bfprt(int num_every_group,const std::vector<struct base_index> &data);
int bfprt_topk(int k, std::vector<int> data, int num_every_group = 5);
} // namespace BFPRT
