> **Summary**: This document is a System Administration related exercise.

# Introduction

This project aims to introduce you to the wonderful world of virtualization.

You will create your first machine in VirtualBox (or UTM if you can’t use VirtualBox) under specific instructions. Then, at the end of this project, you will be able to set up your own operating system while implementing strict rules.

특정 지침에 따라 VirtualBox(또는 VirtualBox를 사용할 수 없는 경우 UTM)에서 첫 번째 시스템을 생성합니다. 그러면 이 프로젝트가 끝나면 엄격한 규칙을 구현하는 동안 자신만의 운영 체제를 설정할 수 있습니다.

# General guidelines

- The use of VirtualBox (or UTM if you can’t use VirtualBox) is mandatory.
- You only have to turn in a signature.txt file at the root of your repository. You must paste in it the signature of your machine’s virtual disk. Go to Submission and peer-evaluation for more information.
    - VirtualBox(또는 VirtualBox를 사용할 수 없는 경우 UTM)는 필수입니다.
    - signature.txt 파일을 저장소의 루트에 저장합니다.  signature.txt를 시스템 가상 디스크의 서명을 붙여넣어야 합니다. 자세한 내용을 보려면 제출 및 동료 평가로 이동하십시오.

[본투비루트](https://www.notion.so/8b4a55b006694ff18b890dfbb6c1e36b)

# Mandatory part

You must create at least 2 encrypted partitions using LVM. Below is an example of the expected partitioning:

LVM을 사용하여 `암호화된` 파티션을 두 개 이상 생성해야 합니다. 다음은 예상 파티셔닝의 예입니다.

> During the defense, you will be asked a few questions about the operating system you chose. For instance, you should know the differences between aptitude and apt, or what SELinux or AppArmor is. In short, understand what you use!

defense중에 선택한 운영 체제에 대한 몇 가지 질문이 표시됩니다. 예를 들어 `aptitude` 와 `apt`차이, `SELinux` 또는 `AppArmor` 가 무엇인지 알아야 합니다. 간단히 말해서, 여러분이 무엇을 사용하는지 이해하세요!

- 운영체제

운영체제(Operating System)는 사용자가 컴퓨터를 사용하기 위해 필요한 소프트웨어이다.

대표적인 운영체제는 Windows, Linux, Mac OSX, iOS 등이 있다.

**데비안**

데비안은 안정성을 매우 중시하는 리눅스 배포판입니다.

![https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5459fe1b-c6ce-4557-93f1-519f115c1a3a/Screen_Shot_2021-05-27_at_2.15.58_PM.png](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5459fe1b-c6ce-4557-93f1-519f115c1a3a/Screen_Shot_2021-05-27_at_2.15.58_PM.png)

The use of SSH will be tested during the defense by setting up a newaccount. You must therefore understand how it works.

새 계정을 설정하여 SSH 사용을 테스트합니다. 그러므로 당신은 그것이 어떻게 작동하는지 이해해야 한다.

A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.

SSH 서비스는 포트 4242에서만 실행됩니다. 보안상의 이유로 SSH를 루트로 사용하여 연결할 수 없어야 합니다.

```bash
ufw status verbose #포트 확인
ufw status numbered #포트 넘버 확인
ufw delete 포트넘버  #포트 지우기

ufw allow 4242 # 4242 포트 열기 v4, v6 둘다 열림

```

su root 하고 service sshd restart 하면 service: command not found 라는 오류가 났는데

❓su - root 로 옵션을 붙혀서 권한을 주면 오류가 나지 않는다 ? 왜지 ?

- su / - su 차이

su는 substitute user의 줄임말입니다.

현 사용자를 **로그아웃하지 않고, 다른 사용자의 권한을 획득할** 때 사용.

단일 사용자계정으로 우분투 데스크탑을 사용하고 있는 경우에도, 사용자의 권한을 루트로 변경할때 자주 사용합니다.

-su 는 login 과 같은 의미로 login 하여 권한을 가져온다.

You have to configure your operating system with the UFW firewall and thus leave only port 4242 open.

UFW 방화벽으로 운영 체제를 구성하여 포트 4242만 열어 두어야 합니다.

> Your firewall must be active when you launch your virtual machine. For CentOS, you have to use UFW instead of the default firewall. To install it, you will probably need DNF.

가상 시스템을 시작할 때 방화벽이 활성화되어 있어야 합니다. CentOS의 경우 기본 방화벽 대신 UFW를 사용해야 합니다. 이를 설치하려면 DNF가 필요할 수 있습니다.

```bash
$ apt install ufw
$ sudo ufw status verbose
최초 설치시, UFW 방화벽은 기본적으로 비활성화되어 있으며 출력은 아래와 비슷합니다.

Status: inactive

다음 명령을 사용하여 UFW 방화벽을 활성화하거나 활성화 할 수 있습니다. 방화벽을로드하고 부팅 할 때이 방화벽을 시작해야합니다.
$ ufw enable

$ sudo ufw disable
기본적으로 UFW 방화벽은 들어오는 모든 연결을 거부하고 서버에 대한 모든 아웃 바운드 연결 만 허용합니다. 즉, 포트를 특별히 열어 두지 않는 한 아무도 서버에 액세스 할 수 없으며 서버의 실행중인 모든 서비스 또는 응용 프로그램이 외부 네트워크에 액세스 할 수 있습니다.

$ sudo ufw disable
$ sudo ufw enable
지금까지 UFW 방화벽을 활성화했다면 들어오는 모든 연결을 차단하고 원격 위치에서 SSH를 통해 서버에 연결 한 경우 더 이상 연결할 수 없습니다.

다음 명령을 사용하여 서버에 대한 SSH 연결을 사용 가능하게 설정하십시오.

$ sudo ufw allow ssh
사용자 정의 SSH 포트 (예 : 포트 2222 )를 사용하는 경우 다음 명령을 사용하여 UFW 방화벽에서 해당 포트를 열어야합니다.

$ sudo ufw allow 2222


```

[https://ko.linux-console.net/?p=284](https://ko.linux-console.net/?p=284)

The hostname of your virtual machine must be your login ending with 42 (e.g., wil42).

You have to implement a strong password policy.

You have to install and configure sudo following strict rules.

In addition to the root user, a user with your login as username has to be present.

This user has to belong to the user42 and sudo groups.

- 가상 시스템의 호스트 이름은 42(예: wil42)로 끝나는 로그인이어야 합니다.
- 강력한 암호 정책을 구현해야 합니다.
- 엄격한 규칙에 따라 sudo를 설치하고 구성해야 합니다.
- 루트 사용자 외에도 사용자 이름으로 로그인한 사용자가 있어야 합니다.
- 이 사용자는 사용자 42 및 sudo 그룹에 속해야 합니다.

1. To set up a strong password policy, you have to comply with the following require- ments:

- Your password has to expire every 30 days.
- The minimum number of days allowed before the modification of a password will
be set to 2.
- The user has to receive a warning message 7 days before their password expires.
- Your password must be at least 10 characters long. It must contain an uppercase letter and a number. Also, it must not contain more than 3 consecutive identical characters.
- The password must not include the name of the user.
- The password must have at least 7 characters that are not part of the former password.
- Of course, your root password has to comply with this policy.

1. 강력한 암호 정책을 설정하려면 다음 요구 사항을 준수해야 합니다.

- 비밀번호는 30일마다 만료됩니다.
- 비밀번호 수정 전까지 허용되는 최소 일수 2로 설정되다
- 비밀번호 만료 7일 전에 경고 메시지를 수신해야 합니다.
- 비밀번호는 10자 이상이어야 합니다. 대문자와 숫자를 포함해야 합니다. 또한 연속해서 동일한 문자를 3자 이상 포함할 수 없습니다.
- 비밀번호에는 사용자 이름이 포함되지 않아야 합니다.
- 비밀번호는 이전 비밀번호에 속하지 않는 7자 이상이어야 합니다.
- 물론 루트 비밀번호는 이 정책을 준수해야 합니다.
- **PASS_MAX_DAYS** : 비밀번호를 사용할 수 있는 최대 일 수 30
- **PASS_MIN_DAYS** : 비밀번호를 바꾸는 사이의 최소 일 수 2
- **PASS_MIN_LEN** : 비밀번호 최소 길이 10
- **PASS_WARN_AGE** : 비밀번호 만료 전 경고 하는 날의 수 7
- **difok** : 이 인자는 새 패스워드가 이전 패스워드와 달라야 하는 문자 수 7개 → 12  (pam_cracklib.so)
- **maxrepeat** : 같은 문자가 N개 넘게 연이어 나오는 패스워드를 거부. 기본은 0으로, 이 검사를 하지 않는다는 뜻이다. 3
- **reject_username** : 사용자 이름이 그대로 또는 뒤집혀서 새 패스워드에 들어가 있는지 검사. 들어 있으면 새 패스워드를 거부한다.
- **enforce_for_root** : 패스워드를 바꾸려고 하는 사용자가 root인 경우에도 검사 실패 시 오류를 반환한다. 기본적으로 이 옵션이 꺼져 있는데, 실패한 검사에 대한 메시지는 찍지만 어쨌든 root는 패스워드를 바꿀 수 있다는 뜻이다. 참고로 root에게는 이전 패스워드를 묻지 않으므로 이전 패스워드와 새 패스워드를 비교하는 검사를 수행하지 않는다
- dcredit=N : 숫자에 주어지는 크레디트값. 기본 1
- udcredit=N : 영어대문자에 주어지는 크레디트값
- [https://aheesun.tistory.com/m/68?category=723396](https://aheesun.tistory.com/m/68?category=723396)

```bash
cd /etc
vi login.defs
```

```bash
sudo chage -M 30 -W 7 계정명

# 확인
chage -l 계정명

Last password change					: Feb 17, 2021
Password expires					: May 18, 2021
Password inactive					: never
Account expires						: never
Minimum number of days between password change		: 0
Maximum number of days between password change		: 90
Number of days of warning before password expires	: 7
```

### 강력한 암호 정책

Insecure passwords include those containing:

- Personally identifiable information (e.g., your dog's name, date of birth, area code, favorite video game)
- Simple character substitutions on words (e.g., `k1araj0hns0n`), as modern dictionary attacks can easily work with these
- Root "words" or common strings followed or preceded by added numbers, symbols, or characters (e.g., `DG091101%`)
- Common phrases or strings of dictionary words (e.g. `photocopyhauntbranchexpose`) including with character substitution (e.g. `Ph0toc0pyh4uN7br@nch3xp*se`)
- Any of the **[most common passwords](https://en.wikipedia.org/wiki/List_of_the_most_common_passwords)**
    - 개인 식별 가능 정보(예: 반려견 이름, 생년월일, 지역 번호, 좋아하는 비디오 게임)
    - modern dictionary attacks이 쉽게 작동할 수 있는 단어에 대한 간단한 문자 대체(예: k1araj0hns0n)
    - 루트 "단어" 또는 일반 문자열 뒤에 숫자, 기호 또는 문자가 추가되거나 앞에 나옵니다(예: "DG091101%").
    - 문자 대체(예: "Ph0toc0pyh4u@nch3xp*se")를 포함한 사전 단어의 일반적인 문구 또는 문자열(예: "photocopyhunt branch exposes")
    - **[가장 일반적인 암호](https://en.wikipedia.org/wiki/List_of_the_most_common_passwords)**

Note: You can use the root account to set a password for a user that bypasses the desired/configured policy. This is useful when setting temporary passwords.

참고: 루트 계정을 사용하여 원하는/구성된 정책을 바이패스하는 사용자의 암호를 설정할 수 있습니다. 이것은 임시 암호를 설정할 때 유용합니다.

```bash
cd /etc/pam.d
vi passswd
#**password requisite pam_cracklib.so try_first_pass retry=3 minlen=8 ucredit=-1 dcredit=-1 ocredit=-1 lcredit=-1**
```

**`password requisite pam_cracklib.so try_first_pass retry=3 minlen=8 ucredit=-1 dcredit=-1 ocredit=-1 lcredit=-1`**

retry=N : 패스워드 입력 실패 시 재시도횟수

difok=N : 기존 패스워드와 비교. 기본값10 (50%)

minlen=N : 크레디트를 더한 패스워드최소길이

dcredit=N : 숫자에 주어지는 크레디트값. 기본 1

udcredit=N : 영어대문자에 주어지는 크레디트값

lcredit=N : 영어 소문자에 주어지는 크레디트값

ocredit=N : 숫자, 영어대/소문자를 제외한 기타문자

(각 항목에서 -1 값을 주면 반드시 해당하는 문자를 포함시켜야 함. 즉 dcredit=-1 이라면 패스워드에 숫자가 반드시 포함되어야 함.)

1. To set up a strong configuration for your sudo group, you have to comply with the following requirements:

- Authentication using sudo has to be limited to 3 attempts in the event of an incor- rect password.
- A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.
- Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.
- The TTY mode has to be enabled for security reasons.
    ◦ For security reasons too, the paths that can be used by sudo must be restricted. Example:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin

1. sudo 그룹에 대한 강력한 구성을 설정하려면 다음 요구 사항을 준수해야 합니다.

- 비밀번호가 틀릴 경우 sudo를 이용한 인증은 3회 이내로 제한되어야 합니다.
- sudo 사용 시 비밀번호가 잘못되어 오류가 발생할 경우 사용자가 선택한 사용자 정의 메시지를 표시해야 합니다.

```bash
# visudo
Defaults badpass_message="Password is wrong, please try agin!"
```

∙ 수도를 이용한 동작은 입력과 출력 모두 보관해야 한다. 로그 파일은 /var/log/sudo/ 폴더에 저장해야 합니다.

- 보안상의 이유로 TTY 모드를 활성화해야 합니다.
- 보안상의 이유로 sudo에서 이용할 수 있는 경로도 제한한다. 예:/usr/local/sbin:/usr/local/bin:/usr/bin:/bin:/snap/bin

Finally, you have to create a simple script called monitoring.sh. It must be devel-oped in bash.

At server startup, the script will display some information (listed below) on all ter- minals every 10 minutes (take a look at wall). The banner is optional. No error must be visible.

Your script must always be able to display the following information:

- The architecture of your operating system and its kernel version.The number of physical processors.The number of virtual processors.The available RAM on your server and its utilization rate as a percentage.The available memory on your server and its utilization rate as a percentage. • The utilization rate of your processors as a percentage.
- The date and time of the last reboot.Whether LVM is active or not.The number of active connections.The number of users using the server.The IPv4 address of your server and its MAC (Media Access Control) address. • The number of commands executed with the sudo program.

마지막으로, monitoring.sh이라는 간단한 스크립트를 작성해야 합니다. 그것은 bash로 개발되어야 한다.

서버를 시작할 때 스크립트는 10분마다 모든 터미널에 일부 정보(아래 목록)를 표시합니다(벽면 참조). 배너는 선택 사항입니다. 오류를 볼 수 없어야 합니다.

스크립트는 항상 다음 정보를 표시할 수 있어야 합니다.

- 운영 체제의 아키텍처와 커널 버전.물리적 프로세서 수입니다.가상 프로세서 수입니다.서버에서 사용 가능한 RAM과 사용률(백분율)입니다.서버에서 사용 가능한 메모리와 사용률(%)을 백분율로 표시합니다. • 프로세서의 사용률(%)을 백분율로 표시합니다.
- 마지막 재부팅 날짜 및 시간입니다.LVM의 활성 여부.활성 연결 수입니다.서버를 사용하는 사용자 수입니다.서버의 IPv4 주소와 해당 MAC(Media Access Control) 주소. • sudo 프로그램으로 실행된 명령 수입니다.

> Broadcast message from root@wil (tty1) (Sun Apr 25 15:45:00 2021):
#Architecture: Linux wil 4.19.0-16-amd64 #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux
#CPU physical : 1
#vCPU : 1
#Memory Usage: 74/987MB (7.50%) #Disk Usage: 1009/2Gb (39%)
#CPU load: 6.7%
#Last boot: 2021-04-25 14:45
#LVM use: yes
#Connexions TCP : 1 ESTABLISHED
#User log: 1
#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
#Sudo : 42 cmd

Broadcast message from root@wil (tty1) (Sun Apr 25 15:45:00 2021):
#Architecture: Linux wil 4.19.0-16-amd64(name -r 리눅스 커널 버전) #1 SMP Debian 4.19.181-1 (2021-03-19) x86_64 GNU/Linux
#CPU physical : 1
#vCPU : 1
#Memory Usage: 74/987MB (7.50%) #Disk Usage: 1009/2Gb (39%)
#CPU load: 6.7%
#Last boot: 2021-04-25 14:45
#LVM use: yes
#Connexions TCP : 1 ESTABLISHED
#User log: 1
#Network: IP 10.0.2.15 (08:00:27:51:9b:a5)
#Sudo : 42 cmd

[https://coconuts.tistory.com/208](https://coconuts.tistory.com/208)

초기설정 꿀팁

```bash
**다이아몬드로 깨지는거 방지**
$ vi .bashrc
#추가
export LANG=C

```

```powershell
**vim 깔아서 쓰기**
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

## 1.포트

```bash
$ apt install ufw
$ sudo ufw status verbose
최초 설치시, UFW 방화벽은 기본적으로 비활성화되어 있으며 출력은 아래와 비슷합니다.

Status: inactive

다음 명령을 사용하여 UFW 방화벽을 활성화하거나 활성화 할 수 있습니다. 방화벽을로드하고 부팅 할 때이 방화벽을 시작해야합니다.
$ ufw enable

$ sudo ufw disable
지금까지 UFW 방화벽을 활성화했다면 들어오는 모든 연결을 차단하고 원격 위치에서 SSH를 통해 서버에 연결 한 경우 더 이상 연결할 수 없습니다.

$ sudo ufw enable
Firewall is active and enabled on system startup

다음 명령을 사용하여 서버에 대한 SSH 연결을 사용 가능하게 설정하십시오.

$ sufo ufw allow ssh
$ sudo ufw allow <port-number>
사용자 정의 SSH 포트 (예 : 포트 2222 )를 사용하는 경우 다음 명령을 사용하여 UFW 방화벽에서 해당 포트를 열어야합니다.

```

## 2.ssh

:ssh ( secure shell) 시큐어 쉘의 약자 보안 기능이 전제 되어 있는 프로토콜.

```bash
#openssh가 있는지 확인
$dpkg -l | grep oepnssh
#il openssh-client ~~ secure sshell(ssh)client, for secure access ~
#il openssh-server ~~ secure sshell(ssh)client, for secure access ~
#il openssh-sftp-server ~~ secure sshell(ssh)client, for secure access ~

#ssh 서버 시작
$ service ssh start
$ service ssh status
#현재 실행중인 서비스 목록중 ssh가있는지 확인
$ service --status-all | grep +

$ apt-get install net-tools
#ssh 서비스가 몇번 포트를 점유하고 있는지 확인
$netstat -antp
```

## .ssh 설정

```bash
$  vi /etc/ssh/sshd_config
#PermitRootLogin prohibit-password
PermitRootLogin no
```

1. 강력한 암호 정책을 설정하려면 다음 요구 사항을 준수해야 합니다.

- 비밀번호는 30일마다 만료됩니다.
- 비밀번호 수정 전까지 허용되는 최소 일수 2로 설정되다
- 비밀번호 만료 7일 전에 경고 메시지를 수신해야 합니다.
- 비밀번호는 10자 이상이어야 합니다. 대문자와 숫자를 포함해야 합니다. 또한 연속해서 동일한 문자를 3자 이상 포함할 수 없습니다.
- 비밀번호에는 사용자 이름이 포함되지 않아야 합니다.
- 비밀번호는 이전 비밀번호에 속하지 않는 7자 이상이어야 합니다.
- 물론 루트 비밀번호는 이 정책을 준수해야 합니다.

## 3. 패스워드 expired 정책

최대 90일 사용하고, 7일전에 알림을 표시하겠다는 내용이다.추가로, 최소 사용일도 제한할수 있다.

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

```
sudo chage -M 30 -W 7  -m 2 계정명

# 확인
chage -l 계정명

Last password change					: Feb 17, 2021
Password expires					: May 18, 2021
Password inactive					: never
Account expires						: never
Minimum number of days between password change		: 0
Maximum number of days between password change		: 90
Number of days of warning before password expires	: 7
```

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

# here are the per-package modules (the "Primary" block)
password        requisite                       pam_pwquality.so retry=3 minlen=12 difok=7 dcredit=-1 ucredit=-1 maxrepeat=3 enforce_for_root reject_username
```

## 5.그룹

```bash
#그룹 조회
cat /etc/group

#그룹 생성
groupadd <group-name>
tail -n 5 /etc/group
```

```bash
sudo group 에 계정 추가

#자신의 계정의 sudo 가 안될때는 sudo group 에 user account 를 추가해주면 된다. 그리고 재로그인을 하자.

adduser <user-name>
adduser <user-name> sudo

reboot

#그룹 확인
$getent group <group-name>
<group-name>:x:27:<username>

#group 에서 user 삭제

gpasswd -d user_account group

sudo 가 가능한 그룹 확인

vi /etc/sudoers

#아래처럼 가능한 그룹을 확인할 수 있다.
#...

#%wheel  ALL=(ALL)   ALL

#...
```

## 6.sudo

```bash
#root 로 로그인 후 진행
$su - root
visudo
Defaults secure_path=":/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"
Defaults badpass_message="<custom-error-message>"
Defaults logfile="/var/log/sudo/<file-name>"
Defaults log_input, log_ouput
Defaults passwd_tries=3
```

