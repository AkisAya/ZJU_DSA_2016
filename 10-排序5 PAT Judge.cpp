#include <stdio.h>

#define maxK 5

class Student{
	public:
		int id;
		int scores[maxK];
		int totalScore;
		int perfect;
		
		Student(){
			id = 0;
			perfect = 0;
			for(int i = 0; i < maxK; i++)
				scores[i] = -2;            // never answer the question
		}
		
		int getTotal() {
			int sum = 0;
			for(int i = 0; i < maxK; i++) {
				if(scores[i] >= 0)
					sum += scores[i];
			}
			return sum;
		}
		
		int setScore(int problem, int score) {
			if(scores[problem] < score)
				scores[problem] = score;
		}
		
		int setId(int i) {
			id = i;
		}
		
		int setPerfect(const int *fullScores, int K) {
			for(int i = 0; i < K; i++) {
				if(fullScores[i] == scores[i]) {
					perfect++;
				}
			}
		}
};

bool shouldPrint(Student &s) {
	bool flag = false;
	for(int i = 0; i < maxK; i++) {
		if(s.scores[i] > -1)
			flag = true;
	}
	return flag;
}

void print(Student &s, int K) {
	printf("%05d %d", s.id, s.getTotal());
	for(int i = 0; i < K; i++) {
		if(s.scores[i] >= 0) {
			printf(" %d", s.scores[i]);
		} else if(s.scores[i] == -1){
			printf(" %d", 0);			
		} else {
			printf(" -");
		}
					
	}	
}

void swap(Student &a, Student &b) {
	Student tmp = a;
	a = b;
	b = tmp;
}

void bubbleSort(Student *stus, int N) {
	
	bool flag;
	Student tmp;
	
	for(int i = N-1; i >= 0; i--) {
		flag = false;
		for(int j = 0; j < i; j++) {
			if(stus[j].getTotal() < stus[j+1].getTotal()) {
				swap(stus[j], stus[j+1]);
				flag = true;
			} else if(stus[j].getTotal() == stus[j+1].getTotal()) {
				if(stus[j].perfect < stus[j+1].perfect) {
					swap(stus[j], stus[j+1]);
					flag = true;
				} else if(stus[j].perfect == stus[j+1].perfect) {
					if(stus[j].id > stus[j+1].id) {
						swap(stus[j], stus[j+1]);
						flag = true;
					}
				}
			}
		}
		if(!flag) break;		
	}
}



int main() {
	int N, K, M;
	scanf("%d %d %d", &N, &K, &M);
	int fullScores[K];
	for(int i = 0; i < K; i++)
		scanf("%d", &fullScores[i]); 
	
	Student Stu[N];
			
	int id, problem, pScore;
	for(int i = 0; i < M; i++){
		scanf("%d %d %d", &id, &problem, &pScore);
		Stu[id-1].setScore(problem-1, pScore);
		Stu[id-1].setId(id);		
	}
	
	for(int i = 0; i < N; i++) {
		Stu[i].setPerfect(fullScores, K);
	}	
	
	bubbleSort(Stu, N);
	
	for(int i = 0; i < N; i++) {
		if(shouldPrint(Stu[i])) {
			printf("%d ", i+1);
			print(Stu[i], K);
			printf("\n");
		}
		
	}
	
	return 0;	
} 
