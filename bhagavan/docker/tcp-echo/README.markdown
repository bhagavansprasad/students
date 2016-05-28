Start server
============
```shell
make run
```

Test server
===========
In another shell
```shell
make test
```

Docker
======
https://registry.hub.docker.com/u/jimho/tcp-echo
```shell
docker pull jimho/tcp-echo
```

or build it yourself

```shell
docker build -t tcp-echo .
```

DEIS
====
```shell
deis create
git push deis master
```
