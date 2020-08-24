### in one terminal shell
~~~
socat -d -d pty,raw,echo=0 pty,raw,echo=0
~~~

### in one other terminal shell
~~~
sudo ln -sf /dev/pts/3 /dev/ttyV3
sudo ln -sf /dev/pts/4 /dev/ttyV4
minicom -b 9600 -D /dev/ttyV4
~~~
