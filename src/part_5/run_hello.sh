#!bin/bash/
# gcc hello.c -lfcgi -o hello
service nginx start
spawn-fcgi -p 8080 ./hello
tail -f /dev/null
/bin/bash