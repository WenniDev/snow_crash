# Level 09
We have the usually files level09 and token.
```sh
$ ls -l
total 12
-rwsr-sr-x 1 flag09 level09 7640 Mar  5  2016 level09
----r--r-- 1 flag09 level09   26 Mar  5  2016 token
```

This time we can read the content of `token` but... it does not help..
```sh
$ cat token
f4kmm6p|=�p�n��DB�Du{��
```

By decompiling the level09 executable we can understand that the returned value is encrypted with a progressive shift. The first letter have a shift of 0, the second of +1, the third of +2...

```sh
$ scp -P 4243 level09@localhost:/home/user/level09/token .
$ chmod +r ./token
```
We can get the token on our pc and execute our script who's doing the inverse process. The first letter have a shift of 0, the second of -1, the third of -2...

```sh
$ c++ level09/ressources/level09.cpp -o level09decode
$ ./level09decode ./token
f3iji1ju5yuevaus41q1afiuq
```

Now we can log as flag09 with `f3iji1ju5yuevaus41q1afiuq`.