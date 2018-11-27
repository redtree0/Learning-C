# Linux cgroups a.k.a. Control Groups

컨테이너(container)가 호스트의 자원을 무제한 점유하고 있다면, 호스트 OS는 당연히 unplanned down이 될 것이다. 

## Cgroups

Cgroups은 프로세스의 자원 사용량을 제한할 수 있는 리눅스 커널의 특징이다.

Cgroups은 버전은 [v1](https://www.kernel.org/doc/Documentation/cgroup-v1/), [v2](https://www.kernel.org/doc/Documentation/cgroup-v2.txt)로 두가지이다. v1은 thread 레벨에서 작동하지만 v2은 process 레벨에서만 작동한다.

## Cgroup subsystems

* blkio - I/O 제한
* cpu - CPU 스케줄링
* cpuset - 멀티코어 시스템에 CPU 할당
* devices - 장치 접근 관리
* memory - 메모리 제한

## Managing cgroups

cgroup은 system call을 하지 않는다. 그 대신, ```/sys/fs/cgroup``` 경로 특정 파일(kmen - kernel memory, memsw - memory + swap 등)에 정의된 값을 읽고 관리한다.

cgroup은 ```/sys/fs/cgroup/memory```에 하위 디렉토리를 만들기만 하면 나머지는 커널에서 관련 파일을 자동으로 채워준다. (신기)

```
vagrant@linuxcontainer:~$ sudo mkdir /sys/fs/cgroup/memory/test
vagrant@linuxcontainer:~$ sudo ls -l /sys/fs/cgroup/memory/test
total 0
-rw-r--r-- 1 root root 0 Nov 27 08:47 cgroup.clone_children
--w--w--w- 1 root root 0 Nov 27 08:47 cgroup.event_control
-rw-r--r-- 1 root root 0 Nov 27 08:47 cgroup.procs
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.failcnt
--w------- 1 root root 0 Nov 27 08:47 memory.force_empty
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.kmem.failcnt
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.kmem.limit_in_bytes
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.kmem.max_usage_in_bytes
-r--r--r-- 1 root root 0 Nov 27 08:47 memory.kmem.slabinfo
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.kmem.tcp.failcnt
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.kmem.tcp.limit_in_bytes
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.kmem.tcp.max_usage_in_bytes
-r--r--r-- 1 root root 0 Nov 27 08:47 memory.kmem.tcp.usage_in_bytes
-r--r--r-- 1 root root 0 Nov 27 08:47 memory.kmem.usage_in_bytes
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.limit_in_bytes
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.max_usage_in_bytes
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.move_charge_at_immigrate
-r--r--r-- 1 root root 0 Nov 27 08:47 memory.numa_stat
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.oom_control
---------- 1 root root 0 Nov 27 08:47 memory.pressure_level
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.soft_limit_in_bytes
-r--r--r-- 1 root root 0 Nov 27 08:47 memory.stat
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.swappiness
-r--r--r-- 1 root root 0 Nov 27 08:47 memory.usage_in_bytes
-rw-r--r-- 1 root root 0 Nov 27 08:47 memory.use_hierarchy
-rw-r--r-- 1 root root 0 Nov 27 08:47 notify_on_release
-rw-r--r-- 1 root root 0 Nov 27 08:47 tasks
```