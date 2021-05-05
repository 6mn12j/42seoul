# Libft 
## memset
할당 받은 메모리를 특정 값으로 초기화 하는 함수.

```void* memset(void *ptr, int value, size_t num)```

**인자 값**
* ptr : 채우고자 하는 메모리의 시작 포인터(시작 주소).
  :void 포인터로 선언하게 되면 포인터 자료형이 달라도 컴파일 경고가 발생하지 않음.받을수는 있는데 비교하거나 옮기거나 할 수 없음 형이 무엇인지 몰라서 `unsigned char`로 선언해서 사용.
  
* value: 메모리에 채우고자 하는 값. int 형이지만 내부에선 unsigned char(1 byte)로 변환돼 저장.
  
* num: 채우고자 하는 바이트 수, 채우고자 하는 메모리 크기.
  
## bezero
할당 받은 메모리(n 만큼)를 'zero'값으로 채움, 만약 n이 zero 라면 
deptrcated 된 함수.

```void bzero(void *ptr, size_t n)```

**인자 값**
+ ptr :채우고자 하는 메모리의 시작 포인터(시작 주소).
+ num :채우고자 하는 바이트 수, 채우고자 하는 메모리 크기.

## memcpy

```void *memcpy(void *restrict dst, const void *restrict src, size_t n);```
src메모리 영역에서 dest 메모리 영역으로 n byte 만큼 복사.
메모리 영역은 겹치면 x. src와 dest 메모리 영역이 겹친다면 memmove 함수를 사용 

```

**반환 값**
dest 의 포인터를 반환.

src 문자 한자씩 dest 에 count 만큼 복사합니다. strcpy() 함수와 차이점은 문자열은 문자열의 끝을 Null byte로 구분하지만, 메모리는 Null byte 도 데이터이기 때문에 count를 명시적으로 지정해야만 합니다.
