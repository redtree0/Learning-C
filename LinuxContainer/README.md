
Prerequirements
HOST : MacOS
python : python2.7

```
$ git clone https://github.com/redtree0/Learning-C.git
$ cd LinuxContainer
$ pip install virtualenv
$ virtualenv -p python2.7 env
$ source env/bin/activate
```

```
(env) $ pip install -r requirements.txt
(env) $ ansible-galaxy install -r requirements.yml -p roles/
```

```
(env) $ make setup
```

```
(env) $ vagrant ssh linuxcontainer
vagrant@linuxcontainer:~$ git clone https://github.com/redtree0/diyC.git
vagrant@linuxcontainer:~$ cd diyC
vagrant@linuxcontainer:~$ make setup
vagrant@linuxcontainer:~$ make
```