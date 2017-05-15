#include <iostream>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
stack<string> s;
string op;
string r[50];
int sum = 0;

int checkP(char c) {
	if (c == '(' || c == ')')
		return 1;
	else if (c == '+' || c == '-')
		return 2;
	else
		return 3;
}

int checkCurrentOp(string c) {
	if (c == "(") {
		s.push(c);
	}
	else if (c == ")") {
		while (s.top() != "("&&!s.empty()) {
			if (s.top() != "(") {
				r[sum] = s.top();
				sum++;
			}
			s.pop();
		}
	}
	else if (c == "*" || c == "/" || c == "+" || c == "-") {
		op = s.top();
		int p1 = checkP(op);
		int p2= checkP(c);
		if (p1 < p2||s.empty()) {
			s.push(c);
		}
		else {
			r[sum] = s.top();
			sum++;
			s.pop();
			checkCurrentOp(c);
		}

	}
	else if (c == '\n') {
		while (!s.empty()) {
			r[sum] = s.top();
			sum++;
			s.pop();
		}
		if (s.empty()) {
			return 0;
		}
			
	}
	else {
		r[sum] = c;
		sum++;
	}
		
}

void intToPost() {
	string c;
	getline(cin, c);
	cin >> c;
	while (!cin.eof()) {
		checkCurrentOp(c);
		

		cin >> c;
	}
}
int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		memset(r, 0, sizeof(r));
		sum = 0;
		op = NULL;
		for (int j = 0; j < sum; j++) {
			cout << r[j];
		}
		cout << endl;
		intToPost();
	}

	return 0;
}
