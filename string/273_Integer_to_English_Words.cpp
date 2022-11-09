// 2022.11.09
class Solution {
public:
	vector<string> num2str_small {
		"Zero", "One", "Two", "Three", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve",
		"Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen",
		"Eighteen", "Nineteen"
	};
	vector<string> num2str_medium {
		"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"
	};

	vector<string> num2str_large {
		"Billion", "Million", "Thousand", ""
	};

	string num2str(int x) {
		string res = "";
		if(x >= 100) {
			res += num2str_small[x / 100] + " Hundred ";
			x %= 100;
		}
		if(x >= 20) {
			res += num2str_medium[x / 10] + " ";
			x %= 10;
		}
		if(x != 0)
			res += num2str_small[x] + " ";
		return res;
	}

	string numberToWords(int num) {
		if(num == 0)
			return num2str_small[0];
		string s;
		for(int i = (int)1e9, j = 0; i >= 1; i /= 1000, j++) {
			if(num < i)
				continue;
			s.append(num2str(num / i) + num2str_large[j] + " ");
			num %= i;
		}
		while(s[s.length() - 1] == ' ')
			s.erase(s.end() - 1);
		return s;
	}
};