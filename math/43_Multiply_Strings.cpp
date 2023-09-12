// 2022.08.14
class Solution {
public:
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();
        vector<int> A;
        vector<int> B;
        vector<int> C(n + m, 0);
        for(int i = n - 1; i >= 0; i--) {
            A.emplace_back(num1[i] - '0');
        }
        for(int i = m - 1; i >= 0; i--) {
            B.emplace_back(num2[i] - '0');
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                C[i + j] += A[i] * B[j];
            }
        }
        for(int i = 0, t = 0; i < C.size(); i++) {
            t += C[i];
            C[i] = t % 10;
            t = t / 10;
        }
        int k = C.size() - 1;
        while(k > 0 && C[k] == 0) {
            k--;
        }
        string res = "";
        while(k >= 0) {
            res += C[k] + '0';
            k--;
        }
        return res;
    }
};

// 2023.09.12
// 设num1长度为n1，num2长度为n2，那么两数乘积的长度小于等于n1 + n2，用result(n1+n2)数组来保存结果
// 对于num1和num2，num1[i] * num2[j]的结果应该放在result[i+j+1]位置
// 遍历ij完成后，对result处理进位
class Solution {
public:
    string multiply(string num1, string num2) {
      int len1 = num1.size();
      int len2 = num2.size();
      vector<int> result(len1 + len2, 0);
      for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
          result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
      }
      // 处理进位
      for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] > 9) {
          result[i - 1] += result[i] / 10;
          result[i] = result[i] % 10;
        }
      }
      // 构造输出
      string output = "";
      for (int& x : result) {
        if (output.empty() && x == 0) {
          continue;
        }
        output.push_back(x + '0');
      }
      if (output.empty()) {
        return "0";
      }
        return output;
    }
};

// 2023.09.12
// 19. N! Plus
// Big Integer 大数阶乘 
// we have defined the necessary header files here for this problem.
// If additional header files are needed in your program, please import here.
#include <string>
#include <vector>

string multi(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    vector<int> result(len1 + len2, 0);
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            result[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
        }
    }
    for (int i = result.size() - 1; i >= 0; i--) {
        if (result[i] > 9) {
            result[i - 1] += result[i] / 10;
            result[i] = result[i] % 10;
        }
    }
    string output = "";
    for(int& x : result) {
        if(output.empty() && x == 0) {
            continue;
        }
        output.push_back(x + '0');
    }
    if(output.empty()) {
        return "0";
    }
    return output;
}
int main()
{  
  // please define the C++ input here. For example: int a,b; cin>>a>>b;;  
  // please finish the function body here.  
  // please define the C++ output here. For example:cout<<____<<endl;
    int num = 0;
    cin >> num;
    string result = "1";
    for (int i = 2; i <= num; i++) {
        result = multi(result, to_string(i));
    }
    cout << result << endl;
    return 0;
}
