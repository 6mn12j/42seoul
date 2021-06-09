초기설정 꿀팁

```powershell
# vim 깔아서 쓰기
$ apt-get install vim
$ vi .vimrc

set number    " line 표시
set ai    " auto indent
set si " smart indent
set cindent    " c style indent
set shiftwidth=4    " 자동 공백 채움 시 4칸
set tabstop=4    " tab을 4칸 공백으로
set ignorecase    " 검색 시 대소문자 무시
set hlsearch    " 검색 시 하이라이트
set nocompatible    " 방향키로 이동 가능
set fileencodings=utf-8,euc-kr    " 파일 저장 인코딩 : utf-8, euc-kr
set fencs=ucs-bom,utf-8,euc-kr    " 한글 파일은 euc-kr, 유니코드는 유니코드
set bs=indent,eol,start    " backspace 사용가능
set ruler    " 상태 표시줄에 커서 위치 표시
set title    " 제목 표시
set showmatch    " 다른 코딩 프로그램처럼 매칭되는 괄호 보여줌
set wmnu    " tab 을 눌렀을 때 자동완성 가능한 목록
syntax on    " 문법 하이라이트 on
filetype indent on    " 파일 종류에 따른 구문 강조
set mouse=a    " 커서 이동을 마우스로 가능하도록
```

```bash
# 다이아몬드로 깨지는거 방지
$ vi .bashrc
#추가
export LANG=C

$ source .bashrc

```

## 1.sudo

```bash
#root 로 로그인 후 진행
$ su - root
$ apt-get install sudo

#sudo group 에 계정 추가 sudo  그룹에 추가 되어야 sudo 명령어 사용 가능
adduser <user-name> sudo

$ visudo
Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
Defaults badpass_message="<custom-error-message>"
Defaults logfile="/var/log/sudo/<file-name>"
Defaults log_input, log_ouput
Defaults passwd_tries=3
Defaults requiretty #tty를 할당 받지 않은 shell에서는 sudo 를 사용하지 못하게 하는 옵션.
```



## 2.포트

```bash
$ apt install ufw
$ sudo ufw status verbose
최초 설치시, UFW 방화벽은 기본적으로 비활성화되어 있으며 출력은 아래와 비슷합니다.

Status: inactive

다음 명령을 사용하여 UFW 방화벽을 활성화하거나 활성화 할 수 있습니다. 방화벽을로드하고 부팅 할 때이 방화벽을 시작해야합니다.
$ ufw enable
Firewall is active and enabled on system startup

#$ sudo ufw disable
#지금까지 UFW 방화벽을 활성화했다면 들어오는 모든 연결을 차단하고 원격 위치에서 SSH를 통해 서버에 연결 한 경우 더 이상 연결할 수 없습니다.

$ sudo ufw enable
Firewall is active and enabled on system startup

다음 명령을 사용하여 서버에 대한 SSH 연결을 사용 가능하게 설정하십시오.

$ sudo ufw allow ssh

$ ufw status verbose #포트 확인 22번 포트는 기본 포트

$ ufw status numbered #포트 넘버 확인
$ ufw delete <port-number>

$ ufw allow <port>
사용자 정의 SSH 포트 (예 : 포트 2222 )를 사용하는 경우 다음 명령을 사용하여 UFW 방화벽에서 해당 포트를 열어야합니다.

$ ufw allow 4242 # 4242 포트 열기 v4, v6 둘다 열림

```

## 3.ssh

:ssh ( secure shell) 시큐어 쉘의 약자. 보안 기능이 전제 되어 있는 프로토콜.

```bash
#openssh가 있는지 확인
$dpkg -l | grep oepnssh
#il openssh-client ~~ secure sshell(ssh)client, for secure access ~
#il openssh-server ~~ secure sshell(ssh)client, for secure access ~
#il openssh-sftp-server ~~ secure sshell(ssh)client, for secure access ~

$ service ssh start
$ service ssh status
#현재 실행중인 서비스 목록중 ssh가있는지 확인
$ service --status-all | grep +

#ssh 서비스가 몇번 포트를 점유하고 있는지 확인ufw
$vi apt-get install net-tools
$netstat -antp
```

## .ssh 설정

```bash
$  vi /etc/ssh/sshd_config

13번재 줄 기본 디폴트 포트 22번으로 설정
#Port 22
Port 4242

#ssh root접근 제한
#PermitRootLogin prohibit-password
PermitRootLogin no

#ssh 재시작
$ systemctl restart ssh
```

## .ssh 설정

```bash
$  vi /etc/ssh/sshd_config

13#Port 22
Port 4242

32#PermitRootLogin prohibit-password
PermitRootLogin no

#ssh 재시작
$ service ssh restart
```

1. 강력한 암호 정책을 설정하려면 다음 요구 사항을 준수해야 합니다.

- 비밀번호는 30일마다 만료됩니다.
- 비밀번호 수정 전까지 허용되는 최소 일수 2로 설정되다
- 비밀번호 만료 7일 전에 경고 메시지를 수신해야 합니다.
- 비밀번호는 10자 이상이어야 합니다. 대문자와 숫자를 포함해야 합니다. 또한 연속해서 동일한 문자를 3자 이상 포함할 수 없습니다.
- 비밀번호에는 사용자 이름이 포함되지 않아야 합니다.
- 비밀번호는 이전 비밀번호에 속하지 않는 7자 이상이어야 합니다.
- 물론 루트 비밀번호는 이 정책을 준수해야 합니다.

## 4. 패스워드 생성 정책

libpam-pwquality 모듈을 설치하고, 정책관련된 내용을 변경하면 된다.25~26 라인이며 추가된 내용은 아래와 같다.

`retry=3`

`minlen=10`

`difok=7`

`dcredit=-1 #숫자`

`ucredit=-1 #대문자`

`maxrepeat=3 #연속 동일한 문자`

`reject_username #사용자이름 포함 x`

`enforce_for_root #루트비밀번호도 이 정책을 준수`

```bash
$ sudo apt-get -y install libpam-pwquality
$ sudo vi /etc/pam.d/common-password

# line 25
# here are the per-package modules (the "Primary" block)
password requisite pam_pwquality.so retry=3 minlen=12 difok=7 dcredit=-1 ucredit=-1 maxrepeat=3 enforce_for_root reject_username
```

## 5. 패스워드 expired 정책

최대 30일 사용하고, 7일전에 알림을 표시하겠다는 내용이다.추가로, 최소 사용일도 제한할수 있다.

```
sudo vi /etc/login.defs

# 파일내용중 아래 부분을 변경한다.
PASS_MAX_DAYS   30
PASS_MIN_DAYS   2
PASS_WARN_AGE   7
```

이미 생성된 계정이 있다면 아래 명령을 통해 정책을 반영해야 한다.

- -M : 최대일수
- -m: 최소일수
- -w :경고 메시지

```bash
$ cut -f1 -d: /etc/passwd
$ sudo chage -M 30 -W 7  -m 2 계정명

# 확인
$ chage -l 계정명

Last password change					: Feb 17, 2021
Password expires					: May 18, 2021
Password inactive					: never
Account expires						: never
Minimum number of days between password change		: 0
Maximum number of days between password change		: 90
Number of days of warning before password expires	: 7
```

## 6.그룹

This user has to belong to the user42 and sudo groups.

```bash
# 유저 생성
useradd <user-name>

# 유저 삭제
userdel <user-name>

# 생성된 유저 조회
tail -n 3 /etc/passwd
# 그룹 조회
cat /etc/group

# 그룹 생성
groupadd <group-name>
tail -n 5 /etc/group
```

```bash
sudo group 에 계정 추가

adduser <user-name> <group-name>

#sudo, 와 suer42 그룹에만 속하게 됨
#-a 옵션을 같이 써주면 원래 있던 그룹에 추가
usermod -G sudo,user42 <user-name>

#그룹 확인
$ getent group <group-name>
<group-name>:x:27:<username>

#사용자의 그룹 확인
id <user-name>
usermod -g user42 minjupar42

#group 에서 user 삭제

gpasswd -d user_account group

sudo 가 가능한 그룹 확인

vi /etc/sudoers

```

## 7.스크립트

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2ac275b4-879a-40be-8b70-377feadb9d81/Screen_Shot_2021-05-28_at_11.46.26_PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2ac275b4-879a-40be-8b70-377feadb9d81/Screen_Shot_2021-05-28_at_11.46.26_PM.png)

```jsx

#!/bin/sh

ARCHITECTURE=`uname -a`
CPU_PHYSICAL=`grep "physical id" /proc/cpuinfo | sort -u | wc -l`
V_CPU=`grep -c processor /proc/cpuinfo`

LAST_BOOT=`uptime -s`

LVM_LM=`lsblk | grep lvm | wc -l`
if [ $LVM_LM -gt 0 ];then
        LVM_USE=yes
else
        LVM_USE=no
fi

TCP_NUMBER="`ss | grep -i tcp | wc -l ` ESTABLISHED"
USER_LOG=`who | wc -l`
MAC=`ip link show | grep ether| awk '{print $2}'`
IP=`hostname -I`

sudo=/var/log/sudo/sudo.log
SUDO_LINE=`cat $sudo | grep TSID | wc -l`

echo '#'Architecture: ${ARCHITECTURE}
echo '#'CPU physical : ${CPU_PHYSICAL}
echo '#'vCPU : ${V_CPU}

#echo '#'Memory Usage: ${MEMORY_USAGE}
#echo '#'Disk Usage: ${DISK_USAGE}
#echo '#'CPU load:${CPU_LOAD}
free -m | awk 'NR==2{printf "#Memory Usage: %s/%sMB (%.2f%%)\n", $3,$2,$3*100/$2}'
df -BM -a | grep /dev/mapper | awk '{sum1+=$3}{sum2+=$4}END{printf "#Disk Usage: %d/%dMB (%d%%)\n",sum1,sum2,sum1/sum2*100}'
mpstat | grep all | awk '{printf "#CPU Load: %.2f%%\n", 100-$12}'

echo '#'Last boot: ${LAST_BOOT}
echo '#'LVM use: ${LVM_USE}
echo '#'Connexions TCP : ${TCP_NUMBER}
echo '#'User log: ${USER_LOG}
echo '#'Network: IP ${IP} '('${MAC}')'
echo '#'Sudo : ${SUDO_LINE} cmd
```

## 호스트 네임 확인

```bash
$hostnamectl

# 호스트명 변경 방법
sudo hostname <바꾸려는호스트명>

#logoout 하면 바뀐 호스트명으로 볼 수 있다.
```

```bash
$ss -tunlp
dhcp 제거 ->dhcp 스태틱으로
```

DHCP 스태틱으로

[https://www.snel.com/support/how-to-configure-static-ip-on-debian-10/](https://www.snel.com/support/how-to-configure-static-ip-on-debian-10/)

```bash
$ifconfig
enp0s3:
inet 10.0.2.15 netmask 255.255.255.0 broadcast 10.0.2.255
ether 08

$route
Gateway 10.0.2.2

$more /etc/resolv.conf
nameserver 10.51.1.253
```

crontab

```bash
크론탭 설정
crontab -e

# */10 * * * * * /monitoring.sh | wall

크론탭 시작
service crond start

크론탭 중지
service crond stop
```