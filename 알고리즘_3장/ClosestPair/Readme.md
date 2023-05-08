# 알고리즘 설계 구현 결과 보고서: <최근접 점의 쌍 찾기 알고리즘>

## 가. 문제 정의
### 문제이름 : 최근접 점의 쌍 찾기
### 문제설명 : 주어진 점들 중 최근접 점의 쌍을 찾는다.
### 문제예시 : 1,1 2,2 4,4 6,6 네개의 점들 중 가장 가까운 점은 1,1과 2,2 이고 거리는 이다.

## 나. 해결 아이디어
### 주어진 점들을 x좌표 기준으로 정렬하고, 점의 개수가 같게 되도록 점들을 왼쪽과 오른쪽으로 점들이 2개 혹은 3개가 될 때 까지 나눈다.(단 점들이 홀수일 때는 왼쪽보다 오른쪽에 점 하나를 더 둔다) 왼쪽에서 가장 가까운 점의 쌍의 거리와 오른쪽에서 가장 가까운 점의 쌍의 거리를 비교하여 더 짧은 쪽(d)을 고르고, 왼쪽과 오른쪽의 x좌표 기준 중간(m)에서 부터 m-d~m+d 사이에 있는 점의 쌍의 거리를 구하여 왼쪽 부분, 오른쪽 부분, 중간 부분에서 가장 짧은 거리의 점의 쌍을 반환한다. 위 방법을 반복하면 가장 짧은 점의 쌍을 구할 수 있다.

## 다. 알고리즘
### 명칭: 최근접 점의 쌍 찾기 알고리즘 (ClosestPair(pairs, left, right, size))
### 입력: 점들의 집합
### 출력: 가장 가까운 점의 쌍
### 처리순서:
#### if (size=2)
#### 	return measureDistance(pairs+left, pairs+right)
#### else if(size=3)
#### 	distance1<- measureDistance(pairs, pairs + 1)
#### 	distance2<-measureDistance(pairs + 1, pairs + 2)
#### 	distance3<-measureDistance(pairs + 2, pairs)
#### 	min = minNum(distance1, distance2)
#### 	min = minNum(distance3, min)
#### 	return min
#### else
#### 	int mid = (left + right) / 2;
#### 	CPleft = ClosestPair(pairs, left, mid, mid - left + 1);
#### 	CPright = ClosestPair(pairs, mid + 1, right, right - mid);
#### 	distanceRange = minNum(CPleft, CPright);
#### 	pairsTmp = (coord*)malloc(sizeof(coord)*size);
#### 	cnt = 0;
#### 	minSub = -1;
#### 	for i = left to right
#### 		if (abs((pairs + i)->x - (pairs + mid)->x) < distanceRange)
#### 			(pairsTmp + cnt)->x = (pairs + i)->x;
#### 			(pairsTmp + cnt)->y = (pairs + i)->y;
#### 			cnt++;
#### 	for i = 0 to cnt
#### 		for j = i+1 to cnt
#### 			minSub = minNum(distanceRange, measureDistance(pairsTmp + i, pairsTmp + j));
#### 			if (minSub < distanceRange)
#### 				distanceRange = minSub;
#### 				if (minSub < min)
#### 					*minPairs = *(pairsTmp + i);
#### 					*(minPairs + 1) = *(pairsTmp + j);
#### 	free(pairsTmp);
#### 	return distanceRange;
## 라. C코드 설계
### 1. 자료 구조 정의
#### - 점들의 집합 : pairs (coord []) - 좌표 배열
#### - 점 사이의 거리 : distance (double) - 실수

### 2. 함수 정의
#### - 함수 기능 : 점의 개수가 같게 되도록 점들을 왼쪽과 오른쪽으로 점들이 2개 혹은 3개가 될 때 까지 나눈다.(단 점들이 홀수일 때는 왼쪽보다 오른쪽에 점 하나를 더 둔다) 왼쪽에서 가장 가까운 점의 쌍의 거리와 오른쪽에서 가장 가까운 점의 쌍의 거리를 비교하여 더 짧은 쪽(d)을 고르고, 왼쪽과 오른쪽의 x좌표 기준 중간(m)에서 부터 m-d~m+d 사이에 있는 점의 쌍의 거리를 구하여 왼쪽 부분, 오른쪽 부분, 중간 부분에서 가장 짧은 거리의 점의 쌍을 반환한다.
#### - 함수 프로토 타입 : double ClosestPair(coord* pairs, int left, int right, int size)

## 마. 시험 계획
### 1. 테스트 케이스 설계
#### 임의의 점들의 집합 데이터 "data.txt" 를 읽어 점들을 배열에 저장한 다음 최근접 쌍을 찾고 결과를 "result.txt"에 쓴다.
### 2. 테스트 환경
#### Visual Studio에서 컴파일 후 실행파일을 명령어 창(cmd)에서 실행한다.
