#include <iostream>
#include<string>
#include<stack>
using namespace std;
int t;
stack<char>s;
char r[50];
int sum;
int checkP(char c) {
	if (c == '(' || c == ')')
		return 1;
	else if (c == '+' || c == '-')
		return 2;
	else
		return 3;
}
void checkOp(char c) {
	if (c == '(') {
		s.push(c);
	}
	else if (c == ')') {
		char temp = s.top();
		while (temp != '(') {
			r[sum] = s.top();
			sum++;
			s.pop();
			temp = s.top();
		}
		s.pop();
	}
	else if (c == '*' || c == '/' || c == '+' || c == '-') {
		if (s.empty()) {
			s.push(c);
		}
		else {
			int p1 = checkP(s.top());
			int p2 = checkP(c);
			if (p2 > p1) {
				s.push(c); 
			}
			else {
				r[sum] = s.top();
				sum++;
				s.pop();
				checkOp(c);
			}
		}
	}
	else {
		r[sum] = c;
		sum++;
	}
		

}
void intToPost() {
	string temp;
	char c;
	memset(r, 0, sizeof(r));
	sum = 0;
	getline(cin, temp);
	if (temp.length() == 1) {
		c = temp[0];
	}
	while (c != '\n') {
		checkOp(c);
		getline(cin, temp);
		if (temp.length() == 1) {
			c = temp[0];
		}
		else
			break;
	}
	
	while (!s.empty()) {
		r[sum] = s.top();
		sum++;
		s.pop();
	}
	for (int i = 0; i < sum; i++) {
		cout << r[i];
	}
	cout << endl;
	
}
int main() {
	cin >> t;
	string te;
	getline(cin, te);
	
	for (int i = 0; i < t; i++) {
		getline(cin, te);
		intToPost();
	}
	return 0;
}
