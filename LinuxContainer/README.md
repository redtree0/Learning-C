# Write a Linux Container Runtime in C

C언어 기반 리눅스 컨테이너를 개발 및 테스트 할 수 있는 VM을 생성해본다.

## Enviroment
호스트 컴퓨터는 macOS로 위에 
VM OS는 Ubuntu 18.04로 구성할 것이다.
이때 호스트 컴퓨터에 python 2.7x 버전, virtualbox, vagrant가 설치 되어있어야 한다.
Vagrant로 VM 관리, Ansible로 프로비저닝(Docker, make 패키지 설치)을 했다.

|  host  |    name     |
|------- |----------   |
| os     |   MacOS     |
| python | python2.7x  |
| VM     |  virtualBox |
| Tool   |  Vagrant    |


|   VM   |    name             |
|------- | ------------------  |
| os     |     Ubuntu18.04     |
| docker |   docker-ce=18.09.0 |
|  make  |         4.1         |
|  gcc   |   (default)7.3.0    |



## Setup

해당 프로젝트를 git clone하고 다음 순서대로 진행한다.

1. python 가상 실행 환경 설정
2. python 패키지 설치 
3. ansible role 설치
4. VM 생성
5. 프로비저닝
6. VM 접속 후 리눅스 컨테이너 테스트

### 1. python 가상 실행 환경 설정
virtualenv로 python 가상 실행 환경을 만들어 준다.
```
$ git clone https://github.com/redtree0/Learning-C.git
$ cd LinuxContainer
$ pip install virtualenv
$ virtualenv -p python2.7 env
$ source env/bin/activate
```

### 2. python 패키지 설치 
requirements.txt에 정의된 python 패키지 설치한다.
```
(env) $ pip install -r requirements.txt
```

### 3. ansible role 설치
requirements.yml에 정의된 ansible role을 설치한다.
```
(env) $ ansible-galaxy install -r requirements.yml -p roles/
```

### 4. VM 생성
vagrant up 명령으로 Vagrantfile에 정의된 VM을 생성 및 실행한다.
```
(env) $ vagrant up
```

### 5. 프로비저닝
Makefile에 정의된 ansible.playbook을 실행한다.
```
(env) $ make setup
// ansible-playbook playbook.setup.yml -i inventory.ini
```

### 6. VM 접속 및 리눅스 컨테이너 실행
```
(env) $ vagrant ssh linuxcontainer
vagrant@linuxcontainer:~$ git clone https://github.com/redtree0/diyC.git
vagrant@linuxcontainer:~$ cd diyC
vagrant@linuxcontainer:~$ make setup
vagrant@linuxcontainer:~$ make
```