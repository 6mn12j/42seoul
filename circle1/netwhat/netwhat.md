## Network

: 두 대 이상의 컴퓨터가 논리적 또는 물리적으로 연결되어 통신이 가능한 상태.

규모에 따른 네트워크 종류

**PAN** (Personal Area Network) : 가장 작은 규모의 네트워크

**LAN** (Local Area Network) : 근거리 영역 네트워크, 로컬 영역 네트워크 , 구내 정보 통신망은 네트워크 매체를 이요하여 집, 사무실, 학교 등의 건물과 같은 가까운 지역을 한데 묶는 컴퓨터 네트워크이다.

**MAN** (Metropolital Area Network) : 대도시 영역 네트워크

**WAN** (Wide Area Network) :  광대역 네트워크

MAC 주소란?

데이터 링크 계층에서 통신을 위한 네트워크 인터페이스에 할당된 고유 식별자로 공장에서 출고될 때 부여되고 평생 사용하는 고유한 주소를 의미. 즉 LAN에서 목적지와 통신하기 위한 실질적인 주소가 바로 MAC주소.

ARP?

단말간 통신에서 단말과 단말은 IP를 이용하여 출발지와 목적지를 지정하며 실제 데이터 이동을 위해 MAC  주소를 함께 이용하는데 이때 IP주소와 MAC주소를 매칭하여 목적지 IP에 맞는 목적지 MAC주소로 전달. 이때 IP 주소와 MAC주소를 일대일 대응하여 테이블로 정리하고 목적지에 IP에 맞는 목적지 MAC주소로 전달하는데 이것을 ARP Table 이라고 부릅니다. (IP 주소와 MAC주소를 일대일 매칭시킨 정보를 정리해둔 테이블)

### IP, IP 주소

Internet Protocol의 약자로 기기간 네트워크 통신을 할 때 쓰는 프로토콜. 통신하는 방식

**IP 주소** '네트워킹이 가능한 장비를 식별하는 주소' 호스트(컴퓨터가) 보내는 데이터를 정확하게 다른 기기에 전달하기 위해서는 각각의 Host 들을 구분하여 컴퓨터가 주고받는 데이터를 정확하게 수신, 송신하기 위함.

- 네트워킹이 가능한 장비란 PC, 서버장비, 스마트폰, 테블릿pc, 인터넷이가능한 전자사전 등등 인터넷에 연결되는 모든 장비들

IP 주소는 IPv4 와 IPv6체계로 나뉘어진다. IPv4는 3자리 수자가 4마디로 표기되고 각 마디를 옥텟이라고 한다. 총 표기되는 숫자는 12개이고 내부적으로는 32비트로 처리된다. 123.123.123.123 을 예로 들면 011111011.01111011.01111011.01111011 로 표시된다.

주소고갈 문제로 인해서 32개의 이진수로 처리하던것을 128개의 이진수(128비트) 로 처리하는 IPv6가 나오게된다.

### IPv4 클래스

**클래스 A**는 대규모 네트워크 환경에 쓰이며, IP 주소 4마디 중 첫 번째 마디의 숫자가 0~127(약 1600만 개 IP 주소 사용 가능)까지 사용됩니다.**클래스 B**는 중규모 네트워크 환경용으로 128~191(약 6만 5천개 IP 주소 사용 가능)까지,**클래스 C**는 소규모 네트워크 환경에 적용되는 것으로 192~223(254개 IP 주소 사용 가능)까지 사용됩니다. 실제 사용되는 것은 A,B,C까지고 나머지**D 클래스**는 멀티캐스트용**E**는 연구/개발용 IP주소 혹은 미래에 사용하기 위해 남겨놓은 것으로 일반적인 용도로 사용되지 않습니다

### 라우터(Router)

즉, 라우터(Router)는 이름 그대로 네트워크와 네트워크 간의 경로(Route)를 설정하고 가장 빠른 길로 트래픽을 이끌어주는 네트워크 장비입니다.

- **라우터의 기능**

OSI7계층 중 **3 계층에** 속하는 장비이며 다음과 같이 크게 두 가지 기능을 합니다. 또한 3 계층이므로 **IP주소**를 사용하여 전달합니다. **단 서로 같은 프로토콜을 사용해야 합니다.**

- **경로 설정(path determination):**

데이터 패킷이 목적지까지 갈 수 있는 길을 검사하고 어떤 경로로 전송하는 것이 가장 효율적 일지 결정합니다.

- **스위칭(switching):**

경로가 결정되면 해당 경로로 데이터 패킷을 넘겨주는 것을 말합니다.

### 캐스트

**브로드캐스트** :

네트워크에 연결 되어잇는 모든 사용자들에게 통신. CPU 사용량이 늘어나는 문제가 있을 수도 있다.

**유니캐스트 :**

1 대 1로 통신

**멀티캐스트** :

그룹(특정 사용자들) 간 통신

### 패킷

네트워크가 전달하는 데이터의 형식화된 블록 ( 데이터를 주고받을 때 정해 놓은 규칙) pack + bucket

### 서브네팅?

네트워크 관리 성능을 향상 시키기 위해, 자원을 효율적으로 분배하는 것. 자원을 효율적으로 분배한다 → 네트워크 영역과 호스트 영역을 분할 하는 것.

너무 큰 브로드캐스트 도메인은 패킷전송을 느리게 하고 성능 저하를 발생 시키므로 네트워크를 쪼개서 성능을 보장한다. 서브넷 마스크는 `필요한 네트워크 주소만 호스트 IP로 할당 할 수 있게 만들어 네트워크 낭비를 방지` 한다.

- IP의 특징 : 하나의 IP는 `네트워크 부분 + 호스트 부분`으로 구성 하나의 네트워크 즉 하나의 브로드캐스트 도메인에 있는 IP끼리 통신하기 위해선 네트워크 영역이 같아야하며, IP충돌이 일어나지 않기 위해서는 호스트 IP는 달라야 한다.
- 네트워크 영역이 다르다면 라우터나 게이트웨이와 같은 통신장비를 통해 통신할 수 있다.  통신 장비 없이 통신할 수 있는 영역을 우리는 브로드캐스트 도메인 이라고 한다.

### 서브넷

서브넷은 말그대로 부분망 이라는 뜻. `IP 주소에서 네트워크 영역을 부분적으로 나눈 부분망, 부분 네트워크를 뜻한다`. 이 서브넷을 만들 때 쓰이는 것이 바로 서브넷 마스크 이 서브넷 마스크를 이용해서 네트워크주소와 호스트 주소를 분리할 수 있다.

### 서브넷 마스크

기본적인 형태는 IP주소와 같은 32bit 이진수. IP주소와 AND연산하여 네트워크 부분의 정보를 걸러내려는것.


IP주소 뒤에 124.25.9.3/24 같은 표시는 서브넷 마스크의 bit수를 의미한다. 서브넷 마스크의 Network ID부분은 1이 연속적으로 있어야 하며, Host ID 부분은 0이 연속적으로 있어야 하는 규칙이 있다.

- IP주소는 IP클래스에 의해 Network Prefix 와 Host Number 로 분리되게 된다. 서브넷팅을 통해서 Host Number  를 Subner Number와 서브넷 안에서 식별되는 Host Number 로 다시 분리한다.

호스트 범위 124.25.9.1~ 124.25.9.14

[https://engkimbs.tistory.com/622](https://engkimbs.tistory.com/622)

### ARP (Address Resolution Protocol)

 IP 주소를 MAC주소로 매칭 시키기 위한 프로토콜 로컬 네트워크에서 단말과 단말 간 통신을 하기 위해서는 IP주소와 함께 MAC주소를 이용하게 되는데, 이때 IP를 MAC 주소로 매칭하여 목적지 IP의 맥주소를 제대로 찾아가기 위함. 왜 IP주소를 MAC으로 매칭하는지? 알기위해서는 LAN과 MAC주소에  대해 이해해야 한다.

### DHCP

현재 사용하고 있지 않은 IP 를 다시 회수하고, IP사용을 요청하는 PC에게 동적으로 그때그때 사용되지 않고 놀고잇는 IP주소를 할당해 주는 방식의 프로토콜

신뢰적인 연결보다는 빠른속도가 중요하여 TCP 가아닌 UDP를 사용. 1대 다에게 다 확인함.

### SMTP (Simple Mail Transfer Protocol)?

email전송에 직접적으로 쓰이는 프로토콜.  TCP 를 통해 전달.

메시지가 생성되면 호출된 SMTP가 메시지를 받고 TCP를 이용하여 다른 호스트의 SMTP에게 전달한다.

### **HTTP**

Web 상에서 정보를 주고받기 위한 핵심 프로토콜이다. 정적인 텍스트 자원을 송/수신하기 위해 개발되었다. 애플리케이션 레벨의 프로토콜이다. 메시지 기반으로 동작한다. 프로토콜은 TCP80번 사용.

다른 목적으로도 사용될 수 있습니다. HTTP는 클라이언트가 요청을 생성하기 위한 연결을 연다음 응답을 받을때 까지 대기하는 전통적인 클라이언트-서버 모델을 따릅니다

### TCP

- (3 - way handshake)

나 연결할게 (클)→ 확인했어 연결해(서) → 연결했어.(클)

- (4 - way handeshake)

나종료할게 (클)→ 종료해도됨(서) → 종료확인해줘 (서)→ 종료확인했어.(클)



`Connection-Oriented Protocol` (`TCP`, `SCTP`, `RTP` 등)  `Connectionless Protocol` (`UDP`)

> **Which of this is not true?**

There is no sequencing of data in UDP. If ordering is required, it has to be managed by the application layer

UDP has only the basic error checking mechanism using checksums

UDP is a datagram-oriented protocol

UDP doesn't supports Broadcasting

UDP is faster, simpler and more efficient than TCP

The delivery of data to the destination cannot be guaranteed in UDP

### 사설 IP (Private IP)

**일반 가정이나 회사 내 등에 할당된 네트워크**의 IP 주소이며, 로컬 IP, 가상 IP라고도 한다. IPv4의 주소부족으로 인해 서브넷팅된 IP이기 때문에 라우터에 의해 로컬 네트워크상의 PC 나 장치에 할당된다.

### 사설IP 주소대역

사설IP 주소는 다음 3가지 주소대역으로 고정된다.

- Class A : **10**.0.0.0 ~ **10**.255.255.255
- Class B : **172.16**.0.0 ~ **172.31**.255.255
- Class C : **192.168**.0.0 ~ **192.168**.255.255

[NETWHAT](https://www.notion.so/NETWHAT-ebc8f498529c4b8386efca7b69e1631f)