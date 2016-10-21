#include <cstdio>
#include <stack>

int main() {
	int M, N, K;
	scanf("%d %d %d", &M, &N, &K);
	std::stack<int> s;
	
	for (int i = 0; i < K; i++) {
		
		bool flag = true;
		int input = 1;
		int output;
		for (int j = 0; j < N; j++) {
			scanf("%d", &output);
			if (flag) {
				while (s.empty() || s.top() != output) {
					s.push(input);
					if (s.size() > M) {
						flag = false;
						break;
					}
					input ++;
				}
					
				if (flag && s.top() == output && s.size()>=1) {
					s.pop();
				} 		
			}
		}
		
		if (flag) printf("YES\n");
		else printf("NO\n");
		
		while (!s.empty()) s.pop();
	}
	
	return 0;
}



