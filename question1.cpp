#include <bits/stdc++.h>
using namespace std;

void interLeaveQueue(queue<int>& q)
{
	if (q.size() % 2 != 0)
		cout << "Input even number of integers." << endl;

	stack<int> s;
	int halfSize = q.size() / 2;

	for (int i = 0; i < halfSize; i++) {
		s.push(q.front());
		q.pop();
	}

	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	for (int i = 0; i < halfSize; i++) {
		q.push(q.front());
		q.pop();
	}

	for (int i = 0; i < halfSize; i++) {
		s.push(q.front());
		q.pop();
	}

	while (!s.empty()) {
		q.push(s.top());
		s.pop();
		q.push(q.front());
		q.pop();
	}
}

int main()
{
	queue<int> q;
    int n, temp;
    cout<<"Enter the number of elements:\n";
    cin>>n;
    cout<<"Enter each element:\n";
    for(int k=0;k<n;k++){
        cin>>temp;
        q.push(temp);
    }
	interLeaveQueue(q);
	int length = q.size();
	for (int i = 0; i < length; i++) {
		cout << q.front() << " ";
		q.pop();
	}
	return 0;
}
