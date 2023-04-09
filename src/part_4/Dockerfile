FROM nginx
USER root

COPY ./hello.c /my_server/
COPY ./nginx.conf /etc/nginx/nginx.conf
COPY ./run_hello.sh /my_server/

WORKDIR /my_server/

RUN apt-get install \
    && apt update \
    && apt install gcc -y \
    && apt install spawn-fcgi -y \
    && apt install libfcgi-dev -y \
    && chmod +x run_hello.sh

 CMD ["/my_server/run_hello.sh"]

    # && gcc hello.c -lfcgi -o hello

ENTRYPOINT ["sh", "./run_hello.sh"]