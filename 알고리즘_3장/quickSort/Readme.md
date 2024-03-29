# 알고리즘 설계 구현 결과 보고서: <퀵 정렬 알고리즘>

## 가. 문제 정의
### 문제이름 : 숫자 정렬하기
### 문제설명 : 주어진 숫자를 정렬한다.
### 문제예시 : 5,4,6,2 네 숫자를 정렬하면 2,4,5,6 이 된다.

## 나. 해결 아이디어
### 숫자들을 배열에 넣고, 배열 중에서 임의의 숫자를 고른 후, 고른 숫자를 기준으로 작은 숫자, 큰 숫자를 나누어 작은 숫자를 고른 숫자 왼편에, 큰 숫자를 고른 숫자 오른편에 둔다. 이와 같은 방법을 반복하면 정렬된 배열을 얻을 수 있다.

## 다. 알고리즘
### 명칭: 퀵 정렬 알고리즘 (quickSort(A,left,right))
### 입력: 숫자들의 집합 (A[left]~A[right])
### 출력: 정렬된 숫자 배열 (A[left]~A[right])
### 처리순서:
#### if(left<right)
#### 	pivot <- rand(left~right)
#### 	swap(A[left],A[pivot])
#### 	L<-left+1
#### 	R<-right
#### 	p<-left+1
#### 	while (L<=R)
#### 		L=left+1
#### 		R=right
#### 		while(L<=right && A[L]<A[left])
#### 			L++
#### 		while(R>=left && A[R]>A[left])
#### 			R--
#### 		if(L<R)
#### 			swap(A[L],A[R])
#### 	while(p<=right && A[p]<A[left])
#### 		p++
#### 	p--
#### 	swap(A[left],A[p]);
#### 	quickSort(A,left,,p-1)
#### 	quickSort(A,p+1,right)

## 라. C코드 설계
### 1. 자료 구조 정의
#### - 숫자들의 집합 : A (int []) - 정수 배열

## 2. 함수 정의
### - 함수 기능 : 배열 중에서 랜덤하게 값을 고르고 고른 값보다 작은 수를 고른값 왼편에, 큰 수를 고른값 오른편에 둔다.
### - 함수 프로토 타입 : void quickSort(A,left,right)

## 마. 시험 계획
### 1. 테스트 케이스 설계
#### 임의의 숫자들의 집합 데이터 "data.txt" 를 읽어 숫자들을 배열에 저장한 다음 퀵정렬하고 정렬한 데이터를 "result.txt" 파일에 복사한다.
### 2. 테스트 환경
#### Visual Studio에서 컴파일 후 실행파일을 명령어 창(cmd)에서 실행한다.
