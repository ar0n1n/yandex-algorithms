#include <iostream>
using namespace std;

int main() {
	int n, target, min_dist(3000), cur_dist;
	int arr[1000];
	int ans;

	scanf("%i", &n);
	for (int i = 0; i < n; ++i)
	   scanf("%i", &arr[i]);
	cin >> target;

	for (int i = 0; i < n; ++i) {
		cur_dist = abs(arr[i] - target);
		if (cur_dist < min_dist) {
			min_dist = cur_dist;
			ans = arr[i];
		}
	}
	printf("%i", ans);
}