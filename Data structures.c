// Data Structures
// 선형 구조: array, list, stack, queue, deque
// 비선형 구조: tree, graph

// array
// 장점: random access. index로 임의 접근 가능
// 단점: 아이템 추가, 삭제 시 아이템 이동 필요 (오버헤드 커짐)

// list
// 단점: 노드마다 포인터 변수를 갖고 있으므로 메모리 추가 필요
// head 부터 찾아가야 하므로 random access 불가
// 장점: 중간 삽입, 삭제가 빠르다

// 즉, 중간 삽입, 삭제가 빈번하면 list 아니면 array를 선택

// 이중 연결 리스트: 앞, 뒤 연결 모두 연결
// 원형 연결 리스트: 마지막 노드가 head를 가리킴

// stack: 한 쪽 방향으로 삽입(push), 삭제(pop) (LIFO). 즉 array로 구현
// queue: 삽입(enqueue), 삭제(dequeue). FIFO. 즉, 연결리스트로 구현
// dequeue: 양 방향으로 삽입, 삭제

// tree: 부모와 자식으로 구성
// graph: 시작점이 없음
