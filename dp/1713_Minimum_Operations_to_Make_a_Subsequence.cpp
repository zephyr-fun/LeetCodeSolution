// 2022.05.06
// https://leetcode-cn.com/problems/minimum-operations-to-make-a-subsequence/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-oj7yu/
// 转为最长公共子序列问题，再转为最长递增子序列问题

// 当一个数组元素不重复时，最长公共子序列问题可以转换为最长递增子序列问题，从而可以将O(m*n)时间复杂度降为O(m + N*logN)
// 时间：O(M + N*logN)

// 空间：O(m+n)

// 例：
// target = [6,4,8,1,3,2]
// arr = [4,7,6,2,3,8,6,1]

// 原问题 ==》求：target和arr的最长公共子序列长度LCS
// 最少操作次数 = target.length- lcs
// 时间复杂度：O(n*m)，target.length, arr.length <= 10^5，无法通过

// 由于target中的元素不重复，可将两个数组转成对应target的下标数组：
// target': 0,1,2,3,4,5
// arr': 1,0,5,4,2,0,3
// 问题 ==》求：target'和arr'的最长公共子序列长度LCS

// 由于target'是严格单调递增的
// 问题 ==》求：arr'的最长递增子序列的长度LIS


// 最后整个算法流程为：

// 设当前已求出的最长上升子序列的长度为 \textit{len}len（初始时为 11），从前往后遍历数组 \textit{nums}nums，在遍历到 \textit{nums}[i]nums[i] 时：

// 如果 \textit{nums}[i] > d[\textit{len}]nums[i]>d[len] ，则直接加入到 dd 数组末尾，并更新 \textit{len} = \textit{len} + 1len=len+1；

// 否则，在 dd 数组中二分查找，找到第一个比 \textit{nums}[i]nums[i] 小的数 d[k]d[k] ，并更新 d[k + 1] = \textit{nums}[i]d[k+1]=nums[i]。

// 以输入序列 [0, 8, 4, 12, 2][0,8,4,12,2] 为例：

// 第一步插入 00，d = [0]d=[0]；

// 第二步插入 88，d = [0, 8]d=[0,8]；

// 第三步插入 44，d = [0, 4]d=[0,4]；

// 第四步插入 1212，d = [0, 4, 12]d=[0,4,12]；

// 第五步插入 22，d = [0, 2, 12]d=[0,2,12]。

// 无序列表最关键的一句在于： 数组 d[i]表示长度为 i 的最长上升子序列的末尾元素的最小值，即在数组 1,2,3,4,5,6中长度为3的上升子序列可以为 1,2,3也可以为 2,3,4等等但是d[3]=3，即子序列末尾元素最小为3。

// 无序列表解释清了数组d的含义之后，我们接着需要证明数组d具有单调性，即证明i<j时，d[i]<d[j]，使用反证法，假设存在k<j时，d[k]>d[j]，但在长度为j，末尾元素为d[j]的子序列A中，将后j-i个元素减掉，可以得到一个长度为i的子序列B，其末尾元素t1必然小于d[j]（因为在子序列A中，t1的位置上在d[j]的后面），而我们假设数组d必须符合表示长度为 i 的最长上升子序列的末尾元素的最小值，此时长度为i的子序列的末尾元素t1<d[j]<d[k]，即t1<d[k]，所以d[k]不是最小的，与题设相矛盾，因此可以证明其单调性

// 无序列表证明单调性有两个好处：1.可以使用二分法；2.数组d的长度即为最长子序列的长度；

class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> map;
        for(int i = 0; i < target.size(); i++) {
            map[target[i]] = i;
        }
        vector<int> lis;
        for(int i = 0; i < arr.size(); i++) {
            if(map.find(arr[i]) != map.end()) {
                lis.push_back(map[arr[i]]);
            }
        }
        int size = lis.size();
        if(size == 0) {
            return target.size();
        }
        vector<int> d(size + 1, 0);
        int len = 1;
        d[len] = lis[0];
        for(int i = 1; i < size; i++) {
            if(lis[i] > d[len]) {
                // cout << "if:" << i << endl;
                len++;
                d[len] = lis[i];
            }
            else {
                // cout << "else:" << i << endl;
                int left = 1;
                int right = len;
                int pos = 0;
                while(left <= right) {
                    int mid = left + (right - left) / 2;
                    if(d[mid] < lis[i]) {
                        pos = mid;
                        left = mid + 1;
                    }
                    else {
                        right = mid - 1;
                    }
                }
                d[pos + 1] = lis[i];
            }
        }
        return target.size() - len;
    }
};