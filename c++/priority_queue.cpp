#include <iostream>
#include <queue>
#include <cstdlib>
using namespace std;

void print(priority_queue< int, vector<int>, greater<int> > &q, size_t size) {
	for(size_t i = 0; i < size && cout<<q.top()<<" ";q.pop(), i++);
	cout<<endl;
}

int main() {
	int num;
	priority_queue< int, vector<int>, greater<int> > evenList, oddList;
	cin>>num;
	int* nums = (int*)calloc(num, sizeof(int));
	for(int i = 0; i < num && cin>>nums[i]; nums[i] % 2 == 0 ? evenList.push(nums[i]) : oddList.push(nums[i]), i++);
	cout<<evenList.size()<<" "<<oddList.size()<<endl;
	print(evenList, evenList.size());
	print(oddList, oddList.size());
	return 0;
}