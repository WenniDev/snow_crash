# Level 01

Same situation as level00, let's do the same commands.

```sh
find / -path /dev -prune -o -exec grep -Hn "flag01" {} \; 2>/dev/null
/etc/passwd:41:flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
```

This time, we found a hashed password in /etc/passwd.
Let's bruteforce it with [John the Ripper](https://www.openwall.com/john/)!

```sh
wget https://www.openwall.com/john/k/john-1.9.0-jumbo-1.tar.xz
tar -xJf john-1.9.0-jumbo-1.tar.xz
./configure && make -s clean && make -sj4
echo 42hDRfypTqqnw > /tmp/pass

./john /tmp/pass
Proceeding with wordlist:./password.lst, rules:Wordlist
abcdefg          (?)

```

Now we can log as flag01 with `abcdefg`.
